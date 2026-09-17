# IoT & Applications — PEMRT525
## Project Lab Experiments & Objectives | Batch MR 2K24 | S5 | JECC

> **Structure:**
> - **Lab Experiments (Common)** — 5 experiments performed by all groups in the lab under supervision.
> - **Project Objectives** — objectives to be completed independently by each group to finish their project.

---

## 🔬 Lab Experiments (Common to All Groups)

### Experiment 1 — ESP32 LED Blink
**Aim:** To write a MicroPython/Arduino program to blink an LED connected to an ESP32 GPIO pin at 1 Hz frequency.

**Procedure:**
1. Connect an LED to GPIO2 of ESP32 through a 220Ω resistor.
2. Write a program to set GPIO2 as OUTPUT.
3. Toggle the GPIO HIGH and LOW with a 500 ms delay in a loop.
4. Observe the LED blinking at 1 Hz.

**Expected Output:** LED blinks continuously at 1-second intervals.

---

### Experiment 2 — ESP32 Switch Controlled LED
**Aim:** To interface a push-button switch with ESP32 and control an LED based on switch input.

**Procedure:**
1. Connect a push-button to GPIO4 (INPUT with internal pull-up) and LED to GPIO2.
2. Write a program to read the button state continuously.
3. Turn the LED ON when button is pressed (LOW) and OFF when released (HIGH).
4. Observe LED responding to button press.

**Expected Output:** LED turns ON when button is pressed and OFF when released.

---

### Experiment 3 — ESP32 LCD Display
**Aim:** To interface a 16×2 LCD (I2C) with ESP32 and display text messages.

**Procedure:**
1. Connect 16×2 LCD via I2C module to ESP32 (SDA → GPIO21, SCL → GPIO22).
2. Install the `LiquidCrystal_I2C` library.
3. Write a program to display "JECC IoT Lab" on Line 1 and a live counter on Line 2.
4. Observe the display updating every second.

**Expected Output:** LCD displays text and live count on two lines.

---

### Experiment 4 — Raspberry Pi LED Blink
**Aim:** To write a Python program to blink an LED connected to a Raspberry Pi GPIO pin at 1 Hz.

**Procedure:**
1. Connect an LED to GPIO17 (BCM) of Raspberry Pi through a 220Ω resistor.
2. Write a Python program using `RPi.GPIO` library.
3. Set GPIO17 as OUTPUT and toggle HIGH/LOW with 0.5 s delay in a loop.
4. Run the program and observe the LED blinking.

**Expected Output:** LED blinks continuously at 1-second intervals.

---

### Experiment 5 — Raspberry Pi Switch Controlled LED
**Aim:** To interface a push-button with Raspberry Pi GPIO and control an LED based on switch input.

**Procedure:**
1. Connect push-button to GPIO18 (BCM, INPUT with pull-up) and LED to GPIO17.
2. Write a Python program to read button state using `RPi.GPIO.input()`.
3. Turn LED ON when button is pressed (LOW) and OFF when released.
4. Observe LED responding to button state.

**Expected Output:** LED turns ON when button is pressed and OFF when released.

---

## P1 — Smart Digital Notice Board
**Group 2 | Hardware:** Raspberry Pi 3/4 + PIR / Ultrasonic Sensor  
**GitHub:** [me-jobis/Smart-Notice-Board](https://github.com/me-jobis/Smart-Notice-Board)

### 📋 Project Objectives *(to be completed by the group)*
1. To fetch live weather data (temperature, humidity, condition) and news headlines from public APIs using Python on the Raspberry Pi and display the retrieved data on screen.
2. To develop a fullscreen rotating display application using pygame that auto-cycles content categories (timetable, achievements, announcements, live clock) every 10 seconds.
3. To build a Flask-based web admin panel accessible over the college LAN for remote notice management without physical access to the display unit.

---

## P2 — Smart AC Controller with Power Failure Handling
**Group 3 | Hardware:** ESP32 + PIR + Relay + DS3231 RTC + SD Card  
**GitHub:** [joelsppl696-hash/Smart-AC-contoller-with-power-failure-handling](https://github.com/joelsppl696-hash/Smart-AC-contoller-with-power-failure-handling)

### 📋 Project Objectives *(to be completed by the group)*
1. To implement automated AC ON/OFF control logic based on occupancy detection (10-minute no-motion timeout) and office-hours time scheduling using the DS3231 RTC.
2. To handle power failure and restoration events — on power restore, check PIR state before re-activating the relay to prevent unnecessary AC restart in an empty room.
3. To log all system events (AC ON, AC OFF, power failure, power restore, trigger source) with RTC timestamps to a CSV file on SD card for energy auditing.

---

## P3 — RFID-Based Smart EV Charging Station
**Group 5 | Hardware:** ESP32 + RC522 RFID + PZEM-004T + Relay + 16×2 LCD  
**GitHub:** [MAdithyaMenon/RFID-EV-CHARGING](https://github.com/MAdithyaMenon/RFID-EV-CHARGING)

### 📋 Project Objectives *(to be completed by the group)*
1. To interface PZEM-004T energy meter with ESP32 and measure real-time voltage, current, power, and kWh consumed during a charging session, displaying live values on the LCD.
2. To transmit session data (Staff ID, kWh, cost, start/end time) via HTTP POST to a Flask server and store records in SQLite.
3. To build a Flask admin dashboard showing per-staff usage history and monthly billing summary.

---

## P4 — LoRa-Based Campus Outdoor Weather Station
**Group 4 | Hardware:** 2× ESP32 + LoRa SX1278 + DHT22 + BMP280 + FC-37 + Anemometer  
**GitHub:** [Njv1232/IoT-project-Weather-Station](https://github.com/Njv1232/IoT-project-Weather-Station)

### 📋 Project Objectives *(to be completed by the group)*
1. To extend the system to two sensor nodes, each transmitting with a unique Node ID, and add FC-37 rain sensor and anemometer (wind speed) to the rooftop node.
2. To develop a gateway ESP32 that receives LoRa packets from both nodes and forwards aggregated data to a Flask server via Wi-Fi using HTTP POST.
3. To build a Flask dashboard displaying live readings from both nodes, 6-hour trend charts, rain and heat alert banners, and CSV logging of all readings.

---

## P6 — College Bus Tracker
**Group 1 | Hardware:** ESP32 + NEO-6M GPS Module  
**GitHub:** [D0n41d/IoT-Project](https://github.com/D0n41d/IoT-Project)

### 📋 Project Objectives *(to be completed by the group)*
1. To design a button-based trip status state machine (Departed → En Route → Arrived) with LED indicators showing current trip state.
2. To implement periodic HTTP heartbeat transmission (every 30 seconds) carrying trip status and GPS coordinates to the Flask server, with automatic "Not Running" detection after a 5-minute heartbeat gap.
3. To build a Flask server with SQLite trip logging and a real-time bus status dashboard showing current status, last ping time, elapsed trip time, and a full day trip log.

---

## Summary

### Common Lab Experiments (All Groups)

| Exp | Title | Platform |
|-----|-------|----------|
| 1 | ESP32 LED Blink | ESP32 |
| 2 | ESP32 Switch Controlled LED | ESP32 |
| 3 | ESP32 LCD Display | ESP32 + 16×2 I2C LCD |
| 4 | Raspberry Pi LED Blink | Raspberry Pi |
| 5 | Raspberry Pi Switch Controlled LED | Raspberry Pi |

### Project Objectives (Group-wise)

| Group | Project | Project Objectives (Self) |
|-------|---------|--------------------------|
| Group 2 | P1 — Smart Digital Notice Board | Weather/News API + pygame display + Flask admin |
| Group 3 | P2 — Smart AC Controller | AC control logic + power failure + CSV logging |
| Group 5 | P3 — RFID EV Charging Station | PZEM-004T energy meter + Flask server + billing |
| Group 4 | P4 — Campus Weather Station | Multi-node LoRa + gateway + Flask dashboard |
| Group 1 | P6 — College Bus Tracker | State machine + heartbeat + bus dashboard |

---

*PEMRT525 | Department of Mechatronics Engineering | Jyothi Engineering College | KTU S5 MR 2K24*
