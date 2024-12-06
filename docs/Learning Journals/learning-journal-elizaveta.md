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
- How to create a bitmap from an image.
- How to use the bitmap in code.
- How to implement the bitmap into a header file.

## What I've learned
I have learned how to create and manipulate bitmap images, convert them into C++ header files. So now Ia capable of having a better understand working with graphical data, using appropriate tools, and organizing code efficiently.

### Step 1: Changing the Size of the Image

I found a suitable image for the bitmap on Google. However, I needed to resize the image to fit the desired dimensions for the dog's face display. To do this, I used a simple bitmap tool that allowed me to input the new width and height.

### Step 2: Converting the bmf file into actual  

To convert the image into a usable bitmap, I used an online tool called ["image2cpp"](https://www.image2cpp.com/). This tool converted the image file into a C++ header file containing the bitmap data. I chose this tool because it provided the output in a format that was easy to integrate into the project's existing codebase.

### Step 3: Implementing my code into Header file

Implementing the Bitmap into the Header File
Once I had the bitmap data in a C++ header file, I integrated it into the project's existing codebase. I added the necessary code to display the bitmap on the dog's face display

Throughout this process, I learned the importance of understanding the project's existing codebase and how to integrate new features seamlessly. I also gained a better understanding of the display's capabilities and how to work with bitmap data to create various face expressions for our robot dog.

## Conclusion
Creating bitmaps for the robot dog's face expressions was a valuable learning experience for me. I improved my skills in working with images, converting them into usable bitmaps, and integrating them into a C++ codebase. I also learned the importance of understanding the project's existing codebase and how to integrate new features seamlessly.




















