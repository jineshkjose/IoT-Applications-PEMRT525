# PEMRT525 — IoT & Applications
## Viva Question Bank with Answers
**S5 Mechatronics (MR 2K24) | JECC | Faculty: Mr. Jinesh K J**

> 4 Modules | 10 questions each | 40 questions total

---

## MODULE 1 — Introduction to IoT

**Q1. What is IoT? Give its full form.**
IoT stands for **Internet of Things**. It is a network of physical objects ("Things") embedded with sensors, software, and connectivity that enables them to collect and exchange data over the internet.

---

**Q2. List the five key characteristics of IoT.**
Remembered as **DSIUI**:
1. Dynamic & self-adapting
2. Self-configuring
3. Interoperable
4. Unique identity (IP address / URI)
5. Integrated into the information network

---

**Q3. What are the two components of IoT Physical Design?**
1. **Things** — physical devices with sensing/actuation capability
2. **Protocol Stack** — communication layers (application, transport, network, link, physical)

---

**Q4. Name the functional blocks in IoT Logical Design.**
1. Device
2. Communication
3. Services
4. Management
5. Security
6. Application

---

**Q5. Name the four IoT communication models.**
1. Request-Response (HTTP, CoAP)
2. Publish-Subscribe (MQTT)
3. Push-Pull (queue-based)
4. Exclusive Pair (WebSocket)

---

**Q6. Explain the Publish-Subscribe communication model.**
A **broker** sits between publishers and subscribers. Publishers send messages to a topic on the broker; subscribers receive all messages on that topic. Neither knows the other directly. Used in **MQTT**.

---

**Q7. What is the Exclusive Pair communication model?**
A **persistent, full-duplex (two-way)** connection between client and server. Both can send data at any time without a new request. **WebSocket** protocol uses this model.

---

**Q8. What are IoT enabling technologies? Name any four.**
1. Wireless Sensor Networks (WSN)
2. Cloud Computing
3. Embedded Systems
4. RFID
5. Big Data Analytics
6. Communication Protocols (MQTT, CoAP)

---

**Q9. What is IoT Level 1? Give its characteristics.**
The simplest IoT configuration — a **single node** that senses, processes data locally, and controls an actuator. No cloud or internet required. Example: a thermostat that reads temperature and turns on a fan.

---

**Q10. What is the difference between IoT Level 1 and Level 6?**
- **Level 1** — single node, local analysis, no cloud
- **Level 6** — multiple nodes, cloud storage, big data analytics, remote monitoring, full internet integration — the most complex IoT deployment

---

## MODULE 2 — M2M, SDN/NFV, Smart Objects & Sensor Networks

**Q1. What is M2M communication?**
**Machine-to-Machine (M2M)** is direct communication between devices for remote monitoring and control without human intervention. Example: a vending machine automatically reporting low stock to a server.

---

**Q2. What are the key differences between M2M and IoT?**

| Aspect | M2M | IoT |
|---|---|---|
| Protocols | Proprietary / non-IP | Open IP-based (HTTP, MQTT, CoAP) |
| Connectivity | Closed, point-to-point | Open internet |
| Data storage | On-premises (siloed) | Cloud |
| Scalability | Limited | Highly scalable |
| Integration | Difficult | Easy (open standards) |

---

**Q3. What is SDN? What problem does it solve?**
**Software Defined Networking (SDN)** separates the **control plane** (routing decisions) from the **data plane** (packet forwarding) and centralises control in a software controller. It solves the complexity of managing large networks where each device runs its own routing logic.

---

**Q4. Name the three layers of SDN.**
1. **Infrastructure Layer (Data Plane)** — switches/routers that forward packets
2. **Control Layer (Control Plane)** — centralised SDN controller (the "brain")
3. **Application Layer** — SDN apps communicating via northbound APIs

---

**Q5. What is OpenFlow in SDN?**
**OpenFlow** is the standard southbound protocol between the SDN controller and network switches. The controller uses OpenFlow to program flow tables in switches, telling them how to forward packets.

---

**Q6. What is NFV? How does it differ from SDN?**
**NFV (Network Function Virtualization)** runs network functions (firewalls, NAT, load balancers) as software on standard servers instead of dedicated hardware.
- **SDN** = separates and centralises *control* of network traffic
- **NFV** = virtualises the *network functions* themselves
They complement each other — SDN manages the network; NFV provides software-based functions.

---

**Q7. What are the three components of NFV architecture?**
1. **VNF** — Virtualized Network Function (software running the network function)
2. **NFVI** — NFV Infrastructure (servers, storage, network hosting VNFs)
3. **NFV MANO** — Management & Orchestration (deploys, scales, monitors VNFs)

---

**Q8. What is a sensor? What is an actuator? Give one example each.**
- **Sensor** — measures a physical quantity and converts it to an electrical signal. Example: DHT22 (temperature & humidity)
- **Actuator** — converts an electrical signal into a physical action. Example: Solenoid valve, relay, motor

---

**Q9. What is MEMS? Where is it used in IoT?**
**MEMS (Micro-Electro-Mechanical Systems)** are miniaturised devices integrating mechanical and electrical components on a silicon chip. Used as accelerometers, gyroscopes, and pressure sensors in smartphones and IoT devices.

---

**Q10. What is a Wireless Sensor Network (WSN)? What are the communication criteria for connecting smart objects?**
A **WSN** is a network of spatially distributed sensor nodes that wirelessly communicate with each other and a gateway to collect environmental data.

Communication criteria for connecting smart objects:
1. **Range** — short range (Bluetooth), medium (ZigBee), long range (LoRa, NB-IoT)
2. **Power consumption** — battery-powered nodes need low-power protocols
3. **Bandwidth / data rate** — how much data needs to be sent
4. **Reliability / QoS** — critical applications need guaranteed delivery
5. **Cost** — licensed vs unlicensed spectrum, hardware cost

---

## MODULE 3 — IoT Communication Protocols

**Q1. What is IEEE 802.15.4? What does it define?**
**IEEE 802.15.4** is a standard that defines the **Physical (PHY) layer** and **Medium Access Control (MAC) layer** for low-rate Wireless Personal Area Networks (LR-WPANs). It is the foundation protocol used by ZigBee, 6LoWPAN, and other IoT standards.

---

**Q2. What does the IEEE 802.15.4 Physical Layer do?**
The PHY layer handles:
- Radio frequency operation (868 MHz, 915 MHz, 2.4 GHz bands)
- Modulation (DSSS — Direct Sequence Spread Spectrum)
- Data transmission and reception
- Clear Channel Assessment (CCA) — checks if the channel is free before transmitting

---

**Q3. What does the IEEE 802.15.4 MAC Layer do?**
The MAC layer handles:
- **CSMA-CA** (Carrier Sense Multiple Access with Collision Avoidance) — manages channel access
- Beacon generation and synchronisation (for coordinator devices)
- Association and disassociation of devices
- Reliable link between adjacent nodes using acknowledgements (ACK)

---

**Q4. What are 802.15.4e and 802.15.4g? (Future of 802.15.4)**
- **802.15.4e** — enhanced MAC layer amendment for industrial IoT; adds Time Slotted Channel Hopping (TSCH) for reliability and determinism in factory automation
- **802.15.4g** — PHY layer amendment for Smart Utility Networks (SUN); adds sub-GHz frequency bands and higher data rates for smart grid / smart metering applications

---

**Q5. What is Modbus? Name its three variants.**
**Modbus** is a serial communication protocol for industrial devices (developed 1979). Three variants:
1. **Modbus RTU** — binary encoding, compact, used over RS-485
2. **Modbus ASCII** — ASCII text encoding, human-readable
3. **Modbus TCP** — Modbus over Ethernet/TCP-IP

---

**Q6. Name the four register types in Modbus.**
1. **Coils** — read/write, 1-bit (digital output)
2. **Discrete Inputs** — read-only, 1-bit (digital input)
3. **Holding Registers** — read/write, 16-bit (analog output / configuration)
4. **Input Registers** — read-only, 16-bit (analog input / sensor data)

---

**Q7. What are the three ZigBee device types and three topologies?**
Device types: **Coordinator** (manages network), **Router** (extends range), **End Device** (sleeps to save power)

Topologies: **Star** (all to coordinator), **Tree** (hierarchical), **Mesh** (any router to any router — most robust, uses AODV routing)

---

**Q8. What modulation does LoRaWAN use? Explain Spreading Factors.**
**CSS (Chirp Spread Spectrum)** — frequency sweeps up/down over time. Gives long range + interference resistance.

Spreading Factors SF7–SF12:
- **SF7** — highest data rate, shortest range
- **SF12** — lowest data rate, longest range
Higher SF = more redundancy = longer range but slower.

---

**Q9. What is LTE-M? How does it differ from NB-IoT?**

| Feature | LTE-M | NB-IoT |
|---|---|---|
| Bandwidth | 1.4 MHz | 180 kHz |
| Data rate | ~1 Mbps | ~250 kbps |
| Mobility | Supports handover (good for moving devices) | Limited mobility |
| Voice | Supports VoLTE | No voice |
| Power | Low | Ultra-low |
| Use case | Asset tracking, wearables | Smart meters, sensors |

Both use **licensed cellular bands** and existing cellular infrastructure.

---

**Q10. What is NB-IoT? Give its key specifications.**
**NB-IoT (Narrowband IoT)** — 3GPP Release 13 LPWA standard:
- Bandwidth: **180 kHz** (one LTE resource block)
- Operates in **licensed cellular bands**
- Range: up to 10 km; excellent deep indoor penetration
- Very low power — device battery can last 10+ years
- Uses existing cellular towers (no new infrastructure)

---

## MODULE 4 — RPi Programming, IoT Security & Smart City

**Q1. What is the Raspberry Pi GPIO header? How many pins does it have?**
GPIO (General Purpose Input/Output) is the **40-pin header** on the Raspberry Pi providing power pins (3.3V, 5V), ground pins, and programmable I/O pins for connecting sensors, actuators, displays, etc.

---

**Q2. What is the difference between BCM and BOARD pin numbering in RPi.GPIO?**
- **BCM** — Broadcom chip's GPIO numbering (e.g., GPIO17). `GPIO.setmode(GPIO.BCM)`
- **BOARD** — physical pin position on the 40-pin header (e.g., pin 11). `GPIO.setmode(GPIO.BOARD)`

---

**Q3. Name the communication interfaces on Raspberry Pi and their pin numbers (BCM).**

| Interface | Pins |
|---|---|
| UART | GPIO 14 (TX), GPIO 15 (RX) |
| I2C | GPIO 2 (SDA), GPIO 3 (SCL) |
| SPI | GPIO 10 (MOSI), GPIO 9 (MISO), GPIO 11 (SCLK), GPIO 8 (CE0) |

Python libraries: UART → `pyserial`, I2C → `smbus2`, SPI → `spidev`

---

**Q4. Write a Python code to blink an LED on GPIO 17 (BCM).**
```python
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)

for _ in range(5):
    GPIO.output(17, GPIO.HIGH)
    time.sleep(1)
    GPIO.output(17, GPIO.LOW)
    time.sleep(1)

GPIO.cleanup()
```

---

**Q5. What is Wokwi? How is it useful?**
**Wokwi** (wokwi.com) is a free browser-based IoT simulator for Arduino, ESP32, and Raspberry Pi. Build circuits and run Python/C++ code without physical hardware — useful for learning, testing, and classroom demonstrations.

---

**Q6. What is the OWASP IoT Top 10? Name the first three vulnerabilities.**
**OWASP (Open Web Application Security Project)** IoT Top 10 — most critical IoT security risks:
1. Weak, guessable, or hardcoded passwords
2. Insecure network services
3. Insecure ecosystem interfaces (APIs, cloud, mobile)

---

**Q7. What is the STRIDE threat model? Expand the acronym.**
- **S** — Spoofing (pretending to be someone else)
- **T** — Tampering (modifying data)
- **R** — Repudiation (denying an action)
- **I** — Information Disclosure (data leak)
- **D** — Denial of Service
- **E** — Elevation of Privilege

---

**Q8. What is the Layered Attacker Model in IoT security?**
The **Layered Attacker Model** classifies attackers based on which OSI layer they attack:
1. **Physical Layer** — tampering with hardware, cloning devices
2. **Data Link Layer** — jamming, eavesdropping on wireless links
3. **Network Layer** — IP spoofing, routing attacks
4. **Transport Layer** — TCP/UDP flooding
5. **Application Layer** — software exploits, malware injection
6. **Cross-layer** — combined attacks targeting multiple layers simultaneously

Understanding this model helps apply the right security control at each layer.

---

**Q9. What is Secure Message Communication in IoT? Name the key properties.**
Secure message communication ensures that data exchanged between IoT devices is protected:
1. **Confidentiality** — encryption prevents unauthorised reading (AES, TLS)
2. **Integrity** — message hash (HMAC) ensures data is not altered in transit
3. **Non-repudiation** — digital signatures prove who sent the message
4. **Availability** — protection against DoS attacks to keep the channel open

Protocols used: **TLS/DTLS** (for IP-based IoT), **MQTT with TLS**, **CoAP with DTLS**

---

**Q10. Describe the 4-Layer Smart City Architecture and Fog vs Cloud Computing.**
Smart City layers:
1. **Street Layer** — sensors, cameras, meters collect raw data
2. **City Layer** — Wi-Fi, 4G/5G, fibre transmits data
3. **Data Center Layer** — cloud/fog servers store and process data
4. **Services Layer** — citizen apps: traffic, parking, alerts

**Fog Computing** — processes data near the device (edge), low latency, real-time decisions.
**Cloud Computing** — processes in remote data centres, high capacity, used for big data analytics.

---

*End of Viva Question Bank | PEMRT525 | JECC | MR 2K24 S5*
