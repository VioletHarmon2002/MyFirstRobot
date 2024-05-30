# Application code

## Code blocks

### Animation block

````js
  const animationOptions = [
      { value: 'wave', text: 'wave' },
    ]
````
This list consist out of all the animation options which you can select from the draggable block. To add another animation option, you only need to add it to this array and everything will work perfect.

````js
    inputElement.addEventListener('mousedown',function(event){
      event.stopPropagation();
    })
````
This event listener is needed to use the drop down list in the draggable block. Otherwise you will drag the block instead of seeing your other possible animations.

