// const canvas = document.getElementById('myCanvas');
// const ctx = canvas.getContext('2d');
// let isDragging = false;
// let dragOffsetX, dragOffsetY;
var create_draggable_buttons = Array.from(document.querySelectorAll('.create-draggable-button'));
var draggable_objects = Array.from(document.querySelectorAll('.draggable'));
const scale = 20;

function clampToNearestScale(number) {
  return Math.round(number / scale) * scale;
}

function loadDraggables(){
    draggable_objects = Array.from(document.querySelectorAll('.draggable'));
    
    
    for (let i = 0; i < draggable_objects.length; i++) {
        let element = draggable_objects[i];
        dragElement(element);
    }
}

function createDraggableDiv(id, topPosition, type) {
  // Create the outer div
  var div = document.createElement("div");
  div.id = id;
  div.className = "draggable " + type;
  div.style.top = topPosition + "px";
  div.style.left = "300px";

  // Create the inner div
  var innerDiv = document.createElement("div");
  innerDiv.className = "draggable-button";
  innerDiv.textContent = "Forward movement";

  // Append the inner div to the outer div
  div.appendChild(innerDiv);

  parentDiv = document.querySelector("#draggable-container");
  parentDiv.appendChild(div);
  
}

function loadCreateDraggables(){
  const create_draggable_buttons = Array.from(document.querySelectorAll('.create-draggable-button'));
  for (let i = 0; i < create_draggable_buttons.length; i++) {
    let element = create_draggable_buttons[i];
    element.addEventListener('mousedown', function (e) {
        console.log("HOI");
        createDraggableDiv("hallo", 0);
        loadDraggables();
    })
}

}

loadDraggables();
loadCreateDraggables();

const canvas = document.getElementById('draggable-container')
const CANVAS_WIDTH = 500;
const CANVAS_HEIGHT = 300;

const NODE_HEIGHT = 50;

const DRAGGABLE_BORDER_X_MIN = 0;
const DRAGGABLE_BORDER_X_MAX = 500;
const DRAGGABLE_BORDER_Y_MIN = 0;
const DRAGGABLE_BORDER_Y_MAX = 300;

canvas.style.width = CANVAS_WIDTH + 'px';
canvas.style.height = CANVAS_HEIGHT + 'px';
function dragElement(elmnt) {
    var pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;
      elmnt.onmousedown = dragMouseDown;

      function getShortestDistance(targetDiv, divArray) {
        let shortestDistance = Infinity;
        let closestDiv = null;
            for (let i = 0; i < divArray.length; i++) {
            const currentDiv = divArray[i];
            const rect1 = targetDiv.getBoundingClientRect();
            const rect2 = currentDiv.getBoundingClientRect();
            const distance = Math.sqrt(
                Math.pow(rect1.left - rect2.left, 2) + Math.pow(rect1.top - rect2.top, 2)
            );
                if (distance < shortestDistance && currentDiv != targetDiv) {
                shortestDistance = distance;
                closestDiv = currentDiv;
            }
        }
        return closestDiv;
    }

    function snapToClosestDiv(targetDiv, closestDiv) {
      if (!closestDiv || !closestDiv.getBoundingClientRect) {
        console.error("Invalid closestDiv.");
        return;
    }
      const rect1 = targetDiv.getBoundingClientRect();
      const rect2 = closestDiv;
  
      const offsetX = rect2.left - rect1.left;
      const offsetY = rect2.top - rect1.top;
      
      const newX = rect2.left;
      let newY = rect2.top;
      
      targetDiv.style.top = newX + "px";
      targetDiv.style.left = newY + "px";
  }

  function snapToLeftSide(targetDiv){
    
    if (!targetDiv || !targetDiv.getBoundingClientRect) {
      console.error("Invalid closestDiv.");
      return;
    }
    targetDiv.style.left = "0px";
  }
    
  let newY = 0;
  function dragMouseDown(e) {
    e = e || window.event;
    e.preventDefault();
    // get the mouse cursor position at startup:
    pos3 = e.clientX;
    pos4 = e.clientY;
    document.onmouseup = closeDragElement;
    // call a function whenever the cursor moves:
    document.onmousemove = elementDrag;

    function closeDragElement() {
      // stop moving when mouse button is released:
      document.onmouseup = null;
      document.onmousemove = null;
      var closestDiv = getShortestDistance(elmnt, draggable_objects);
      newY = clampToNearestScale(newY);
      elmnt.style.top = newY + "px";  
      console.log(closestDiv);
      // snapToClosestDiv(elmnt, closestDiv);
      snapToLeftSide(elmnt);
    }

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

    
    newY = (elmnt.offsetTop - pos2);
    let newX = (elmnt.offsetLeft - pos1);
    console.log(newY);

    // console.log(newX + " " + newY);
    if(newY < DRAGGABLE_BORDER_Y_MIN || newY >= DRAGGABLE_BORDER_Y_MAX || newX < DRAGGABLE_BORDER_X_MIN || newX >= DRAGGABLE_BORDER_X_MAX) {
      //console.log("NEE")
      //closeDragElement();

    } else {
      elmnt.style.top = newY + "px";
      elmnt.style.left = newX + "px";
    }

    //console.log((elmnt.offsetTop - pos2) + "px" + " " + (elmnt.offsetLeft - pos1) + "px");
    // set the element's new position: 
  }
  
  }