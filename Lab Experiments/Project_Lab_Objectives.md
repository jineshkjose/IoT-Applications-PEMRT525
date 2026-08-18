# IoT & Applications — PEMRT525
## Project Lab Objectives | Batch MR 2K24 | S5 | JECC

> These objectives are derived from the five selected hardware projects.  
> Each objective is written in lab experiment format: **"To [action] [what] [using what]"**

---

## P1 — Smart Digital Notice Board
**Group 2 | Hardware:** Raspberry Pi 3/4 + PIR sensor | **Protocol:** Wi-Fi (LAN)  
**GitHub:** [me-jobis/Smart-Notice-Board](https://github.com/me-jobis/Smart-Notice-Board)

### Objectives
1. To interface a PIR motion sensor with Raspberry Pi GPIO and implement occupancy-based display ON/OFF control.
2. To develop a fullscreen rotating display application using pygame that auto-cycles content categories (timetable, achievements, announcements, live clock) every 10 seconds.
3. To build a Flask-based web admin panel accessible over the college LAN for remote notice management without physical access to the display unit.
4. To demonstrate IoT-based energy conservation by automatically powering off the display after 60 seconds of no detected motion.

---

## P2 — Smart AC Controller with Power Failure Handling
**Group 3 | Hardware:** ESP32 + PIR + Relay + DS3231 RTC + SD Card | **Protocol:** GPIO + SPI/I2C  
**GitHub:** [joelsppl696-hash/Smart-AC-contoller-with-power-failure-handling](https://github.com/joelsppl696-hash/Smart-AC-contoller-with-power-failure-handling)

### Objectives
1. To interface PIR sensor, relay module, DS3231 RTC (I2C), and SD card module (SPI) with ESP32 and implement multi-peripheral communication on a single microcontroller.
2. To implement automated AC ON/OFF control logic based on occupancy detection (10-minute no-motion timeout) and office-hours time scheduling using RTC.
3. To handle power failure and power restoration events — on power restore, check PIR state before re-activating the relay to prevent unnecessary AC restart in an empty room.
4. To log all system events (AC ON, AC OFF, power failure, power restore, trigger source) with RTC timestamps to a CSV file on SD card for energy auditing and compliance verification.

---

## P3 — RFID-Based Smart EV Charging Station with LAN Server
**Group 5 | Hardware:** ESP32 + RC522 RFID + PZEM-004T + Relay + 16×2 LCD | **Protocol:** Wi-Fi (LAN) + RFID  
**GitHub:** [MAdithyaMenon/RFID-EV-CHARGING](https://github.com/MAdithyaMenon/RFID-EV-CHARGING)

### Objectives
1. To interface RC522 RFID reader, PZEM-004T energy meter, relay module, and 16×2 I2C LCD with ESP32 to build a complete hardware stack for a metered charging station.
2. To implement RFID-based user authentication — allow charging only for registered staff RFID cards and display an error message on the LCD for unrecognised cards.
3. To measure and display real-time energy consumption parameters (voltage, current, power, kWh) and calculated session cost (₹) on the LCD throughout the active charging session.
4. To transmit session data (Staff ID, kWh consumed, cost, start/end time) via HTTP POST to a Flask server with SQLite storage and an admin dashboard showing per-staff usage and monthly billing.

---

## P4 — LoRa-Based Campus Outdoor Weather Station
**Group 4 | Hardware:** 2× ESP32 + LoRa SX1278 + DHT22 + BMP280 + FC-37 + Anemometer | **Protocol:** LoRaWAN  
**GitHub:** [Njv1232/IoT-project-Weather-Station](https://github.com/Njv1232/IoT-project-Weather-Station)

### Objectives
1. To interface DHT22 (temperature and humidity), BMP280 (atmospheric pressure), FC-37 rain sensor, and anemometer with ESP32 for multi-parameter outdoor environmental sensing.
2. To implement LoRa (SX1278) wireless communication between two remote sensor nodes and a gateway ESP32, demonstrating long-range IoT data transmission using the LoRaWAN protocol.
3. To design a multi-node architecture where each node includes its Node ID in the transmitted LoRa packet, and the gateway aggregates data from both nodes and forwards it to a central Flask server via Wi-Fi.
4. To develop a Flask dashboard displaying live readings from both nodes side by side, 6-hour trend charts for temperature and humidity, automatic rain and heat alert banners, and CSV logging of all readings.

---

## P6 — College Bus Tracker — Lab Experiment
**Group 1 | Hardware:** ESP32 + NEO-6M GPS Module | **Protocol:** Wi-Fi (College LAN)  
**GitHub:** [D0n41d/IoT-Project](https://github.com/D0n41d/IoT-Project)

> **Lab Scope:** GPS data acquisition and upload to Flask server with SQLite storage.  
> *(Full project features such as trip state machine and dashboard are implemented outside lab.)*

### Objective
To interface a NEO-6M GPS module with ESP32, parse live GPS coordinates (latitude, longitude, speed, timestamp), transmit the data via HTTP POST to a Flask server over Wi-Fi, and store each GPS record in a SQLite database — demonstrating IoT-based real-time location data logging.

---

## Summary Table

| Group | Project | Key Hardware | Key Protocol | Objectives Count |
|-------|---------|-------------|-------------|-----------------|
| Group 1 | P6 — College Bus Tracker | ESP32, NEO-6M GPS | Wi-Fi (LAN) → Flask → SQLite | 1 |
| Group 2 | P1 — Smart Digital Notice Board | Raspberry Pi, PIR | Wi-Fi (LAN) | 4 |
| Group 3 | P2 — Smart AC Controller | ESP32, PIR, Relay, RTC, SD | GPIO + I2C + SPI | 4 |
| Group 4 | P4 — Campus Weather Station | 2× ESP32, LoRa SX1278 | LoRaWAN | 4 |
| Group 5 | P3 — RFID EV Charging Station | ESP32, RC522, PZEM-004T | Wi-Fi + RFID | 4 |

---

*PEMRT525 | Department of Mechatronics Engineering | Jyothi Engineering College | KTU S5 MR 2K24*
