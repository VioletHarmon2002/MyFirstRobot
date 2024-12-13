Learning journal for joshua

# Tuesday 26th November 2024

Today I'm going to work on one or two userstories,
First I'm going to create a button that will allow the user to wag the tail of the dog
and secondly I'm going to work on the embedded part and rewrite some of the code to make it more efficient and readable.


Update:

I created a button in the frontend and rewrote some code in the embedded part of the device, I also used the ip constant
instead of hardcoded ip's




# Friday December 13 2024

Today I'm going to work on documentation for both my userstory and learning story, and then after that I will pick up another userstory, and I will create a learning story for linting so that we can be consistent with conventions in our project


#### Tasks for today

- Create documentation for userstory #127
- Create documentation for learning story #136
- Try and test the robot to get another robot working



#### Documentation for learning story #136

I researched google code conventions and created files for the main conventions we're going to use, as a formal question I have "What code conventions can we use as a team?" So as a team we decided to use the google code conventions. More specifically mentioned in the files `Web Conventions.md` In there I also have the link to the code conventions of google. 

The sources that I used for this learning story are as follows:

[Javascript Code conventions](https://google.github.io/styleguide/jsguide.html)

[HTML & CSS Code conventions](https://google.github.io/styleguide/htmlcssguide.html#HTML_Style_Rules)

#### Elaboration on Research
The reason I researched the google code conventions that are mentioned in the convention files is to ensure that our team follows consistent coding standards.
The main findings from my research include best practices for writing clean, readable, and maintainable code in JavaScript, HTML, and CSS. These conventions cover different parts such as naming conventions, code formatting, and documentation standards.

#### Findings

- **Javascript**: Emphasis on using `const` and `let` instead of `var`, preferring arrow functions, and following a consistent naming convention.
- **HTML & CSS**:  Guidelines for structuring HTML documents, using semantic tags, and maintaining a consistent style for CSS selectors and properties.


#### Enforcing

To ensure that these conventions are followed, we as a team will work on implementing the following measures.

- **Code reviews**: Regular code reviews will be conducted with merge requests
- **Linting Tools**: We will try to implement Linting tools such as `ESLint` for JAvascript and `stylelint` for CSS
- **Documentation**: The `Web Conventions.md` file will serve as a reference for all team members, providing detailed guidelines and examples.


By implementing these measures we will try to maintain high code quality and consistency as a team across our project