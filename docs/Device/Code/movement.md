# Robot Movement
### Walking Function Refactoring  
I implemented the forward-walking functionality for the robot and documented the progress in [User Story #114](https://gitlab.fdmci.hva.nl/IoT/2024-2025-semester-1/group-project/poonuugaaqii15/-/issues/114).

#### Key Changes:
- **Modular Design:**  
  - Extracted the `walkForward` function from the main file to a separate header file to improve code organization and readability.  
  - Created a dedicated **`walking.h`** file to encapsulate walking-related functions.

#### Benefits:
- **Clean Codebase:** The main file is now more concise and focused.  
- **Future Expansion:** The `walking.h` file provides a reusable structure for implementing additional walking movements.
---



### Issues Encountered and Fixes Implemented

#### 1. **Incorrect Use of `switch` with Strings**
- **Issue:**  
  The function `getCommand` attempted to use a `switch` statement with `String` objects, which is not supported in C++.
  
  ```cpp
  Command getCommand(const String& command) {
    switch(command) {  // Error: switch cannot be used with strings.
      case "forward":
        return FORWARD;
      // ...
    }
  }
  ```
  
- **Solution:**  
  Replace the `switch` statement with a series of `if-else` conditions or use a `std::map` for cleaner implementation.

  **Updated Code Example:**  
  ```cpp
  Command getCommand(const String& command) {
    if (command == "forward") return FORWARD;
    else if (command == "backward") return BACKWARD;
    // ... other conditions
    else return UNKNOWN;
  }
  ```

#### 2. **Duplicate Command Check**
- **Issue:**  
  The `"dance"` command was repeated in the conditional statement, which could lead to redundancy and confusion:
  
  ```cpp
  } else if (command == "forward" || command == "backward" || command == "dance" || command == "dance") {
  ```

- **Solution:**  
  Remove the duplicate `"dance"` condition to simplify and avoid redundancy.

  **Corrected Code Example:**  
  ```cpp
  } else if (command == "forward" || command == "backward" || command == "dance") {
  ```

#### **Key Takeaways:**
- **C++ Limitations:** Remember that `switch` statements do not support strings; use `if-else` or lookup structures instead.
- **Code Review:** Always review conditional statements for duplicate checks to ensure efficiency and clarity.

---  

### Laying Down Function Refactoring
I implemented the lieDown function so that the robot can lay down: [User Story #106](https://gitlab.fdmci.hva.nl/IoT/2024-2025-semester-1/group-project/poonuugaaqii15/-/issues/106).

#### For Developers
The lieDown function is placed in a separate header file (lieDown.h) for maintainability and reusability. Separating this functionality from the main file makes the codebase more organized and easier to modify. By storing the servo angles in an array, the function is both readable and simple to adjust.

**How It Works:**

The lieDown function accepts four servo objects representing the legs of the robot:  

- Front Left (FL)
- Front Right (FR)
- Rear Left (RL)
- Rear Right (RR)

The predefined servo positions for the lying-down motion are stored in the lieDownPositions array:  
{0, 180, 180, 0}.  

These correspond to specific angles for each leg:  

- 0° for the Front Left leg
- 180° for the Front Right leg
- 180° for the Rear Left leg
- 0° for the Rear Right leg

When the function is called, each servo is commanded to move to the assigned angle using the write method.

#### For End Users
The lieDown function allows the robot to smoothly transition into a lying-down position. This motion should be visually natural, with each leg moving to a predefined angle.

**How It Works:**

- Upon activating the "lie down" command, the robot's legs are adjusted via its servo motors to specific angles.  
- The motion ensures that the robot adopts a stable and balanced lying posture.

**Key Features:**

- The function ensures smooth movement of the robot.
- Predefined positions make the movement accurate and repeatable.
- The design is efficient, enabling reliable execution of the lying-down motion.

### Sit Function
The sit() function is designed to move the servos of the robot to predefined positions that simulate a sitting posture. It is part of the Movement class and works with initialized servo motors to adjust the robot's legs accordingly.

#### For Developers  
**How it Works:** The function writes specific angles to each servo based on predefined "sit" positions stored in an array:

````
int sitPosition[] = {110, 70, 35, 145}; // Angles for FL, FR, RL, RR servos
````

These values correspond to the optimal configuration for a sitting position.

**Function Details:**

````
void sit();
````

- Location: Defined in movement.cpp.  
- Access: Public method in the Movement class.  
- Purpose: Moves the robot into a seated position by writing specific angles to each leg servo.

#### For End Users  
**What it Does:** Transitions the robot into a sitting position by moving its legs to predefined angles.  
**When to Use:** Use this function when you want the robot to adopt a seated posture for resting or stabilization. The movement can be controlled via the web application when the "sit" command is pressed. The robot dog will then follow the instruction.