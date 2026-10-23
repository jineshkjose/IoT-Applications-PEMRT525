# Experiment 5: Interfacing Push Button Switch with Raspberry Pi for LED Control
# PEMRT525 IoT & Applications Lab | JECC | S5 MR 2K24
# Run: python3 Exp5_RPi_Switch_LED.py

import RPi.GPIO as GPIO
import time

LED_PIN    = 17  # BCM GPIO17 = Physical Pin 11
BUTTON_PIN = 18  # BCM GPIO18 = Physical Pin 12

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN,    GPIO.OUT)
GPIO.setup(BUTTON_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)  # Internal pull-up

try:
    while True:
        btn = GPIO.input(BUTTON_PIN)
        if btn == GPIO.LOW:               # Button pressed (pulled to GND)
            GPIO.output(LED_PIN, GPIO.HIGH)  # LED ON
        else:
            GPIO.output(LED_PIN, GPIO.LOW)   # LED OFF
        time.sleep(0.05)                  # 50ms debounce delay

except KeyboardInterrupt:
    print("Program stopped by user")

finally:
    GPIO.cleanup()
