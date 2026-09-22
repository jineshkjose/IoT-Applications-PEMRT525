/*
 * ============================================================
 *  WBT Room Alert System — Indoor Unit (ESP32)
 *  PEMRT525 IoT & Applications | JECC MR 2K24 S5
 * ============================================================
 *
 *  WIRING — 4-wire telephone cable to outdoor SHT45 sensor
 *  ──────────────────────────────────────────────────────────
 *    Wire 1 RED   → 3.3V   → SHT45 VCC
 *    Wire 2 BLACK → GND    → SHT45 GND
 *    Wire 3 BLUE  → GPIO21 → SHT45 SDA
 *    Wire 4 GREEN → GPIO22 → SHT45 SCL
 *
 *  OLED (SSD1306 128x64, I2C addr 0x3C)
 *    SDA→GPIO21  SCL→GPIO22  VCC→3.3V  GND→GND
 *    (SHT45 addr=0x44, OLED addr=0x3C — no conflict)
 *
 *  RGB LED (common cathode, 220 ohm each)
 *    R→GPIO25  G→GPIO26  B→GPIO27
 *
 *  BUZZER (active piezo 3.3V or via BC547 for 5V)
 *    +→GPIO32
 *
 *  BATTERY MONITOR
 *    18650 pack → 100k/100k divider → GPIO34
 *
 *  LIBRARIES (Arduino Library Manager)
 *    Adafruit SHT4x Library
 *    Adafruit SSD1306
 *    Adafruit GFX Library
 * ============================================================
 */

#include <Wire.h>
#include <Adafruit_SHT4x.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <math.h>

// Pin definitions
#define PIN_LED_R    25
#define PIN_LED_G    26
#define PIN_LED_B    27
#define PIN_BUZZER   32
#define PIN_BATT_ADC 34

// OLED
#define OLED_WIDTH  128
#define OLED_HEIGHT  64
#define OLED_ADDR  0x3C

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);
Adafruit_SHT4x   sht4;

// WBT alert thresholds (degrees C)
#define WBT_SAFE    24.0
#define WBT_CAUTION 28.0
#define WBT_DANGER  32.0

// Timing
unsigned long lastRead  = 0;
unsigned long lastBuzz  = 0;
unsigned long lastBlink = 0;
const unsigned long READ_INTERVAL = 5000;

// Readings
float temperature = 0.0;
float humidity    = 0.0;
float wbt         = 0.0;
int   alertZone   = 0;   // 0=safe 1=caution 2=danger 3=alarm
bool  ledState    = false;

// ── Stull (2011) WBT formula ──────────────────────────────────
// T in Celsius, RH in percent (0–100)
float calcWBT(float T, float RH) {
  return T * atan(0.151977 * sqrt(RH + 8.313659))
       + atan(T + RH)
       - atan(RH - 1.676331)
       + 0.00391838 * pow(RH, 1.5) * atan(0.023101 * RH)
       - 4.686035;
}

// ── RGB LED ───────────────────────────────────────────────────
void setLED(bool r, bool g, bool b) {
  digitalWrite(PIN_LED_R, r);
  digitalWrite(PIN_LED_G, g);
  digitalWrite(PIN_LED_B, b);
}

void updateLED(int zone, bool blink) {
  switch (zone) {
    case 0: setLED(0, 1, 0);     break;   // green
    case 1: setLED(1, 1, 0);     break;   // yellow
    case 2: setLED(1, 0, 0);     break;   // red
    case 3: setLED(blink, 0, 0); break;   // red blinking
  }
}

// ── Battery ───────────────────────────────────────────────────
float readBattVoltage() {
  int raw = analogRead(PIN_BATT_ADC);
  return (raw / 4095.0) * 3.3 * 2.0;  // x2 for divider
}

int battPercent(float v) {
  return constrain((int)((v - 3.0) / 1.2 * 100.0), 0, 100);
}

// ── OLED normal screen ────────────────────────────────────────
void updateDisplay() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Header
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("WBT MONITOR");
  int bp = battPercent(readBattVoltage());
  display.setCursor(90, 0);
  display.print(bp); display.print("%");
  display.drawLine(0, 9, 127, 9, SSD1306_WHITE);

  // Temperature
  display.setTextSize(2);
  display.setCursor(0, 13);
  display.print("T:"); display.print(temperature, 1); display.print("C");

  // Humidity
  display.setCursor(0, 31);
  display.print("H:"); display.print(humidity, 0); display.print("%");

  // WBT line
  display.drawLine(0, 48, 127, 48, SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 51);
  display.print("WBT:"); display.print(wbt, 1); display.print("C");

  // Status label
  display.setCursor(72, 51);
  const char* labels[] = {"SAFE", "CAUTION", "DANGER", "ALARM!"};
  display.print(labels[alertZone]);

  // Risk bar
  display.setCursor(0, 58);
  display.print("Risk:");
  int barW = constrain((int)((wbt - 20.0) / 18.0 * 80), 0, 80);
  display.fillRect(30, 58, barW, 5, SSD1306_WHITE);
  display.drawRect(30, 58, 80, 5, SSD1306_WHITE);

  display.display();
}

// ── OLED alarm screen ─────────────────────────────────────────
void showAlarmScreen() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(5, 5);
  display.print("!! ALARM !!");
  display.setTextSize(1);
  display.setCursor(0, 30);
  display.print("WBT: "); display.print(wbt, 1); display.print("C  DANGER!");
  display.setCursor(0, 45);
  display.print("Move to AC room NOW");
  display.display();
}

// ═══════════════════════════════════════════════════════════════
void setup() {
  Serial.begin(115200);

  pinMode(PIN_LED_R,  OUTPUT);
  pinMode(PIN_LED_G,  OUTPUT);
  pinMode(PIN_LED_B,  OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_BUZZER, LOW);

  // I2C at 50 kHz for reliable operation over long cable
  Wire.begin(21, 22);
  Wire.setClock(50000);

  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED not found");
    while (true) delay(1000);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(15, 20); display.print("WBT Monitor");
  display.setCursor(15, 36); display.print("Initialising...");
  display.display();
  delay(1500);

  // SHT45
  if (!sht4.begin()) {
    display.clearDisplay();
    display.setCursor(0, 20); display.print("SHT45 not found!");
    display.setCursor(0, 35); display.print("Check 4-wire cable");
    display.display();
    Serial.println("ERROR: SHT45 not detected — check wiring");
    while (true) delay(1000);
  }
  sht4.setPrecision(SHT4X_HIGH_PRECISION);
  sht4.setHeater(SHT4X_NO_HEATER);

  Serial.println("WBT Monitor ready. Reading every 5 s.");
}

// ═══════════════════════════════════════════════════════════════
void loop() {
  unsigned long now = millis();

  // Sensor read
  if (now - lastRead >= READ_INTERVAL) {
    lastRead = now;
    sensors_event_t hEvt, tEvt;
    sht4.getEvent(&hEvt, &tEvt);
    temperature = tEvt.temperature;
    humidity    = hEvt.relative_humidity;
    wbt         = calcWBT(temperature, humidity);

    if      (wbt < WBT_SAFE)    alertZone = 0;
    else if (wbt < WBT_CAUTION) alertZone = 1;
    else if (wbt < WBT_DANGER)  alertZone = 2;
    else                         alertZone = 3;

    Serial.printf("T=%.2fC  RH=%.1f%%  WBT=%.2fC  Zone=%d\n",
                  temperature, humidity, wbt, alertZone);
  }

  // LED blink (alarm zone)
  if (alertZone == 3 && (now - lastBlink >= 500)) {
    lastBlink = now;
    ledState = !ledState;
  }
  updateLED(alertZone, ledState);

  // Display
  if (alertZone == 3 && (now / 2000) % 2 == 0)
    showAlarmScreen();
  else
    updateDisplay();

  // Buzzer intervals
  unsigned long buzzInterval = 0;
  if      (alertZone == 1) buzzInterval = 60000;  // 1/min
  else if (alertZone == 2) buzzInterval = 10000;  // every 10 s
  else if (alertZone == 3) buzzInterval = 1500;   // continuous

  if (alertZone > 0 && (now - lastBuzz >= buzzInterval)) {
    lastBuzz = now;
    int dur = (alertZone == 3) ? 700 : 200;
    digitalWrite(PIN_BUZZER, HIGH);
    delay(dur);
    digitalWrite(PIN_BUZZER, LOW);
  }

  delay(100);
}
