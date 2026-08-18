# IoT & Applications — PEMRT525
## Project Lab Experiments & Objectives | Batch MR 2K24 | S5 | JECC

> **Structure:**
> - **Lab Experiment** — one objective performed in the lab session under supervision.
> - **Project Objectives** — remaining objectives to be completed independently by the group to finish the project.

---

## P1 — Smart Digital Notice Board
**Group 2 | Hardware:** Raspberry Pi 3/4 + PIR / Ultrasonic Sensor  
**GitHub:** [me-jobis/Smart-Notice-Board](https://github.com/me-jobis/Smart-Notice-Board)

### 🔬 Lab Experiment
To interface a PIR sensor or ultrasonic sensor with Raspberry Pi GPIO and implement occupancy-based monitor ON/OFF control — turning the display ON when presence is detected and automatically powering it OFF after 60 seconds of no detected motion.

### 📋 Project Objectives *(to be completed by the group)*
1. To fetch live weather data (temperature, humidity, condition) and news headlines from public APIs using Python on the Raspberry Pi and display the retrieved data on screen.
2. To develop a fullscreen rotating display application using pygame that auto-cycles content categories (timetable, achievements, announcements, live clock) every 10 seconds.
3. To build a Flask-based web admin panel accessible over the college LAN for remote notice management without physical access to the display unit.

---

## P2 — Smart AC Controller with Power Failure Handling
**Group 3 | Hardware:** ESP32 + PIR + Relay + DS3231 RTC + SD Card  
**GitHub:** [joelsppl696-hash/Smart-AC-contoller-with-power-failure-handling](https://github.com/joelsppl696-hash/Smart-AC-contoller-with-power-failure-handling)

### 🔬 Lab Experiment
To interface PIR sensor, relay module, DS3231 RTC (I2C), and SD card module (SPI) with ESP32 and verify multi-peripheral communication — reading PIR state, getting current time from RTC, and writing a test log entry to a CSV file on the SD card.

### 📋 Project Objectives *(to be completed by the group)*
1. To implement automated AC ON/OFF control logic based on occupancy detection (10-minute no-motion timeout) and office-hours time scheduling using the DS3231 RTC.
2. To handle power failure and restoration events — on power restore, check PIR state before re-activating the relay to prevent unnecessary AC restart in an empty room.
3. To log all system events (AC ON, AC OFF, power failure, power restore, trigger source) with RTC timestamps to a CSV file on SD card for energy auditing.

---

## P3 — RFID-Based Smart EV Charging Station
**Group 5 | Hardware:** ESP32 + RC522 RFID + PZEM-004T + Relay + 16×2 LCD  
**GitHub:** [MAdithyaMenon/RFID-EV-CHARGING](https://github.com/MAdithyaMenon/RFID-EV-CHARGING)

### 🔬 Lab Experiment
To interface the RC522 RFID reader with ESP32, read staff RFID card UIDs, validate against a registered card list, control a relay based on authentication result, and display authentication status (Access Granted / Access Denied) on a 16×2 I2C LCD.

### 📋 Project Objectives *(to be completed by the group)*
1. To interface PZEM-004T energy meter with ESP32 and measure real-time voltage, current, power, and kWh consumed during a charging session, displaying live values on the LCD.
2. To transmit session data (Staff ID, kWh, cost, start/end time) via HTTP POST to a Flask server and store records in SQLite.
3. To build a Flask admin dashboard showing per-staff usage history and monthly billing summary.

---

## P4 — LoRa-Based Campus Outdoor Weather Station
**Group 4 | Hardware:** 2× ESP32 + LoRa SX1278 + DHT22 + BMP280 + FC-37 + Anemometer  
**GitHub:** [Njv1232/IoT-project-Weather-Station](https://github.com/Njv1232/IoT-project-Weather-Station)

### 🔬 Lab Experiment
To interface DHT22 (temperature and humidity) and BMP280 (atmospheric pressure) with ESP32, transmit the sensor readings wirelessly using LoRa SX1278 from a sensor node to a gateway node, and print the received data on the gateway's Serial Monitor — demonstrating LoRa point-to-point communication.

### 📋 Project Objectives *(to be completed by the group)*
1. To extend the system to two sensor nodes, each transmitting with a unique Node ID, and add FC-37 rain sensor and anemometer (wind speed) to the rooftop node.
2. To develop a gateway ESP32 that receives LoRa packets from both nodes and forwards aggregated data to a Flask server via Wi-Fi using HTTP POST.
3. To build a Flask dashboard displaying live readings from both nodes, 6-hour trend charts, rain and heat alert banners, and CSV logging of all readings.

---

## P6 — College Bus Tracker
**Group 1 | Hardware:** ESP32 + NEO-6M GPS Module  
**GitHub:** [D0n41d/IoT-Project](https://github.com/D0n41d/IoT-Project)

### 🔬 Lab Experiment
To interface a NEO-6M GPS module with ESP32, parse live GPS coordinates (latitude, longitude, speed, timestamp) from NMEA sentences, transmit the data via HTTP POST to a Flask server over Wi-Fi, and store each GPS record in a SQLite database.

### 📋 Project Objectives *(to be completed by the group)*
1. To design a button-based trip status state machine (Departed → En Route → Arrived) with LED indicators showing current trip state.
2. To implement periodic HTTP heartbeat transmission (every 30 seconds) carrying trip status and GPS coordinates to the Flask server, with automatic "Not Running" detection after a 5-minute heartbeat gap.
3. To build a Flask server with SQLite trip logging and a real-time bus status dashboard showing current status, last ping time, elapsed trip time, and a full day trip log.

---

## Summary

| Group | Project | Lab Experiment (In Lab) | Project Objectives (Self) |
|-------|---------|------------------------|--------------------------|
| Group 2 | P1 — Smart Digital Notice Board | PIR/Ultrasonic → RPi GPIO → Monitor ON/OFF | Weather/News API + pygame display + Flask admin |
| Group 3 | P2 — Smart AC Controller | ESP32 multi-peripheral: PIR + Relay + RTC + SD card | AC control logic + power failure + CSV logging |
| Group 5 | P3 — RFID EV Charging Station | RC522 RFID auth + relay + LCD display | PZEM-004T energy meter + Flask server + billing |
| Group 4 | P4 — Campus Weather Station | DHT22 + BMP280 + LoRa point-to-point | Multi-node + gateway + Flask dashboard + alerts |
| Group 1 | P6 — College Bus Tracker | NEO-6M GPS → Flask → SQLite | State machine + heartbeat + bus dashboard |

---

*PEMRT525 | Department of Mechatronics Engineering | Jyothi Engineering College | KTU S5 MR 2K24*
