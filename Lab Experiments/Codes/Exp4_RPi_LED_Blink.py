# Experiment 4: Blinking of LED using Raspberry Pi GPIO
# PEMRT525 IoT & Applications Lab | JECC | S5 MR 2K24
# Run: python3 Exp4_RPi_LED_Blink.py

import RPi.GPIO as GPIO
import time

LED_PIN = 17  # BCM GPIO17 = Physical Pin 11

GPIO.setmode(GPIO.BCM)           # Use BCM pin numbering
GPIO.setup(LED_PIN, GPIO.OUT)    # Set GPIO17 as digital output

try:
    while True:
        GPIO.output(LED_PIN, GPIO.HIGH)  # LED ON  (3.3 V)
        time.sleep(0.5)
        GPIO.output(LED_PIN, GPIO.LOW)   # LED OFF (0 V)
        time.sleep(0.5)

except KeyboardInterrupt:
    print("Program stopped by user")

finally:
    GPIO.cleanup()   # Reset all GPIO pins to default state
