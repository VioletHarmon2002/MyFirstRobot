Learning journal for elizaveta

---
sidebar_label: 'Elizaveta'
sidebar_position: 1
---

# Learning Story: Implementing the Fall Right Function and Mastering GitLab

## What needs to be learned
- How to implement servo control for robot movement.
- How to design a flexible function.
- How to use GitLab for version control, collaboration, and project management.

## What I've learned
In our robot dog project, one important functionality was making the dog fall to its right side. This task provided a great opportunity to enhance both my programming skills and my ability to collaborate using GitLab. I have gained some exeprience with embedded coding during this task.

### Step 1: Understanding Servo Control
The first step was understanding how to control servo motors with the ESP32Servo library. I learned that each servo motor's angle could be set from 0 to 180 degrees, allowing me to determine the necessary angles to position each leg for a controlled fall.

### Step 2: Designing the Function
I created the `fallRight` function, which accepts four Servo objects as references.

### Step 3: Testing
Using `Serial.println()` helped me track function execution,

## GitLab Workflow

### Step 1: Creating Issues
Before coding, I created an issue in our GitLab repository. The issue detailed the need for a "fall right" function. For issue I ahve creted accepatnce criterias and DoD.

### Step 2: Working with Branches
A new branch was created for this task. Working in a separate branch helped me isolate my changes from the main project.

### Step 3: Committing Changes
As I developed the `fall_right.h` file, I made commits with descriptive messages. I learned the importance of commit messages in maintaining an organized project history.

### Step 4: Creating a Merge Request
After completing and testing the feature, I created a merge request in GitLab. This process helped me present my changes to the team for review. I learned to write clear descriptions.

### Step 5: Code Review and Collaboration
Through the merge request, I received feedback from my team members. This experience showed me the benefits of peer review in catching potential issues, so the code can be improved or changed.

### Step 6: Merging and Closing the Issue
Once the changes were approved, I merged my branch into the main branch. I also learned to close the issue in GitLab.

## Conclusion
Implementing the `fall_right.h` file not only enhanced the functionality of our robot dog but also improved my embedded programming and GitLab collaboration skills.

# Learning Story: Creating a bitmap 


## What needs to be learned
- How to create a bitmap.
- How to use it in a code.
- How to use .

## What I've learned
I have learned how to 

### Step 1: Changing the size of the image 

I have found a nice picture from google, but it is needed to be resized, so the first thing I have done is found a simpe bitmap tool, so i can put new width and height.

### Step 2: Converting the bmf file into actual  

For the converting my file into the i was using some tools. 

### Step 3: Implementing my code into Header file    




## **Learning Question**
How can the PlatformIO extension in Visual Studio Code be utilized to test the robot dog’s components effectively?

## **Goal** 
The goal of this learning story is to understand how to use the PlatformIO extension in Visual Studio Code for assembling and testing a robot dog. The process involves setting up a PlatformIO project, putting code to control hardware components and testing.

## **Key steps of using the platform**
1. Install PlatformIO Extension: I have downloaded it from Extension section in VsCode.
2. Create a New Project: A new separate PlatformIO project was being created for the robot dog, we have copied and pasted src folder into the new folder. By creating a new project, it is possible  to specify and manage the required libraries.
I have learnt, that it is helpful to isolate my work from other projects. This isolation helps prevent conflicts between different sets of code and configurations, making it easier to manage and maintain the codebase.
3. Put the Code: i have put the code from the existing files i had for embedded part of the project.
4. Integrate Libraries: a few libraries were needed to be downloaded, so i just downloaded them straightly from "Libraries" section in PlatformIO.


## **Benefits of using the platform**
I have detected some benefits of using this extension:

Efficiency: PlatformIO automates many aspects of the development process, reducing the need for manual configuration and saving time.
Improved Debugging: With integrated debugging and a serial monitor, I can quickly detect and resolve issues with the robot dog's functionality.
Simplified Workflow: The PlatformIO extension streamlines the process of writing, testing, compiling, and uploading code, making the development cycle faster and more efficient.
Version Control: PlatformIO helps in maintaining and managing different versions of the firmware, enabling easy rollbacks and testing of changes.

## **Testing the Robot Dog with PlatformIO**

### **Step 1: Install Required Libraries**
To streamline development, all necessary libraries for the robot dog’s functionalities (e.g., ESP32Servo, Adafruit GFX, WiFiManager, ArduinoJson) were installed using the Libraries window in PlatformIO. This ensures that the code dependencies are managed effectively and automatically linked during compilation.

### **Step 2: Creating, compiling and uplading the code **

1. PlatformIO is being  used in Visual Studio Code to compile and upload the test script to  Arduino board. It can be done by clicking the "Upload" button in the PlatformIO toolbar or using the command palette. Printed messages can be observed in serial monitor.

### **Step 3: Example of testing the function **

#include <Arduino.h>
#include "movement/movement.h"

// Define the pins for the servos
const int flPin = 9;  // Front Left
const int frPin = 10; // Front Right
const int rlPin = 11; // Rear Left
const int rrPin = 12; // Rear Right

Movement robotMovement(flPin, frPin, rlPin, rrPin);

void setup() {
    Serial.begin(9600);
    robotMovement.initServos();
}

void loop() {
    Serial.println("Testing Walk Forward");
    robotMovement.walkForward();
    delay(2000);

    Serial.println("Testing Walk Backward");
    robotMovement.walkBackward();
    delay(2000);

    Serial.println("Stopping Servos");
    robotMovement.stopServos();
    delay(2000);
}


## ** Troubleshhoting **

If the servos do not behave as expected, the pin connections can be checked and ensure the servo library is correctly included and configured. 


# Learning Story: Creating a 3D Pyramid Face Using Laser Cutting

## Learning Question
I want to learn how to create a 3D face, which steps should be implemented and study the laser techniques.

So the first step, of course, is to come up with the plan of creating small tasks for every section.

## Tasks
1. **Research and Planning**
   - Study existing 3D pyramid designs and their applications.
   - Identify suitable materials for the face.
   - Review laser cutting techniques.



**Techniques**
1. Vector Cutting
- **What it is**: A process where the laser follows a path (vector line) to cut through the material completely.
- **Use Cases**: Creating shapes, parts, or intricate designs that need to be separated from the material.
- **Materials**: Wood, acrylic, cardboard, leather, and thin metals.
- **Tips**: 
  - Ensure lines in your design are hairline-thin for accurate cuts.
  - Optimize cutting paths to reduce time and material waste.
  - Use appropriate power and speed settings for clean edges.

2. Raster Engraving
- **What it is**: The laser scans back and forth (like a printer) to remove the surface of the material in a pattern or design.
- **Use Cases**: Adding details, logos, or decorative textures to the material’s surface.
- **Materials**: Wood, acrylic, leather, and coated metals.
- **Tips**:
  - Use high-resolution images for fine details.
  - Adjust power and speed to control the depth of engraving.
  - Test on scrap material to avoid overburning

3. Scoring
- **What it is**: A shallow cut into the surface without cutting all the way through.
- **Use Cases**: Adding fold lines, light decorative marks, or assembly guides.
- **Materials**: Paper, cardboard, and thin sheets of plastic or wood.
- **Tips**: 
  - Use lower power settings to avoid cutting through.
  - Score lines can help with precise bending or folding.




2. **Design**
   - Use CAD software (e.g., AutoCAD, Fusion 360) to create a 2D layout for the pyramid faces.
   - Include slots, tabs, or hinges for easy assembly.
   - Design space for securely mounting the OLED display inside the pyramid.

3. **Prototyping**
   - Create a cardboard prototype using the design.
   - Assemble the prototype to test fit and dimensions.
   - Adjust the design based on findings from the prototype.

4. **Assembly and Integration**
   - Assemble the laser-cut pyramid faces using glue or fasteners.
   - Mount the OLED display inside the pyramid.
   - Ensure visibility of facial expressions through the pyramid's opening.
   - Attach the pyramid face securely to the robot dog's head.















