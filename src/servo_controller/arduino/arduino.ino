#include <Servo.h>
Servo myServo;

void setup() {
  Serial.begin(115200);
  myServo.attach(3);
}

void loop() {
  if (Serial.available()) {
    int angle = Serial.parseInt();
    myServo.write(constrain(angle, 0, 180));
  }
}