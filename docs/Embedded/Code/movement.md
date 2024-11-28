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
