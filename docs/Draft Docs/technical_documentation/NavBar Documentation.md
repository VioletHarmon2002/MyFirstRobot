# Overview

This script dynamically loads a navigation bar into the webpage and sets the active link based on the current page. It ensures that the correct nav link is highlighted, providing a visual to the user about their current location within the website


# Code breakdown

**Event Listener** : `document.addEventListener("DOMContentLoaded", function ()`


**Fetch NavBar.html**: 
```
fetch('NavBar.html')
.then(response => response.text())
.then(data => { document.getElementById('navbar').innerHTML = data;
```

- This fetches the `NavBar.html` file.
- Converts the response to text
- Inserts the fetched file's content into the element with the ID `navbar`


**Determine the current page**

With this code `const currentPage = window.location.pathname.split("/").pop();` The current page's filename is fetched from the URL

**Map pages to link ID's**

```
const pageToLinkMap = {
    "arrows.html": "robot-controls-link",
    "blocky.html": "block-editor-link",
    "connect.html": "connect-robot-link",
};
```

Then we get the active Link ID using this line

`const activeLinkId = pageToLinkMap[currentPage];`

Then we use the current pag'es filename to get the link ID from the `pageToLinkMap`

**Set the active link**

With this code we set the active link

```javascript
if (activeLinkId) {
    const activeLink = document.getElementById(activeLinkId);
    if (activeLink) {
        activeLink.classList.add("active");
    }
}
```


**Error Handling**

With this line we handle the errors incase the link doesn't exist

`.catch(error => console.error('Error loading navbar:', error));`

# Navigation Buttons to Nav Bar [#144]
The navigation buttons have been replaced with a responsive top navigation bar for seamless navigation across pages. The existing NavBarLoader functionality has been retained to dynamically highlight the current page.

**For Developers**
Changes Made:

1. HTML:  
Added a <nav> element with structured navigation links inside an unordered list (<ul>).

````
<nav id="navbar">
    <ul class="nav-list">
        <li><a href="arrows.html" id="robot-controls-link" class="nav-link">Robot Controls</a></li>
        <li><a href="blocky.html" id="block-editor-link" class="nav-link">Block Editor</a></li>
        <li><a href="connect.html" id="connect-robot-link" class="nav-link">Connect</a></li>
    </ul>
</nav>
````

2. CSS:  
Styled the navbar for a horizontal layout with hover effects, active link indicators, and responsive design for smaller screens.

````
.nav-list { list-style: none; display: flex; gap: 24px; }
.nav-link:hover { color: var(--color-sweet); }
.active { border-bottom: 2px solid var(--color-sweet); }
````

**For Users**  
- Improved Navigation: The navigation bar is fixed at the top for easy access across all pages.  
- Interactive Design: Hover effects and active link highlighting enhance usability.  
- Responsive Layout: Adapts seamlessly to various screen sizes for a consistent experience.