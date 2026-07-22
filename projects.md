# IoT & Applications — PEMRT525
## Project Topics | Batch MR 2K24 | Semester S5 | JECC

> 6 project topics. Each group picks one. No two groups may select the same project.    
> All implementations must be **hardware-based**.  
> Submit: Source code + Circuit diagram + Demo video (max 2 min) + One-page report

---

## Summary

| # | Project | Hardware | Protocol |
|---|---------|----------|----------|
| P1 | Smart Digital Notice Board | Raspberry Pi 3/4 | Wi-Fi (LAN) |
| P2 | Smart AC Controller | ESP32 | GPIO + SD card |
| P3 | RFID EV Charging Station | ESP32 + Flask | Wi-Fi (LAN) + RFID |
| P4 | Campus Weather Station | ESP32 + LoRa SX1278 | LoRaWAN |
| P5 | Staff Location Tracker | ESP32 badge | Wi-Fi (LAN) |
| P6 | College Bus Tracker v1 *(optional)* | ESP32 + Mobile Hotspot | Wi-Fi / Mobile |

---

## P1 — Smart Digital Notice Board with Motion-Activated Display

**Hardware:** Raspberry Pi 3/4, PIR sensor, HDMI cable, TV/monitor  
**Stack:** Python, Flask (admin panel), pygame (fullscreen display), RPi.GPIO  
**Modules:** 2 & 4 | **CO:** CO2, CO5

### Problem Statement
Traditional notice boards at JECC are static, paper-based, and require manual updates by staff — causing delays in communicating time-critical information such as timetable changes, exam schedules, and events. Notices posted in one location are not visible across departments, and there is no centralized control over what is displayed. Displays left ON continuously also waste electricity when corridors are empty.

Design a Raspberry Pi-based Smart Digital Notice Board with a Flask web admin panel accessible from any device on the college LAN. A PIR motion sensor detects human presence — the display automatically turns ON when someone approaches and turns OFF after 60 seconds of no motion.

**Content categories displayed on TV/monitor:**
- Timetable — current day's class schedule auto-loaded from a file
- Achievements — student/faculty awards, results, publications
- General Announcements — exam notifications, holiday alerts, events
- Live Clock & Date — always visible on screen

Content auto-rotates every 10 seconds. Admin can add/edit/delete notices from any phone or laptop on the network without touching the display unit.

### Deliverables
1. Circuit diagram — PIR to RPi GPIO pin connection
2. `smart_noticeboard.py` — fullscreen display, auto-rotate, PIR on/off control
3. Flask admin panel — add/edit/delete notices, timetable upload
4. Screenshots — admin panel UI, display rotating through all 4 categories, PIR trigger
5. One-page report — system architecture, content rotation logic, PIR threshold, power saving estimate

---

## P2 — Smart AC Controller with Power Failure Handling

**Hardware:** ESP32, PIR sensor, relay module, DS3231 RTC (I2C), SD card module (SPI), powerbank  
**Stack:** Arduino (ESP32)  
**Modules:** 2 & 4 | **CO:** CO2, CO5

### Problem Statement
AC units in JECC classrooms and staff rooms run unnecessarily in two scenarios: (1) occupants forget to switch off the AC when leaving, and (2) when a power failure occurs while the AC is ON, the unit automatically resumes when power is restored — because most AC units retain their last ON state. There is no usage record to verify energy conservation compliance.

Design an ESP32-based smart AC controller with these Auto OFF rules:
- PIR detects no motion for 10 continuous minutes → relay OFF
- After office hours (5:00 PM) → PIR checked; if room empty → AC OFF
- Power restored after failure → ESP32 boots, checks PIR; if empty → relay stays OFF

**All events logged to `log.csv` on SD card:**

| Field | Description |
|-------|-------------|
| Timestamp | From DS3231 RTC |
| Event | AC ON / AC OFF / Power Failure / Power Restored |
| AC State | ON / OFF |
| Trigger | Manual / Motion timeout / Office hours / Power restore check |

SD card is removable and readable on any PC for energy audit. ESP32 runs on powerbank during power cut to log failure events accurately.

### Deliverables
1. Circuit diagram — ESP32 with PIR, relay, DS3231 RTC, SD card module
2. `ac_controller.ino` — PIR read, relay control, RTC time check, SD card CSV write
3. Sample `log.csv` showing all event types including power failure and restore
4. Demo video — AC OFF on no-motion, power cut scenario, power restore with room-empty check
5. One-page report — state machine diagram (AC states), office hours config, audit log format

---

## P3 — RFID-Based Smart EV Charging Station with LAN Server

**Hardware:** ESP32, RC522 RFID reader, PZEM-004T energy meter, relay module, 16×2 I2C LCD  
**Stack:** Arduino (ESP32), Python Flask, SQLite  
**Modules:** 1, 3 & 4 | **CO:** CO1, CO3, CO5

### Problem Statement
JECC staff who own electric vehicles have no dedicated or accountable charging facility at college. Open power outlets lead to unmetered electricity consumption with no cost recovery. A fair, authenticated system is needed where staff are identified before charging begins and billed only for the exact units they consume.

**Charging Flow:**
- Staff taps RFID card on RC522 reader → ESP32 validates staff ID
- If valid → relay closes → 3-pin socket powers ON → session starts
- LCD shows: staff name, live kWh consumed, live cost (₹)
- Staff taps RFID again → relay opens → ESP32 sends session data via HTTP POST to Flask server

**Flask Server (SQLite on LAN PC):**
- Stores all sessions: Staff ID, Name, Date, Start/End Time, kWh, Cost (₹)
- Admin dashboard — per-staff usage, session history
- Monthly bill summary per staff filterable by month

### Deliverables
1. Circuit diagram — ESP32 with RC522, PZEM-004T, relay, 16×2 LCD
2. `ev_charger.ino` — RFID auth, relay control, PZEM-004T read, HTTP POST on session end
3. Flask server — session store (SQLite), admin dashboard, monthly bill view
4. Screenshots — admin dashboard with session table, monthly bill for one staff member
5. One-page report — RFID auth flow, PZEM-004T parameters (V/A/W/kWh), cost formula used

---

## P4 — LoRa-Based Campus Outdoor Weather Station

**Hardware:** 2× ESP32 + LoRa SX1278, DHT22, BMP280, rain sensor FC-37, anemometer, 18650 battery, RPi + TV  
**Stack:** Arduino (ESP32), Python Flask  
**Modules:** 3 & 4 | **CO:** CO3, CO5

### Problem Statement
JECC has no real-time weather monitoring on campus. Outdoor events like sports day and fests are planned without local weather data — relying on generic city-level forecasts that don't reflect actual campus conditions. Sudden rain or extreme heat causes disruption with no prior warning.

**Node 1 — Rooftop (ESP32 + LoRa SX1278):**
- DHT22 — temperature and humidity
- BMP280 — atmospheric pressure
- Rain sensor FC-37 — rainfall detection
- Anemometer — wind speed (RPM → km/h)
- Transmits LoRa packet every 5 minutes

**Node 2 — College Grounds (ESP32 + LoRa SX1278):**
- DHT22 — temperature and humidity
- Rain sensor FC-37 — rainfall detection
- Transmits every 5 minutes with node ID

**Gateway (ESP32 + LoRa — in lab):** Receives from both nodes → HTTP POST to Flask server via Wi-Fi

**Central Dashboard (Flask + RPi → TV):**
- Live readings from both nodes side by side
- 6-hour trend charts for temperature and humidity
- Rain alert banner — when rain detected on either node
- Heat alert banner — when temperature exceeds 38°C
- All readings logged to `weather_log.csv`

### Deliverables
1. Circuit diagrams — rooftop node, grounds node, gateway unit (3 diagrams)
2. `weather_node.ino` — sensor read, LoRa packet transmit (node ID set by `#define`)
3. `gateway.ino` — LoRa receive, HTTP POST to Flask
4. Flask server + RPi dashboard — live readings, charts, alert banners, CSV log
5. One-page report — LoRa packet structure, RSSI observed, comparison of both node readings, alert thresholds

---

## P5 — ESP32 WiFi-Based Staff Location Tracker

**Hardware:** ESP32 badge (one per staff), PC/RPi running Flask server on college LAN  
**Stack:** Arduino (ESP32 WiFi scan), Python Flask, SQLite  
**Modules:** 1 & 3 | **CO:** CO1, CO3

### Problem Statement
Students at JECC frequently visit the department to meet a faculty member, only to find them absent — in a lab, another block, or off-campus. There is no way to check a staff member's location before making the trip, wasting time for both parties.

Each staff member carries an ESP32 badge that scans college Wi-Fi access points and connects to the strongest one. Since each AP covers a defined zone (Staff Room, ECE Lab, HOD Office, Seminar Hall, etc.), the connected AP identifies the staff member's current location. The ESP32 sends a heartbeat (Staff ID + AP name + RSSI + timestamp) to a Flask server on the college LAN every 30 seconds. If no heartbeat is received for 5 minutes, staff is marked Off Campus.

**TV Dashboard (student corridor):**
- 🟢 On Campus — staff name + current zone + last seen time
- 🔴 Off Campus — last seen time shown

### Deliverables
1. `staff_badge.ino` — WiFi AP scan, strongest AP selection, HTTP POST heartbeat every 30 sec
2. Flask server — staff registry (SQLite), heartbeat endpoint, location update logic
3. TV dashboard (Flask HTML) — live staff location table with status indicators
4. Screenshots — dashboard showing 3+ staff with On Campus (different zones) and Off Campus states
5. One-page report — AP-to-zone mapping table, heartbeat timeout logic, privacy note, GPS upgrade path

---

## P6 — College Bus Tracker — Initial Version *(Optional)*

**Hardware:** ESP32, push button (3 trip states), LED status indicator, powerbank  
**Stack:** Arduino (ESP32 multi-SSID WiFi), Python Flask, SQLite  
**Modules:** 1 & 3 | **CO:** CO1, CO3

### Problem Statement
Students and parents waiting for the JECC college bus have no visibility of bus location or arrival time. The driver cannot communicate delays to the college. The transport office has no record of departure and arrival times for accountability.

**How it works:**
- ESP32 pre-programmed with driver's mobile hotspot SSID + college Wi-Fi SSID
- Driver turns ON hotspot when bus departs → ESP32 connects → pings server every 30 sec
- Driver presses button to cycle trip status: Departed → En Route → Arrived
- When bus returns to campus → ESP32 auto-connects to college Wi-Fi → status updates to "Arrived at Campus"
- LED: Blue = college WiFi, Yellow = hotspot, Red = no connection

**Dashboard (college LAN — TV/browser):**
- Bus name, driver, current status, last ping, elapsed time
- Full day trip log — departure, arrival, duration

**Future Upgrade:** Add NEO-6M GPS → send live coordinates → plot on map

### Deliverables
1. `bus_tracker.ino` — multi-SSID WiFi, button state machine, HTTP POST heartbeat
2. Flask server — trip log (SQLite), status endpoint, dashboard
3. TV dashboard — bus status card, last ping, trip log table
4. Screenshots — En Route state, Arrived state, full trip log
5. One-page report — multi-SSID logic, trip state machine diagram, GPS upgrade plan

