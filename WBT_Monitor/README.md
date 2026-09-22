# WBT Room Alert System
## PEMRT525 IoT & Applications | JECC MR 2K24 S5

### Overview
Outdoor SHT45 sensor connected via 4-wire telephone cable to indoor ESP32 room unit.
Calculates Wet Bulb Temperature (WBT) and alerts when danger zone is reached.

### Files
- `indoor_unit/indoor_unit.ino` — Arduino sketch for ESP32 indoor unit

### Components
| Component | Model | Notes |
|-----------|-------|-------|
| MCU | ESP32 Dev Board | Indoor unit only |
| Sensor | SHT45 (I2C) | Outdoor — high precision ±0.1°C |
| Display | SSD1306 OLED 128×64 | I2C addr 0x3C |
| Buzzer | Active piezo 3.3V | GPIO32 |
| RGB LED | 5mm common cathode | GPIO25/26/27 |
| Battery | 2× 18650 + TP4056 | Backup during power failure |
| Cable | 4-wire telephone wire | Up to 10 m, 50 kHz I2C |

### I2C over telephone cable
- Reduce clock to 50 kHz: `Wire.setClock(50000)` (already in code)
- For distances >10 m: use P82B96 I2C extender at both ends

### Arduino Libraries (install via Library Manager)
1. Adafruit SHT4x Library
2. Adafruit SSD1306
3. Adafruit GFX Library

### Alert Zones
| WBT | Zone | LED | Buzzer |
|-----|------|-----|--------|
| < 24°C | Safe | Green | Silent |
| 24–28°C | Caution | Yellow | 1 beep/min |
| 28–32°C | Danger | Red | Every 10 s |
| > 32°C | ALARM | Red blink | Every 1.5 s |

### WBT Formula
Stull (2011): `WBT = T·atan(0.151977·√(RH+8.313659)) + atan(T+RH) - atan(RH-1.676331) + 0.00391838·RH^1.5·atan(0.023101·RH) - 4.686035`
