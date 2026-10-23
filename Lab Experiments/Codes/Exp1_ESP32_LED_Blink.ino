// Experiment 1: Blinking of LED using ESP32 Microcontroller
// PEMRT525 IoT & Applications Lab | JECC | S5 MR 2K24

#define LED_PIN 2   // GPIO2

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configure GPIO2 as digital output
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED ON  (3.3 V)
  delay(500);                   // Wait 500 ms
  digitalWrite(LED_PIN, LOW);   // LED OFF (0 V)
  delay(500);                   // Wait 500 ms
}
