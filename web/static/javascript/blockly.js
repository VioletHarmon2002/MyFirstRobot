const HVA_DARK_COLOR = '#28147C'
const HVA_LIGHT_COLOR = '#381CB4'
const forward_color = "#1b97b3";
const turn_color = "#16c548";
const IP_ADRESS = '192.168.137.103';

let running;

const play_button = document.getElementById("play-btn");
const pause_button = document.getElementById("pause-btn");

pause();

let code;
let formattedCode;

// Function for reading the code in async, so we can wait with javascript
function readCode(){
  try{ 
    eval(`(async () => { 
      ${code} 
    })();`);
  } catch(e){
    console.error(e);
  }
}

// Plays the machine and displays it on the page
function play(){
  console.log("play");
  play_button.style.display = "none";
  pause_button.style.display = "block";
  showCodeOutside();
  running = true;
}

// Pauses the machine and displays it on the page
function pause(){
  console.log("pause");
  pause_button.style.display = "none";
  play_button.style.display = "block";
  running = false;
}

// This sleep function makes a new promise so that the program wait x amount of seconds before continuing
function sleep(seconds) {
  return new Promise(resolve => setTimeout(resolve, seconds * 1000));
}

// This function formats the code so that its better displayed on the web page, this is not for function, purely for esthetics
function formatCode(){
  formattedCode = code;
  formattedCode = formattedCode.replace(/({|})/g, '$1<br>');
  formattedCode = formattedCode.replace(/;/g, ';<br>');
  return formatCode;
}

// Function for moving forward or backward, its async since that is needed to use sleep functions
async function forward(dir, n){
  if(dir == "forward"){
    for(var i=0; i<n; i++){
      sendCommandBlock('forward');
      await sleep(1);
    }
  } else {
    for(var i=0; i<n; i++){
      sendCommandBlock("backward");
      await sleep(1);
    }
  }
}

// THis function sends a command from a block
function sendCommandBlock(command){
  const data = {
    "command": command,
  };
  console.log("sendCommand: " + JSON.stringify(data));

  // Send the JSON message to the API
  fetch('http://192.168.137.103/api.php?action=command', {
      method: 'POST',
      headers: {
          'Content-Type': 'application/json'
      },
      body: JSON.stringify(data)
  })
  .then(response => {
      if (!response.ok) {
          throw new Error('Network response was not ok');
      }
      return response.json();
  })
  .then(data => {
      console.log('API response:', data);
  })
  .catch(error => {
      console.error('There was a problem with the fetch operation:', error);
  });
}


// BASIC BLOCKLY CODE
// This is the basic theming
Blockly.Themes.Halloween = Blockly.Theme.defineTheme('haloween', {
  'base': Blockly.Themes.Classic,
  'componentStyles': {
    'workspaceBackgroundColour': '#28147C',
    'toolboxBackgroundColour': '#381CB4',
    'toolboxForegroundColour': '#381CB4',
    'flyoutBackgroundColour': '#381CB4',
    'flyoutForegroundColour': '#ccc',
    'flyoutOpacity': 0.5,
    'scrollbarColour': '#ff0000',
    'insertionMarkerColour': '#fff',
    'insertionMarkerOpacity': 0.3,
    'scrollbarOpacity': 0.4,
    'cursorColour': '#d0d0  d0',
    'blackBackground': '#333'
  }
});

var workspace;

// Read the code, convert it, and display it
function showCodeOutside() {
  // Generate JavaScript code and display it.
  Blockly.JavaScript.INFINITE_LOOP_TRAP = null;
  code = Blockly.JavaScript.workspaceToCode(workspace);
  formatCode(code);
  code_display_element.innerHTML = formattedCode;
  readCode();
}

// Adds blockly workspace
const code_display_element = document.getElementById('code_display_element');
document.addEventListener("DOMContentLoaded", function() {
    workspace = Blockly.inject('blocklyDiv', {
        toolbox: document.getElementById('toolbox'),
        theme: Blockly.Themes.Halloween,
    });

    function showCode() {
        showCodeOutside();
    }
});


// ADD BLOCKS HERE
// Move block
Blockly.common.defineBlocksWithJsonArray([
  {
    "type": "move",
    "message0": "move %1 for %2 seconds",
    "args0": [
      {
        "type": "field_dropdown",
        "name": "DIRECTION",
        "options": [
          ["Forwards", "forward"],
          ["Backwards", "backward"]
        ]
      },
      {
        "type": "field_number",
        "name": "NUMBER",
        "value": 0,
        "min": 0,
        "max": 10,
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": forward_color
  }
]);

javascript.javascriptGenerator.forBlock['move'] = function(block) {
  let value = '\'' + block.getFieldValue('NUMBER') + '\''; // Get value from field
  let direction = '\'' + block.getFieldValue('DIRECTION') + '\''; // Get value from field
  return 'forward(' + direction + ', ' + value +');\n'; // Turn block into code returned here
};

// print block
Blockly.common.defineBlocksWithJsonArray([
  {
    "type": "print",
    "message0": "print %1",
    "args0": [
      {
        "type": "field_input",
        "name": "text",
        "check": "String"
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": 230,
    "tooltip": "",
    "helpUrl": ""
  }
]);

javascript.javascriptGenerator.forBlock['print'] = function(block) {
  let value = '\'' + block.getFieldValue('text') + '\''; // Get value from field
  return 'console.log(' + value +');\n'; // Turn block into code returned here
}; 

// Turn block
Blockly.common.defineBlocksWithJsonArray([
  {
    "type": "turn",
    "message0": "turn %1",
    "args0": [
      {
        "type": "field_dropdown",
        "name": "DIRECTION",
        "options": [
          ["Leftward", "left"],
          ["Rightward", "right"]
        ]
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": turn_color
  }
]);

javascript.javascriptGenerator.forBlock['turn'] = function(block) {
  let direction = '\'' + block.getFieldValue('DIRECTION') + '\''; // Get value from field
  return 'sendCommandBlock(' + direction +');\n'; // Turn block into code returned here
};

// Animate block
Blockly.common.defineBlocksWithJsonArray([
  {
    "type": "play_animation",
    "message0":"Do animation: %1",
    "args0": [
      {
        "type":"field_dropdown",
        "name": "animationInQuestion",
        "options": [
          ["Wave","wave"],
          ["Sit","sit"],
          ["Lay down","lie"],
          ["Dance", "dance"]
        ]
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": 200
  }
]);

javascript.javascriptGenerator.forBlock['play_animation'] = function(block) {
  let value = '\'' + block.getFieldValue('animationInQuestion') + '\''; // Get value from field
  return 'sendCommandBlock(' + value +');\n'; // Turn block into code returned here
};

// Wait block
// Turn block
Blockly.common.defineBlocksWithJsonArray([
  {
    "type": "wait",
    "message0": "wait %1 seconds",
    "args0": [
      {
        "type": "field_number",
        "name": "NUMBER",
        "value": 0,
        "min": 0,
        "max": 20,
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": turn_color
  }
]);

javascript.javascriptGenerator.forBlock['wait'] = function(block) {
  let value = '\'' + block.getFieldValue('NUMBER') + '\'';
  return 'await sleep(' + value +');\n';
};

// emote block
Blockly.common.defineBlocksWithJsonArray([
  {
    "type": "emote",
    "message0":"Do emote: %1",
    "args0": [
      {
        "type":"field_dropdown",
        "name": "emoteInQuestion",
        "options": [
          ["smile","smile"],
          ["frown","frown"],
          ["sleep","sleep"],
          ["cry","cry"]
        ]
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": 100
  }
]);

javascript.javascriptGenerator.forBlock['emote'] = function(block) {
  let value = '\'' + block.getFieldValue('NUMBER') + '\''; // Get value from field
  return 'await sleep(' + value +');\n'; // Turn block into code returned here
};
function closeFlyout(){

  document.getElementsByClassName("blocklyFlyout")[0].style.visibility = 'hidden';
  // document.getElementsByClassName("blocklyScrollbarVertical")[0].style.visibility = 'hidden';
  document.getElementById("toggleFlyout").textContent = "Open";
}

function openFlyout(){
  document.getElementsByClassName("blocklyFlyout")[0].style.visibility = 'visible';
  // document.getElementsByClassName("blocklyScrollbarVertical")[0].style.visibility = 'visible  ';
  document.getElementById("toggleFlyout").textContent = "Close";
}
