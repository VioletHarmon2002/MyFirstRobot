// const canvas = document.getElementById('myCanvas');
// const ctx = canvas.getContext('2d');
// let isDragging = false;
// let dragOffsetX, dragOffsetY;
var create_draggable_buttons = Array.from(document.querySelectorAll('.create-draggable-button'));
var draggable_objects = Array.from(document.querySelectorAll('.draggable'));
const scale = 50;

function addListNumbers(n){
  const list_element = document.querySelector('#list');
  for(var i = 0; i < n; i++){
    var item = document.createElement("p");
    item.className = "list-item";
    item.textContent = i + 1;
    list_element.appendChild(item);
  }
}
addListNumbers(10);

function clampToNearestScale(number) {
  return Math.round(number / scale) * scale;
}

function loadDraggables(){
    draggable_objects = Array.from(document.querySelectorAll('.draggable-parent'));
    
    
    for (let i = 0; i < draggable_objects.length; i++) {
        let element = draggable_objects[i];
        dragElement(element);
        console.log(element);
    }
  }
  
  function createDraggableDiv(id, topPosition, type) {
  // Create the outer div
  var div = document.createElement("div");
  div.id = id;
  div.className = "draggable-parent";
  div.style.left = "300px";
  
  // Create the inner div
  var innerDiv = document.createElement("div");
  
  div.appendChild(innerDiv);
  parentDiv = document.querySelector("#draggable-container");
  parentDiv.appendChild(div);

  if(type == 'forward'){
    innerDiv.className = "draggable-button forward";
    innerDiv.textContent = "forward (s):";
    
    var inputElement = document.createElement("input");
    inputElement.classList.add('input', 'forward-input');
    inputElement.setAttribute('type', 'number');
    div.appendChild(inputElement);
  } 
  else if(type == 'wait'){
    innerDiv.className = "draggable-button wait";
    innerDiv.textContent = "wait (s):";
  
    var inputElement = document.createElement("input");
    inputElement.classList.add('input', 'forward-input');
    inputElement.setAttribute('type', 'number');
    div.appendChild(inputElement);
  }
  else if(type == 'turn'){
    innerDiv.className = "draggable-button turn";
    innerDiv.textContent = "turn (degrees):";
  
    var inputElement = document.createElement("input");
    inputElement.classList.add('input', 'forward-input');
    inputElement.setAttribute('type', 'number');
    div.appendChild(inputElement);
  }
  else if(type == 'move'){
    innerDiv.className = "draggable-button move";
    innerDiv.textContent = "move to step (index):";
  
    var inputElement = document.createElement("input");
    inputElement.classList.add('input', 'forward-input');
    inputElement.setAttribute('type', 'number');
    div.appendChild(inputElement);
  }
  

  // Append the inner div to the outer div
  loadDraggables();
}

function loadCreateDraggables(){
  const create_draggable_buttons = Array.from(document.querySelectorAll('.create-draggable-button'));
  for (let i = 0; i < create_draggable_buttons.length; i++) {
    let element = create_draggable_buttons[i];
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
  const moveDiv = elmnt.getElementsByClassName('draggable-button');
  moveDiv[0].onmousedown = dragMouseDown;

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
      newY = clampToNearestScale(newY);
         elmnt.style.top = newY + "px";  
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
      // elmnt.style.top = newY + "px";
      elmnt.style.top = newY + "px";
      elmnt.style.left = newX + "px";
    }

    //console.log((elmnt.offsetTop - pos2) + "px" + " " + (elmnt.offsetLeft - pos1) + "px");
    // set the element's new position: 
  }
  
  }