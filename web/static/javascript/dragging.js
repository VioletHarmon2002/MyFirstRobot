// const canvas = document.getElementById('myCanvas');
// const ctx = canvas.getContext('2d');
// let isDragging = false;
// let dragOffsetX, dragOffsetY;
const canvas = document.getElementById('draggable-container')
const CANVAS_WIDTH = 500;
const CANVAS_HEIGHT = 800;
const NODE_HEIGHT = 70;

canvas.style.width = CANVAS_WIDTH + 'px';
canvas.style.height = CANVAS_HEIGHT + 'px';

//Changeable draggable area, normally set to canvas width and height.
const DRAGGABLE_BORDER_X_MIN = 0;
const DRAGGABLE_BORDER_X_MAX = CANVAS_WIDTH;
const DRAGGABLE_BORDER_Y_MIN = 0;
const DRAGGABLE_BORDER_Y_MAX = CANVAS_HEIGHT;

// Scale for the finding of the index
const scale = NODE_HEIGHT ;

var create_draggable_buttons = Array.from(document.querySelectorAll('.create-draggable-button'));
var draggable_objects = Array.from(document.querySelectorAll('.draggable'));
var commands_array = {};
addListNumbers(10);

// Function for adding list numbers to the draggable container
function addListNumbers(n){
  const list_element = document.querySelector('#list');
  for(var i = 0; i < n; i++){
    var item = document.createElement("p");
    item.className = "list-item";
    item.textContent = i + 1;
    item.style.top = i*NODE_HEIGHT + "px";
    list_element.appendChild(item);
  }
}

// Functioin for clamping to the nearest number on the scale, example: on a scale of 20, the number 41 would clamp to 40
function clampToNearestScale(number) {
  return Math.round(number / scale) * scale;
}

// Adds draggable functionality to every element with the draggable-parent class
function loadDraggables(){
  draggable_objects = Array.from(document.querySelectorAll('.draggable-parent'));
  for (let i = 0; i < draggable_objects.length; i++) {
    let element = draggable_objects[i];
    dragElement(element);
    console.log(element);
  }
}

// Adds creation of draggable divs functionality to the create draggable button class
function loadCreateDraggables(){
  const create_draggable_buttons = Array.from(document.querySelectorAll('.create-draggable-button'));
  for (let i = 0; i < create_draggable_buttons.length; i++) {
    let element = create_draggable_buttons[i];
  }
}

function createDraggableDiv(id, topPosition, type) {
  // Create the outer div
  var div = document.createElement("div");
  div.id = id;
  div.className = "draggable-parent";
  div.style.left = "20px";
  
  // Create the inner div
  var innerDiv = document.createElement("div");
  div.appendChild(innerDiv);

  // Find parent/constainer div
  parentDiv = document.querySelector("#draggable-container");
  parentDiv.appendChild(div);

  // Set it so that when the input is updated, the value is also updated in the commands_array
  var inputElement = document.createElement("input");
  inputElement.addEventListener("change", function(e) {
    let index = findIndexInList(div);
    setNodeInArray(index, div.id, inputElement.value);
  })

  // Check what type is set, and add the correct values accordingly
  if(type == 'forward'){
    innerDiv.className = "draggable-button forward";
    innerDiv.textContent = "forward:";
    
    inputElement.classList.add('input', 'forward-input');
    inputElement.setAttribute('type', 'number');
    div.appendChild(inputElement);
  } 
  else if(type == 'wait'){
    innerDiv.className = "draggable-button wait";
    innerDiv.textContent = "wait:";
  
    inputElement.classList.add('input', 'forward-input');
    inputElement.setAttribute('type', 'number');
    div.appendChild(inputElement);
  }
  else if(type == 'turn'){
    innerDiv.className = "draggable-button turn";
    innerDiv.textContent = "turn:";
  
    inputElement.classList.add('input', 'forward-input');
    inputElement.setAttribute('type', 'number');
    div.appendChild(inputElement);
  }
  else if(type == 'move'){
    innerDiv.className = "draggable-button move";
    innerDiv.textContent = "move to step:";
  
    inputElement.classList.add('input', 'forward-input');
    inputElement.setAttribute('type', 'number');
    div.appendChild(inputElement);
  }
  else if (type == 'animation') {
    innerDiv.className = "draggable-button animation";
    innerDiv.textContent = "do animation:";

    // List of possible animations. Add to this array the additional animations.
    const animationOptions = [
      { value: 'wave', text: 'wave' },
      { value: 'sit', text: 'sit'}
    ]
    var inputElement = document.createElement("select");
    inputElement.setAttribute('id', 'animationDropdown');
    inputElement.setAttribute('name', 'animationDropdown');
    inputElement.classList.add('input', 'forward-input');
    // Required to prevent the block from dragging when you want to use the menu.
    inputElement.addEventListener('mousedown',function(event){
      event.stopPropagation();
    })
    // Loop through the options array and create option elements for the list
    animationOptions.forEach(option => {
      const optionElement = document.createElement('option');
      optionElement.setAttribute('value', option.value);
      optionElement.textContent = option.text;
      inputElement.appendChild(optionElement);
    });

    innerDiv.appendChild(inputElement);
    }
  

  // Reload the draggable divs/add functionality
  loadDraggables();
}

// Upload program to robot
function uploadProgram(){
  console.log(commands_array);
  
}

loadDraggables();
loadCreateDraggables();

// Set the correct command into the commands_array
function setNodeInArray(index, type, value) {
  commands_array[index] = [type, value];
}

// Finds the index of a draggable block by the height of the element
function findIndexInList(elmnt){
  let index = 0;
  let y = clampToNearestScale(elmnt.offsetTop);
  index = elmnt.offsetTop / NODE_HEIGHT;
  return index;
}

// Main function for making a element draggable
function dragElement(elmnt) {
  var pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0; // Init values
  const moveDiv = elmnt.getElementsByClassName('draggable-button'); // Find the part of the element that when clicked, drags the entire element

  const inputElement = elmnt.getElementsByClassName('input')[0]; // Find the element that holds the input value
  moveDiv[0].onmousedown = dragMouseDown;

  function snapToLeftSide(targetDiv){
    if (!targetDiv || !targetDiv.getBoundingClientRect) {
      console.error("Invalid closestDiv.");
      return;
    }
    targetDiv.style.left = "20px";
  }
    
  let newY = 0;
  function dragMouseDown(e) {
    e = e || window.event;
    e.preventDefault();
    // get the mouse cursor position at startup:
    pos3 = e.clientX;
    pos4 = e.clientY;
    document.onmouseup = closeDragElement; // call a function when the mouse is let go
    document.onmousemove = elementDrag; // call a function whenever the cursor moves:

    function closeDragElement() {
      // stop moving when mouse button is released:
      document.onmouseup = null;
      document.onmousemove = null;
      newY = clampToNearestScale(newY); // clamp to nearest value on the scale, this adds the snapping functionality
      elmnt.style.top = newY + "px";  // Set according height
      const index = newY / NODE_HEIGHT; 
      const input = inputElement.value;
      setNodeInArray(index, elmnt.id, input); // Set command same as the block in the commands_array
      snapToLeftSide(elmnt); // Snaps the element to the left side
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
    
    newY = (elmnt.offsetTop - pos2); // Calculate new Y position
    let newX = (elmnt.offsetLeft - pos1); // Calculate new X position

    // Calculate if the new position fits inside the draggable area
    if(newY < DRAGGABLE_BORDER_Y_MIN || newY >= DRAGGABLE_BORDER_Y_MAX || newX < DRAGGABLE_BORDER_X_MIN || newX >= DRAGGABLE_BORDER_X_MAX) {
    } else {
      elmnt.style.top = newY + "px";
      elmnt.style.left = newX + "px";
    }
  }
}