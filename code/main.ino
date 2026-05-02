// Smart Shoulder Assistive Device
// Ultrasonic Sensor + Vibration Motor

#include "config.h"

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long distance = getDistance();

  Serial.println(distance);

  // SAFE ZONE
  if (distance > SAFE_DISTANCE) {
    digitalWrite(MOTOR_PIN, LOW);
  }

  // WARNING ZONE (slow vibration)
  else if (distance > WARNING_DISTANCE) {
    slowVibration();
  }

  // CAUTION ZONE (medium vibration)
  else if (distance > DANGER_DISTANCE) {
    mediumVibration();
  }

  // DANGER ZONE (strong vibration)
  else {
    digitalWrite(MOTOR_PIN, HIGH);
  }
}

// ---------------- FUNCTIONS ----------------

long getDistance() {
  long duration;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void slowVibration() {
  digitalWrite(MOTOR_PIN, HIGH);
  delay(200);
  digitalWrite(MOTOR_PIN, LOW);
  delay(400);
}

void mediumVibration() {
  digitalWrite(MOTOR_PIN, HIGH);
  delay(150);
  digitalWrite(MOTOR_PIN, LOW);
  delay(150);
}
