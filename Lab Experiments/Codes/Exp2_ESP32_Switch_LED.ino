// Experiment 2: Interfacing Push Button Switch with ESP32 for LED Control
// PEMRT525 IoT & Applications Lab | JECC | S5 MR 2K24

#define LED_PIN    2   // GPIO2 - output
#define BUTTON_PIN 4   // GPIO4 - input

void setup() {
  pinMode(LED_PIN,    OUTPUT);       // LED as output
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Enable internal pull-up
}

void loop() {
  int btnState = digitalRead(BUTTON_PIN);

  if (btnState == LOW) {           // Button pressed (pulled to GND)
    digitalWrite(LED_PIN, HIGH);   // LED ON
  } else {
    digitalWrite(LED_PIN, LOW);    // LED OFF
  }
}
