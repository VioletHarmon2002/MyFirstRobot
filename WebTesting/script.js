// const canvas = document.getElementById('myCanvas');
// const ctx = canvas.getContext('2d');
// let isDragging = false;
// let dragOffsetX, dragOffsetY;

const draggable_objects = Array.from(document.querySelectorAll('.draggable'));
// let active_drag_element;
// function mouseHoverOver(index) {
//     console.log('Mouse is hovering over element: ' + index);
//     active_drag_element = draggable_objects[index];
// }
// function mouseHoverOut(index) {
//     console.log('Mouse is hovering out element: ' + index);
//     active_drag_element = null;
// }

// for (let i = 0; i < draggable_objects.length; i++) {
//     const element = draggable_objects[i];
//     element.addEventListener('mouseover', () => {
//         mouseHoverOver(i);
//     });
//     element.addEventListener('mouseout', () => {
//         mouseHoverOut(i);
//     });
// }
// canvas.addEventListener('mousemove', (e) => {
//     console.log(isDragging);
//     if (isDragging) {
//         const mouseX = e.clientX - canvas.getBoundingClientRect().left;
//         const mouseY = e.clientY - canvas.getBoundingClientRect().top;
//         const canvasRect = canvas.getBoundingClientRect();
//         let newX = mouseX - dragOffsetX;
//         let newY = mouseY - dragOffsetY;
//         newX = Math.min(canvasRect.width - active_drag_element.offsetWidth, Math.max(0, newX));
//         newY = Math.min(canvasRect.height - active_drag_element.offsetHeight, Math.max(0, newY));
        
//         active_drag_element.style.left = newX + 'px';
//         active_drag_element.style.top = newY + 'px';
//     }
// });

// canvas.addEventListener('mousedown', () => {
//     isDragging = true;
// });
// canvas.addEventListener('mouseup', () => {
//     isDragging = false;
// });

for (let i = 0; i < draggable_objects.length; i++) {
    let element = draggable_objects[i];
    dragElement(element);
}

const canvas = document.getElementById('draggable-container')
const CANVAS_WIDTH = 500;
const CANVAS_HEIGHT = 300;

canvas.style.width = CANVAS_WIDTH + 'px';
canvas.style.height = CANVAS_HEIGHT + 'px';
function dragElement(elmnt) {
    var pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;
      elmnt.onmousedown = dragMouseDown;
    
  
    function dragMouseDown(e) {
      e = e || window.event;
      e.preventDefault();
      // get the mouse cursor position at startup:
      pos3 = e.clientX;
      pos4 = e.clientY;
      document.onmouseup = closeDragElement;
      // call a function whenever the cursor moves:
      document.onmousemove = elementDrag;
    }
  
    function elementDrag(e) {
      e = e || window.event;
      e.preventDefault();
      // calculate the new cursor position:
      pos1 = pos3 - e.clientX;
      pos2 = pos4 - e.clientY;
      pos3 = e.clientX;
      pos4 = e.clientY;

      element_width = 180;
      element_height = 100;

      
      let newX = (elmnt.offsetTop - pos2);
      let newY = (elmnt.offsetLeft - pos1);
      console.log(newX + " " + newY)
      if(newX < 0 || newX >= CANVAS_HEIGHT - element_height || newY < 0 || newY >= CANVAS_WIDTH - element_width) {
        //console.log("NEE")
        //closeDragElement();

      } else {
        elmnt.style.top = newX + "px";
        elmnt.style.left = newY + "px";
      }

      //console.log((elmnt.offsetTop - pos2) + "px" + " " + (elmnt.offsetLeft - pos1) + "px");
      // set the element's new position: 
    }
  
    function closeDragElement() {
      // stop moving when mouse button is released:
      document.onmouseup = null;
      document.onmousemove = null;
    }
  }