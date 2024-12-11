void dance() {
  // Define dance movement parameters
  const int forwardAngle = 40;  // Angle to move the leg forward
  const int backwardAngle = 40;  // Angle to move the leg backward
  const int sideShiftAngle = 10;  // Angle to shift the robot's weight to one side
  const int stepDelay = 300;  // Delay between steps in milliseconds

  unsigned long startTime = millis();  // Record the start time of the dance

  // Dance for 10 seconds or until a new command is received
  while (currentCommand == "dance" && millis() - startTime < 10000) {
    // Step 1: Shift weight to the right
    FL.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);

    // Lift front left leg and rear right leg, and move them forward/backward respectively
    FL.write(DEFAULT_POS - forwardAngle);
    RR.write(DEFAULT_POS + backwardAngle);
    delay(stepDelay);

    // Lower the legs
    FL.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS);
    delay(stepDelay);

    // Return weight to center
    FL.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    delay(stepDelay);

    // Step 2: Shift weight to the left
    FR.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);

    // Lift front right leg and rear left leg, and move them forward/backward respectively
    FR.write(DEFAULT_POS - forwardAngle);
    RL.write(DEFAULT_POS + backwardAngle);
    delay(stepDelay);

    // Lower the legs
    FR.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS);
    delay(stepDelay);

    // Return weight to center
    FR.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(stepDelay);

    // Step 3: Shift weight to the right
    FL.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);

    // Lift front left leg and rear right leg, and move them backward/forward respectively
    FL.write(DEFAULT_POS + backwardAngle);
    RR.write(DEFAULT_POS - forwardAngle);
    delay(stepDelay);

    // Lower the legs
    FL.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS);
    delay(stepDelay);

    // Return weight to center
    FL.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    delay(stepDelay);

    // Step 4: Shift weight to the left
    FR.write(DEFAULT_POS + sideShiftAngle);
    RR.write(DEFAULT_POS + sideShiftAngle);
    delay(stepDelay);

    // Lift front right leg and rear left leg, and move them backward/forward respectively
    FR.write(DEFAULT_POS + backwardAngle);
    RL.write(DEFAULT_POS - forwardAngle);
    delay(stepDelay);

    // Lower the legs
    FR.write(DEFAULT_POS + sideShiftAngle);
    RL.write(DEFAULT_POS);
    delay(stepDelay);

    // Return weight to center
    FR.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(stepDelay);
  }

  // Stop the movement and return all legs to the default position
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
}

void moveToStartPosition() {
  // Move servos from 0 to 180 degrees in steps of 5
  for (int angle = 0; angle <= 180; angle += 5) {
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(50);
  }
}

void lieDown() {
  Serial.println("Lying down");
  // Move legs to lying down position
  FL.write(PRESET_FL_LIE);
  FR.write(PRESET_FR_LIE);
  RL.write(PRESET_RL_LIE);
  RR.write(PRESET_RR_LIE);
}

void sit() {
  Serial.println("Sitting down");
  int sitPosition[] = {110, 70, 35, 145};
  // Move legs to sitting position
   FL.write(sitPosition[0]);
   FR.write(sitPosition[1]);
   RL.write(sitPosition[2]);
   RR.write(sitPosition[3]);
}

void wave() {
  // Perform waving motion three times
  for (int i = 0; i < 3; i++) {
    Serial.println("Waving");
    FL.write(WAVE_UP);
    delay(500);
    FL.write(WAVE_DOWN);
    delay(500);
  }
  FL.write(DEFAULT_POS); // Return the leg to the default position after waving
}



void turnRight() {
  Serial.println("Turning right");
  unsigned long startTime = millis();  // Record start time

  // Turn right for 5 seconds
  while (millis() - startTime < 5000) {
    // Adjust the servo positions for turning right
    FL.write(TURN_RIGHT_FL);
    FR.write(TURN_RIGHT_FR);
    RL.write(TURN_RIGHT_RL);
    RR.write(TURN_RIGHT_RR);
    delay(TURN_DELAY);

    // Move back to the default position smoothly
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(TURN_DELAY);
  }

  // Ensure all servos return to default position at the end of the turn
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  delay(WALK_DELAY);
}

void turnLeft() {
  Serial.println("Turning left");
  unsigned long startTime = millis();  // Record start time

  // Turn left for 5 seconds
  while (millis() - startTime < 5000) {
    // Adjust the servo positions for turning left
    FL.write(TURN_LEFT_FL);
    FR.write(TURN_LEFT_FR);
    RL.write(TURN_LEFT_RL);
    RR.write(TURN_LEFT_RR);
    delay(TURN_DELAY);

    // Move back to the default position smoothly
    FL.write(DEFAULT_POS);
    FR.write(DEFAULT_POS);
    RL.write(DEFAULT_POS);
    RR.write(DEFAULT_POS);
    delay(TURN_DELAY);
  }

  // Ensure all servos return to default position at the end of the turn
  FL.write(DEFAULT_POS);
  FR.write(DEFAULT_POS);
  RL.write(DEFAULT_POS);
  RR.write(DEFAULT_POS);
  delay(WALK_DELAY);
}



void handleCommand(String command) {
  switch (getCommand(command)) {
    case FORWARD:
      movement.walkForward();
      break;
    case BACKWARD:
      movement.walkBackward();
      break;
    // case LEFT:
    //   turnLeft();
    //   break;
    // case RIGHT:
    //   turnRight();
    //   break;
    // case SIT:
    //   sit();
    //   break;
    // case LIE:
    //   lieDown();
    //   break;
    // case WAVE:
    //   wave();
    //   break;
    // case DANCE:
    //   dance();
    //   break;
    // case START:
    //   moveToStartPosition();
    //   break;
    case UNKNOWN:
      Serial.println("Unknown command");
      break;
  }
}