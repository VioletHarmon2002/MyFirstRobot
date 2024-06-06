#include <ESP32Servo.h>

// Define the pins for the servos
#define SERVO_FL_PIN 18  // Front left leg servo pin
#define SERVO_RL_PIN 16  // Rear left leg servo pin
#define SERVO_FR_PIN 17  // Front right leg servo pin
#define SERVO_RR_PIN 5   // Rear right leg servo pin


#define DEFAULT_POS 90
#define WALK_OFFSET 30
#define WALK_DELAY 1000

// Create servo objects
Servo FL; // Front left leg
Servo FR; // Front right leg
Servo RL; // Rear left leg
Servo RR; // Rear right leg

void moveToStartPos() {
  FR.write(120);
  RR.write(70);
  FL.write(90);
  RL.write(70);
}

void leftStep() {
  FR.write(90);
  delay(100);
  FL.write(60);
  delay(300);
  RL.write(110);
  delay(100);
  RR.write(120);
}

void rightStep() {
  FL.write(90);
  delay(100);
  FR.write(120);
  delay(300);
  RR.write(70);
  delay(100);
  RL.write(60);
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Attach servos to pins
  FL.attach(SERVO_FL_PIN);
  FR.attach(SERVO_FR_PIN);
  RL.attach(SERVO_RL_PIN);
  RR.attach(SERVO_RR_PIN);

  // Move servos to initial position (optional)
  FL.write(70);
  FR.write(110);
  RL.write(110);
  RR.write(70);

  delay(4000);

  moveToStartPos();
}

void loop() {
  leftStep();
  delay(300);
  rightStep();
  delay(300);

}