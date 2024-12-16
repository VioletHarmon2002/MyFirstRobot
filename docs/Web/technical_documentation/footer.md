### For Developers

The footer is responsive and changes layout based on screen size. On smaller screen sizes, the different sections will be placed underneath each other instead of next to each other horizontally. It has styling (colours, fonts, font sizing, animations) that is consistent with the rest of the website. All of the animations are done with CSS and consist of having a lower border that shifts to the right when hovering over a link.

The lower border is created using the `::after` tag, by default it is hidden with `opacity: 0;`, but it becomes visible when hovering over the link. The CSS animation is done with the following styling rules:

```    
-webkit-transition: opacity .2s ease-in-out, left .2s ease-in-out;
transition: opacity .2s ease-in-out, left .2s ease-in-out;
```

They are animations that last 200 milliseconds to unhide the `::after` content and to shift it to the right. The full styling for the `::after` looks like this:

```
.navigation-link::after, .social-link span::after {
    content: "";
    position: absolute;
    left: 0;
    bottom: -2px;
    border-bottom: 1px solid;
    width: calc(100% - 4px);
    opacity: 0;
    -webkit-transition: opacity .2s ease-in-out, left .2s ease-in-out;
    transition: opacity .2s ease-in-out, left .2s ease-in-out;
}
```

It uses `position: absolute;` to be positioned independently from the link it belongs to and calculates it width by grabbing the width of the link and reducing it by 4 pixels.

The social media links have SVG icons to improve scalability and to allow them to change colour when hovering over them. It would also be possible to achieve this using images, but that would be less easy to change because you would need the original image and then also have extra images for each different colour that you would want to change to.

Another option would be to get the social media icons using an icon font like Bootstrap Icons or Font Awesome. This would also allow easy animation and should be considered when using more icons. For this project we only use a handful of icons, so it was unnecessary to add an entire font for just this feature.


### For End Users

The footer is made to be as close to the footer on the official AUAS website as possible. The content and links of the footer match the official one at the time of writing. This is done for consistency, to improve user experience and to increase recognisability.