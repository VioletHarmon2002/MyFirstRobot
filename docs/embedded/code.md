# Code

 @brief Makes the robot dog wave.
 
 This function makes the robot dog wave by moving its front leg up and down in a waving motion.
 It prints "Hallo!" to the serial monitor and performs the waving motion three times.
 Each wave consists of moving the leg down, adding a delay for a visible wave, moving the leg up, and adding another delay.
  
 @note This function assumes that the Serial and FL (front leg) objects have been properly initialized.
 

```cpp
void wave() {
    Serial.print("Hallo!");
    for (int i = 0; i < 3; i++) {
        FL.write(WAVE_DOWN);
        delay(500); // Add delay for a visible wave
        FL.write(WAVE_UP);
        delay(500); // Add delay for a visible wave
    }
    FL.write(90);
}
```