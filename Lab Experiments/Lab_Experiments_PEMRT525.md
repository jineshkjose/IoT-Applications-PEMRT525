# IoT & Applications — PEMRT525
## Lab Experiments | Batch MR 2K24 | S5 | JECC
### Department of Mechatronics Engineering | Jyothi Engineering College (Autonomous)

---

## Experiment 1 — ESP32 LED Blink

**Aim:** To write an Arduino program to blink an LED connected to ESP32 GPIO2 at 1 Hz frequency.

**Components Required:**

| Component | Quantity |
|-----------|----------|
| ESP32 Development Board | 1 |
| LED (Red / Green) | 1 |
| Resistor 220Ω | 1 |
| Breadboard | 1 |
| Jumper Wires | 3 |
| USB Cable | 1 |

**Circuit Connections:**

| ESP32 Pin | Component |
|-----------|-----------|
| GPIO2 | LED Anode (+) via 220Ω resistor |
| GND | LED Cathode (−) |

```
ESP32 GPIO2 ──── 220Ω ──── LED(+) ──── LED(−) ──── GND
```

**Code:**
```cpp
#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED ON
  delay(500);                   // Wait 500 ms
  digitalWrite(LED_PIN, LOW);   // LED OFF
  delay(500);                   // Wait 500 ms
}
```

**Procedure:**
1. Connect the LED to GPIO2 of ESP32 through a 220Ω resistor as per the circuit diagram.
2. Connect the LED cathode to GND of the ESP32.
3. Open Arduino IDE. Select Board: **ESP32 Dev Module** and the correct COM port.
4. Enter the code and click **Upload**.
5. Once uploaded, observe the LED on the breadboard.

**Result:** The LED blinks continuously at 1 Hz (500 ms ON, 500 ms OFF), confirming successful GPIO digital output control on the ESP32.

---

## Experiment 2 — ESP32 Switch Controlled LED

**Aim:** To interface a push-button switch with ESP32 GPIO and control an LED based on switch input.

**Components Required:**

| Component | Quantity |
|-----------|----------|
| ESP32 Development Board | 1 |
| LED (Red / Green) | 1 |
| Resistor 220Ω | 1 |
| Push-Button Switch | 1 |
| Breadboard | 1 |
| Jumper Wires | 5 |
| USB Cable | 1 |

**Circuit Connections:**

| ESP32 Pin | Component |
|-----------|-----------|
| GPIO2 | LED Anode (+) via 220Ω resistor |
| GND | LED Cathode (−) |
| GPIO4 | Push-button terminal 1 |
| GND | Push-button terminal 2 |

```
ESP32 GPIO4 ──── Button ──── GND      (Input, Internal Pull-Up)
ESP32 GPIO2 ──── 220Ω ──── LED(+) ──── LED(−) ──── GND
```

**Code:**
```cpp
#define LED_PIN    2
#define BUTTON_PIN 4

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Internal pull-up enabled
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {       // Button pressed (pulled to GND)
    digitalWrite(LED_PIN, HIGH);  // LED ON
  } else {
    digitalWrite(LED_PIN, LOW);   // LED OFF
  }
}
```

**Procedure:**
1. Connect the LED to GPIO2 through a 220Ω resistor. Connect LED cathode to GND.
2. Connect one terminal of the push-button to GPIO4 and the other terminal to GND.
3. Open Arduino IDE, select the correct board and port.
4. Upload the code.
5. Press and hold the push-button and observe the LED. Release and observe.

**Result:** The LED turns ON when the push-button is pressed and turns OFF when released, confirming successful GPIO digital input reading and output control on the ESP32.

---

## Experiment 3 — ESP32 LCD Display

**Aim:** To interface a 16×2 LCD display (I2C) with ESP32 and display text messages on both lines.

**Components Required:**

| Component | Quantity |
|-----------|----------|
| ESP32 Development Board | 1 |
| 16×2 LCD with I2C Module | 1 |
| Breadboard | 1 |
| Jumper Wires | 4 |
| USB Cable | 1 |

**Circuit Connections:**

| ESP32 Pin | I2C LCD Pin |
|-----------|-------------|
| 3.3V / 5V | VCC |
| GND | GND |
| GPIO21 (SDA) | SDA |
| GPIO22 (SCL) | SCL |

```
ESP32          I2C LCD Module
3.3V  ─────── VCC
GND   ─────── GND
GPIO21 ─────── SDA
GPIO22 ─────── SCL
```

**Library Required:** `LiquidCrystal_I2C` (Install via Arduino IDE → Library Manager)

**Code:**
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set I2C address (0x27 or 0x3F — check with I2C scanner)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int counter = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  JECC IoT Lab  ");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(counter);
  lcd.print("   ");   // Clear trailing digits
  counter++;
  delay(1000);
}
```

**Procedure:**
1. Connect the I2C LCD module to ESP32 as per the circuit (SDA → GPIO21, SCL → GPIO22).
2. Open Arduino IDE, install the `LiquidCrystal_I2C` library.
3. Upload the code and observe the LCD display.
4. Line 1 should show **"JECC IoT Lab"** and Line 2 should show a live count incrementing every second.
5. If the display does not show text, adjust the contrast potentiometer on the I2C module.

**Result:** The 16×2 LCD displays "JECC IoT Lab" on Line 1 and a live incrementing counter on Line 2, confirming successful I2C communication between ESP32 and the LCD module.

---

## Experiment 4 — Raspberry Pi LED Blink

**Aim:** To write a Python program to blink an LED connected to Raspberry Pi GPIO17 (BCM) at 1 Hz frequency.

**Components Required:**

| Component | Quantity |
|-----------|----------|
| Raspberry Pi 3 / 4 | 1 |
| LED (Red / Green) | 1 |
| Resistor 220Ω | 1 |
| Breadboard | 1 |
| Jumper Wires (Female–Male) | 3 |

**Circuit Connections:**

| RPi Pin | Component |
|---------|-----------|
| GPIO17 (BCM) — Pin 11 | LED Anode (+) via 220Ω resistor |
| GND — Pin 6 | LED Cathode (−) |

```
RPi GPIO17 (Pin 11) ──── 220Ω ──── LED(+) ──── LED(−) ──── GND (Pin 6)
```

**Code (Python):**
```python
import RPi.GPIO as GPIO
import time

LED_PIN = 17  # BCM numbering

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)

try:
    while True:
        GPIO.output(LED_PIN, GPIO.HIGH)  # LED ON
        time.sleep(0.5)
        GPIO.output(LED_PIN, GPIO.LOW)   # LED OFF
        time.sleep(0.5)

except KeyboardInterrupt:
    print("Program stopped")

finally:
    GPIO.cleanup()
```

**Procedure:**
1. Connect the LED to GPIO17 (Physical Pin 11) of Raspberry Pi through a 220Ω resistor.
2. Connect the LED cathode to GND (Physical Pin 6).
3. Open the Raspberry Pi terminal and create a file: `nano led_blink.py`
4. Type the code and save (Ctrl+X → Y → Enter).
5. Run the program: `python3 led_blink.py`
6. Observe the LED blinking. Press **Ctrl+C** to stop.

**Result:** The LED blinks continuously at 1 Hz (500 ms ON, 500 ms OFF), confirming successful GPIO output control using Python on the Raspberry Pi.

---

## Experiment 5 — Raspberry Pi Switch Controlled LED

**Aim:** To interface a push-button switch with Raspberry Pi GPIO and control an LED based on switch input using Python.

**Components Required:**

| Component | Quantity |
|-----------|----------|
| Raspberry Pi 3 / 4 | 1 |
| LED (Red / Green) | 1 |
| Resistor 220Ω | 1 |
| Push-Button Switch | 1 |
| Breadboard | 1 |
| Jumper Wires (Female–Male) | 6 |

**Circuit Connections:**

| RPi Pin | Component |
|---------|-----------|
| GPIO17 (BCM) — Pin 11 | LED Anode (+) via 220Ω resistor |
| GND — Pin 6 | LED Cathode (−) |
| GPIO18 (BCM) — Pin 12 | Push-button terminal 1 |
| GND — Pin 14 | Push-button terminal 2 |

```
RPi GPIO17 ──── 220Ω ──── LED(+) ──── LED(−) ──── GND
RPi GPIO18 ──── Button ──── GND      (Input, Pull-Up enabled in software)
```

**Code (Python):**
```python
import RPi.GPIO as GPIO
import time

LED_PIN    = 17  # BCM
BUTTON_PIN = 18  # BCM

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.setup(BUTTON_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)  # Pull-up resistor

try:
    while True:
        button_state = GPIO.input(BUTTON_PIN)

        if button_state == GPIO.LOW:        # Button pressed
            GPIO.output(LED_PIN, GPIO.HIGH) # LED ON
        else:
            GPIO.output(LED_PIN, GPIO.LOW)  # LED OFF

        time.sleep(0.05)  # Small delay to reduce CPU usage

except KeyboardInterrupt:
    print("Program stopped")

finally:
    GPIO.cleanup()
```

**Procedure:**
1. Connect the LED to GPIO17 through a 220Ω resistor, cathode to GND.
2. Connect one terminal of the push-button to GPIO18 and the other to GND.
3. Open the Raspberry Pi terminal: `nano switch_led.py`
4. Enter the code, save and run: `python3 switch_led.py`
5. Press and hold the push-button — observe the LED turning ON.
6. Release the button — observe the LED turning OFF.
7. Press **Ctrl+C** to stop.

**Result:** The LED turns ON when the push-button is pressed and turns OFF when released, confirming successful GPIO digital input reading using internal pull-up resistor and output control on Raspberry Pi using Python.

---

## Summary

| Exp | Title | Platform | GPIO Mode |
|-----|-------|----------|-----------|
| 1 | ESP32 LED Blink | ESP32 | Digital Output |
| 2 | ESP32 Switch Controlled LED | ESP32 | Digital Input + Output |
| 3 | ESP32 LCD Display | ESP32 | I2C Communication |
| 4 | Raspberry Pi LED Blink | Raspberry Pi | Digital Output (BCM) |
| 5 | Raspberry Pi Switch Controlled LED | Raspberry Pi | Digital Input + Output (BCM) |

---

*PEMRT525 — IoT & Applications | S5 MR 2K24 | Department of Mechatronics Engineering | Jyothi Engineering College (Autonomous), Thrissur*
