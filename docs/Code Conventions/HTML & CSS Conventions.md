# HTML Conventions

1. **HTML Structure**
    - Properly nest elements.
    - Indent child elements with 2 spaces to show hierarchy.
    - Close all void elements (e.g., `<br />`, `<img />`) for consistency.

2. **Lowercase Tags and Attributes**
    - Always use lowercase for tag and attribute names.
    - Example: `<div class="example-class"></div>`

3. **Attribute Quotes**
    - Always use double quotes for attributes.
    - Example: `<input type="text" placeholder="Enter your name">`

4. **Meaningful Element Names**
    - Use semantic elements (`<header>`, `<footer>`, `<article>`, etc.) wherever possible.
    - Example: 
    ```HTML
    <main>
        <section>
            <h1>Welcome</h1>
        </section>
    </main>
    ```


    # CSS Conventions

1. **Selectors**
    - Keep selectors short, meaningful, and lowercase.
    - Avoid deeply nested selectors (limit nesting to 2 levels if possible).

2. **Naming Classes and ID's**
    - Use `kebab-case` for class and ID names.
    - Example: `.button-primary {color: #fff;}`

3. **Formatting Rules**
    - Write one declaration per line, and seperate rule blocks with a black line.
    - Indent rules with 2 spaces.
    - Example: 
    ```CSS
    .example-class {
        background-color: #f4f4f4;
        color: #333;
    }

    .another-class {
        margin: 10px 0;
    }
    ```

4. **Avoid Inline Styles**
    - Define all styles in external stylesheets to maintain separation of concerns.

    **For more info please visit the page down below, these are the most important conventions for our project that are taken out of this page.**

    [HTML & CSS Code conventions](https://google.github.io/styleguide/htmlcssguide.html#HTML_Style_Rules)