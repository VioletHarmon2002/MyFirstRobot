Learning journal for joshua

# Tuesday 26th November 2024

Today I'm going to work on one or two userstories,
First I'm going to create a button that will allow the user to wag the tail of the dog
and secondly I'm going to work on the embedded part and rewrite some of the code to make it more efficient and readable.


Update:

I created a button in the frontend and rewrote some code in the embedded part of the device, I also used the ip constant
instead of hardcoded ip's




# Friday December 13 2024

Today I'm going to work on documentation for both my userstory and learning story, and then after that I will pick up another userstory, and I will create a learning story for linting so that we can be consistent with conventions in our project.


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

- **Code reviews**: Regular code reviews will be conducted with merge requests.
- **Linting Tools**: We will try to implement Linting tools such as `ESLint` for JAvascript and `stylelint` for CSS.
- **Documentation**: The `Web Conventions.md` file will serve as a reference for all team members, providing detailed guidelines and examples.


By implementing these measures we will try to maintain high code quality and consistency as a team across our project.



# Sunday December 15 2024

#### Learning Question

Why is implementing a linter good for our project and is it worth the time?




To answer this question I will first look at why a linter would be benefinicial for our current project.

**Benefits**

1. **Consistency**: It ensures code conventions are followed and are consistent across the entire codebase.
2. **Error Detection**: Less inconsistency means Less errors, it also helps catch syntax errors and potential bugs early in the development process.
3. **Code Quality**: It enforces the best practices and coding standards for everyone in the group, which means that it leads to higher quality code.
4. **Productivity**: It saves time by automatically checking for common issues that are known
5. **Maintainability**: And finally atlast, it makes the code easier to read and maintain by keeping a consistent style

Overall, the time that is invested in setting up and using a linter is typically worth it because of the benefits of the better and more consistent code quality and reduced debugging time.


**Which linters will we use for our project?**

Because we're using the google coding conventions, and because we have HTML, CSS and Javascript files, we are going to use the following linters:

1. **HTML**: [HTMLHint](https://htmlhint.com/)
2. **CSS**: [Stylelint](https://stylelint.io/)
3. **JavaScript**: [ESLint](https://eslint.org/)

These linters are widely used and have extensive documentation and community support. They can be easily configured to use the google coding standards that we will apply to our project which is why we will be using these.



**How Will we configure these for the google coding standards?**

Originally these linteres do not use google coding standards by default. However, we can easily configure them to use these standards.

For `ESLint(Javascript)` we will the command `npm install eslint-config-google` and then in the `.eslintrc` config file we could use a simple `"extends": "google"` to configure ESLint to use the google coding standards.

For `Stylelint(CSS)` we will use the command `npm install stylelint-config-google` then the same as our ESLint file, in the `.stylelintrc` config file we use `"extends": "google"` to use the google standards for CSS.


For `HTMLHint(HTML)` there is no official google style config, but we can manually configure the most important rules in the `.htmlhintrc` file to match Google's HTML conventions.


So in short, **is it worth it to implement a linter?** Yes, the benefits heavily outweigh the time it takes to put this up, it will help everyone be more consistent, reduce debugging time and improve code quality.