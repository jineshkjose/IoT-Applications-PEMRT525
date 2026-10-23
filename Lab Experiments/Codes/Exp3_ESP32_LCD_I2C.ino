// Experiment 3: Interfacing 16x2 LCD Display with ESP32 using I2C Protocol
// PEMRT525 IoT & Applications Lab | JECC | S5 MR 2K24
// Library: LiquidCrystal_I2C by Frank de Brabander (install via Library Manager)

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD I2C address: 0x27 (try 0x3F if display shows nothing)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int counter = 0;

void setup() {
  lcd.init();          // Initialise the LCD
  lcd.backlight();     // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("  JECC IoT Lab  ");  // Line 1 - fixed text
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(counter);
  lcd.print("   ");    // Clear trailing digits
  counter++;
  delay(1000);          // Update every 1 second
}
