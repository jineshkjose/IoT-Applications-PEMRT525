# Important Questions — Topics Overview
**PEMRT525 — Internet of Things & Applications**  
Module 1 & Module 2 | KTU S5 | MR 2K24 | JECC

---

## MODULE 1 — IoT Fundamentals

### Part A — Short Answer (3 Marks each)

#### Q1 · IoT Definition & Characteristics
- Definition of IoT with key terms: *physical objects, sensors, internet, no human intervention*
- Any **2 characteristics** with a one-line description each:
  - Connectivity — every device connects to a network to send/receive data
  - Sensing — sensors measure physical parameters from the real world
  - Intelligence — devices process data locally to filter and act
  - Heterogeneity — different hardware, OS, and protocols work together
  - Dynamic Nature — devices join/leave/update without manual intervention
  - Enormous Scale — billions of devices need scalable cloud infrastructure
  - Safety & Security — protects physical safety and data integrity

#### Q2 · 4-Layer IoT Architecture
- **Layer 1 — Perception Layer**: Sensors, actuators, RFID, cameras — collect raw physical data
- **Layer 2 — Network Layer**: Wi-Fi, 3G/4G/5G, ZigBee, LoRaWAN — transmit data
- **Layer 3 — Middleware Layer**: Cloud computing, databases, analytics — store and process
- **Layer 4 — Application Layer**: Smart home, healthcare, smart city apps — deliver to users
- Data flow: Physical World → Perception → Network → Middleware → Application

#### Q3 · Publish-Subscribe Model & MQTT
- **3 Roles**:
  1. Publisher — generates data, sends to broker under a topic
  2. Broker — central server routing messages by topic (e.g., Mosquitto)
  3. Subscriber — registers for a topic, receives all matching messages
- **Protocol**: MQTT (Message Queuing Telemetry Transport)
- **Advantage over Request-Response**: Decoupling & one-to-many scalability — publishers and subscribers do not know each other; one message reaches thousands of subscribers

#### Q4 · IoT Security Functional Block (Cross-Cutting Concern)
- **Responsible block**: Security functional block
- **Functions**: Authentication, Encryption (AES-128, TLS), Data Integrity
- **Cross-cutting** = must be applied at ALL layers simultaneously:
  - Device level — secure boot, device authentication
  - Communication level — TLS/DTLS encryption in transit
  - Services level — authorisation for cloud service access
  - Management level — signed firmware OTA updates
  - Application level — API key management, RBAC

---

### Part B — Long Answer (9 Marks each)

#### Q1 · Bahga & Madisetti IoT Deployment Levels
| Level | Description | Example |
|-------|-------------|---------|
| 1 | Single device, all local, no cloud | Standalone smart thermostat |
| 2 | Multiple sensors, local gateway, local analysis only | Single smart home |
| 3 | Multi-node, cloud storage + analytics | Single smart office building |
| 4 | Multi-node, **multiple sites**, full cloud analytics + control | **Campus energy monitoring** |
| 5 | Multiple IoT systems coordinated via cloud | Smart city subsystems |
| 6 | Multiple organisations sharing IoT platforms | National smart grid |

**Selected for multi-building campus energy monitoring: Level 4**  
Justification: multiple buildings = multiple sites, cloud analytics for energy patterns, central dashboard for all buildings, bi-directional remote control of HVAC/lighting, single organisation (not Level 5/6).

#### Q2 · Four IoT Communication Models
| Model | Mechanism | Protocol | IoT Example |
|-------|-----------|----------|-------------|
| Request-Response | Client → Server → Client (synchronous, stateless) | HTTP, CoAP | Smart controller querying weather API |
| Publish-Subscribe | Publisher → Broker → Subscriber (async, decoupled) | MQTT, AMQP | Factory sensors → MQTT broker → dashboard |
| Push-Pull | Producer → Queue → Consumer (async, buffered) | Kafka, ZeroMQ | 1000 sensors → Kafka queue → analytics |
| Exclusive Pair | Persistent full-duplex bidirectional | WebSocket | Real-time patient monitoring dashboard |

**Key comparison points**: sync/async, coupling (tight/loose), protocol, polling needed, best use case.

---

## MODULE 2 — M2M, Smart Objects & WSNs

### Part A — Short Answer (3 Marks each)

#### Q1 · M2M Definition & Gateway Role
- **M2M**: Networking of machines for remote monitoring, control, and data exchange *without human intervention*
- **M2M Gateway roles**:
  - Protocol translation — non-IP (Modbus, RS-485) → IP (TCP/IP)
  - Data aggregation — bundles multiple node readings into fewer transmissions
  - Local pre-processing — filters invalid/duplicate data
  - WAN connectivity — connects via 4G/GPRS to backend server
- **Example**: 10 electricity meters → Modbus/RS-485 → Gateway → 4G GPRS → Utility server

#### Q2 · Sensor Classification (3 Criteria)
| Criterion | Sub-types | Sensor Example | IoT Application |
|-----------|-----------|----------------|-----------------|
| Relationship with environment | Invasive / Non-invasive | CGM (invasive); IR thermometer (non-invasive) | Smart healthcare; building access |
| Physical contact | Contact / Non-contact | Thermocouple (contact); Ultrasonic (non-contact) | Machine health; smart parking |
| Physical quantity measured | Temperature / Motion / Gas / Humidity / Pressure etc. | LM35; PIR; MQ-2; DHT22 | Cold chain; security; gas safety; agriculture |

#### Q3 · Smart Object — 4 Components
| Component | Function | Examples |
|-----------|----------|---------|
| Sensor / Actuator | Interface with physical world — measure & respond | Temperature sensor, solenoid valve |
| Processor (MCU/SoC) | Brain — process data, run algorithms, decide | Arduino, ESP32, ARM Cortex-M |
| Communication Hardware | Connect to network — exchange data | Wi-Fi module, ZigBee radio, LoRa |
| Power Source | Energy supply | Battery, solar panel, USB mains |

**How "smart" is created**: Closed-loop cycle — Sense → Process → Communicate → Act. All 4 components together enable autonomous operation without human intervention.

**Mnemonic**: S-P-C-P

#### Q4 · WSN Deployment Criteria — Smart Agriculture
| Criterion | Agriculture Requirement |
|-----------|------------------------|
| Range | Fields span hectares — sub-GHz (LoRaWAN 2–5 km) or ZigBee mesh needed |
| Power consumption | Remote battery nodes must last months/years — deep sleep, duty cycling |
| Topology | Mesh for large fields — extends range via relay, self-heals if nodes damaged |
| Data rate | Tiny packets (10–50 bytes per reading) — 250 kbps is more than sufficient |
| Constrained devices | Class 0/1 nodes (small RAM/flash) — ZigBee, 6LoWPAN compatible |
| Environmental resilience | IP65/IP67 rated — rain, dust, heat, animals, machinery |
| Cost | 100–1000 nodes — per-node cost must be low (<$5 for 802.15.4 modules) |

---

### Part B — Long Answer (9 Marks each)

#### Q1 · WSN Architecture + FFD/RFD + 6 Design Constraints

**WSN Architecture** (draw labelled diagram):
- Sensor Nodes (Motes/RFD) → Cluster Heads (FFD) → Base Station/Sink → Internet

**FFD vs RFD Comparison**:
| Feature | FFD — Full Function Device | RFD — Reduced Function Device |
|---------|---------------------------|-------------------------------|
| Stack | Complete IEEE 802.15.4 | Subset only |
| Roles | Coordinator, Router, End Device | End Device (leaf) only |
| Can coordinate? | Yes | No |
| Can relay data? | Yes | No |
| Communicates with | FFDs and RFDs | Only its coordinator (FFD) |
| Power | Mains-powered / large battery | Always battery; deep sleep |
| WSN role | Base station, cluster head | Sensor node |

**6 Design Constraints** and how they are addressed:
| Constraint | Data Aggregation solution | Self-Organisation solution |
|------------|--------------------------|---------------------------|
| Limited Energy | 100 nodes → 1 aggregated packet → 99% fewer transmissions | Duty cycling; rotating cluster-head role to balance drain |
| Limited Processing | Simple average/max/min functions — trivial for MCU | Lightweight LEACH-type protocols designed for small MCUs |
| Limited Memory | Only summaries buffered, not all raw readings | Compact routing state tables fit constrained RAM |
| Limited Bandwidth | 98% bandwidth reduction after aggregation | Efficient routing trees minimise hop count |
| Small Physical Size | RFD only needs short range to cluster head | Mesh multi-hop — short antenna range is sufficient |
| Harsh Environment | Cluster head backup if one fails | Self-healing re-routes around failed nodes automatically |

#### Q2 · WSN Protocol Stack + Hospital Technology Selection

**Protocol Stack** (draw table):
| Layer | IEEE 802.15.4 | ZigBee | ZigBee IP / 6LoWPAN |
|-------|--------------|--------|----------------------|
| Application | — | ZigBee Profiles (HA, SE), ZDO | CoAP, Smart Energy 2.0, DTLS |
| App Support | — | APS (binding, group addressing) | — |
| Network | — | ZigBee NWK (AODV mesh routing) | IPv6 + UDP + RPL |
| Adaptation | — | — | 6LoWPAN (IPv6 header compression + fragmentation) |
| MAC | CSMA/CA, 4 frame types (Data/ACK/Beacon/Command), AES-128 optional | Same | Same |
| PHY | 2.4 GHz (16 ch, 250 kbps); 915 MHz (40 kbps); 868 MHz (20 kbps) — DSSS | Same | Same |

**Key 6LoWPAN functions**: (1) Compresses IPv6 headers 40 bytes → 2 bytes, (2) Fragments large packets to fit 127-byte 802.15.4 frames, (3) Supports mesh addressing.

**5 Criteria → Technology Selection for Smart Hospital**:
| Criterion | Hospital Requirement | ZigBee Result |
|-----------|---------------------|--------------|
| Range | Room-to-room, multi-ward coverage | ✅ 10–100 m/hop; mesh extends across floors |
| Power | Wearable sensors run 24+ hrs on small battery | ✅ Ultra-low power; µA sleep current |
| Latency/Reliability | Life-critical alerts in seconds; near-zero packet loss | ✅ ACK-based guaranteed delivery; 10–30 ms/hop |
| Topology | Complex hospital layout with walls and obstacles | ✅ Mesh self-heals around obstacles and failed nodes |
| Data Rate | Tiny vital signs packets (10 bytes/30 s per patient) | ✅ 250 kbps >> 2.7 bps/patient needed |

**Selected: IEEE 802.15.4 / ZigBee mesh**

**Why alternatives are less suitable**:
- Wi-Fi — too high power; drains wearable battery in hours
- LoRaWAN — higher latency; star topology (no self-healing); outdoor design
- Bluetooth LE — limited range (10–30 m); star topology; not scalable for wards
- NB-IoT — high latency; needs cellular infra inside hospital; not real-time

---

## Quick Reference — All 12 Questions

| Module | Part | Q | Marks | Topic | Key Terms |
|--------|------|---|-------|-------|-----------|
| Mod 1 | A | 1 | 3 | IoT definition + 2 characteristics | Network, things, sensors, connectivity, sensing |
| Mod 1 | A | 2 | 3 | 4-layer IoT architecture | Perception, Network, Middleware, Application |
| Mod 1 | A | 3 | 3 | Publish-Subscribe + MQTT | Publisher, Broker, Subscriber, MQTT, decoupling |
| Mod 1 | A | 4 | 3 | Security block (cross-cutting) | Authentication, encryption, integrity, all layers |
| Mod 1 | B | 1 | 9 | Deployment levels + campus system | Level 1–4, Level 4 for campus, cloud analytics |
| Mod 1 | B | 2 | 9 | 4 communication models + table | Request-Response, Pub-Sub, Push-Pull, Exclusive Pair |
| Mod 2 | A | 1 | 3 | M2M + gateway role | M2M def, protocol translation, non-IP to IP |
| Mod 2 | A | 2 | 3 | Sensor classification (3 criteria) | Invasive/non-invasive, contact/non-contact, by quantity |
| Mod 2 | A | 3 | 3 | Smart object 4 components | Sensor, Processor, Communication, Power, S-P-C-P |
| Mod 2 | A | 4 | 3 | WSN criteria for agriculture | Range, Power, Topology, Data rate, Cost, Environment |
| Mod 2 | B | 1 | 9 | WSN architecture + FFD/RFD + constraints | Diagram, FFD/RFD table, 6 constraints, aggregation, self-org |
| Mod 2 | B | 2 | 9 | Protocol stack + hospital selection | 802.15.4 PHY/MAC, ZigBee, 6LoWPAN, 5 criteria, ZigBee ✅ |

---

*PEMRT525 | Mechatronics Engineering | Jyothi Engineering College | KTU S5 MR 2K24*
