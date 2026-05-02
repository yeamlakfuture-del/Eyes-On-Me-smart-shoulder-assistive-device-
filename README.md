# Eyes-On-Me-smart-shoulder-assistive-device-

# Smart Shoulder Assistive Device (Haptic Navigation Aid)

## Overview of EyesOnMe

This project is a wearable assistive device designed to help visually impaired individuals detect obstacles in front of them. It is worn around the shoulders to provide a wider and higher field of detection while being confortable and easy to use compared to traditional tools.

Instead of using sound, the device uses **vibration (haptic feedback)** to alert the user. This makes the system more private, less disruptive, and more comfortable in public environments.

---

##  Problem that happens to many visually impaired individuals

Many visually impaired individuals rely on canes or assistance to navigate. While helpful, these tools may not detect obstacles at upper body level (such as walls, signs, or objects at chest/head height).

Additionally, sound-based alert systems can be distracting or uncomfortable for both the user and people nearby.

---

##  Solution

This project provides a **wearable, shoulder-mounted obstacle detection system** that:

* Detects obstacles in real time using an ultrasonic sensor
* Uses vibration instead of sound for alerts
* Provides intuitive feedback based on distance
* Is simple, affordable, and easy to build

---

##  How It Works

1. The ultrasonic sensor continuously measures the distance to objects in front of the user.
2. The Arduino processes this data.
3. Based on the distance, the system responds with vibration:

* **Far (>120 cm)** → No vibration
* **Medium (80–120 cm)** → Pulsing vibration
* **Close (<40-80 cm)** → Continuous vibration

4. The user can react accordingly to avoid obstacles.

---

##  Components (BOM)

| Component                   | Quantity | Source            |
| --------------------------- | -------- | ----------------- |
| Arduino (Uno or compatible) | 1        | School            |
| Ultrasonic Sensor (HC-SR04) | 1        | School            |
| Cylindrical vibration motor | 1        | Purchase          |
| Jumper Wires                | Multiple | School            |
| Breadboard                  | 1        | School            |
| Power Source (USB)          | 1        | purchase          |

---

##  Wiring

Typical connections:

 Ultrasonic Sensor (HC-SR04)
   VCC → 5V (Arduino)
   GND → GND (Arduino)
   TRIG → Digital Pin 9
   ECHO → Digital Pin 10
 
(See `/hardware/` folder for diagram)

 Cylindrical Vibration Motor (CVM)

The CVM is connected through a transistor driver circuit because it requires more current than an Arduino digital pin can safely supply.

Connections:
 CVM (+) → +5V external supply (or Arduino 5V if low load testing)
 CVM (–) → Collector of NPN transistor (e.g., 2N2222)
 Emitter of transistor → GND
 Base of transistor → Digital Pin 8 (through 1kΩ resistor)

Power System
 Arduino is powered via USB or USB power bank
 CVM is powered from 5V supply but controlled via transistor switching
 All grounds (Arduino GND and motor GND) must be connected together (common ground)

##  Firmware

The Arduino code reads distance from the ultrasonic sensor and controls the vibration motor based on proximity.

* Located in `/code/main.ino`
* Uses simple distance thresholds
* Designed for real-time feedback

---

##  How to Use

1. Power the device using USB.
2. Wear the device around your shoulders with the sensor facing forward.
3. Walk normally.
4. Feel the vibration feedback:

   * No vibration → safe
   * Pulsing → caution
   * Continuous → obstacle very close

---

##  Design

* The system is mounted on a shoulder strap.
* The ultrasonic sensor is positioned facing forward.
* The vibration motor is placed where the user can feel it clearly (shoulder).
* Components are securely attached using a stable structure (not loose wiring).

(See `/images/` and `/hardware/` for visuals)

---

##  Future Improvements

* Add multiple sensors for left/right detection
* Improve wearable design with custom casing
* Add voice feedback as an optional feature
* Integrate wireless connectivity (ESP32)
* Add AI-based assistance features

---

##  Why I Built This

I wanted to create somethig affordable and a mini companion to visually impaired people giving the independence and allow them to maneuver from one place to another. This project focuses on practical usability by using vibration instead of sound, making it more suitable for real-world environments.
And this passion was driven from my school, I had a friend that is visually impaired and was not able to go from one place to another and he was allways bumping with walls and poles. So i thought if i was able to give a solution for all blind people and my friend

---

##  Current Status

This project is currently in the prototyping stage. The core system (ultrasonic sensor + vibration feedback) is being developed and tested before adding advanced features.

---

##  Author

Name: Yeamlak Fekadu
Age: 14
Country: Ethiopia
Grade: 8

---
