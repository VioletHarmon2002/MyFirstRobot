const HVA_DARK_COLOR = '#28147C'
const HVA_LIGHT_COLOR = '#381CB4'
const forward_color = "#1b97b3";
const turn_color = "#16c548";


let running;

const play_button = document.getElementById("play-btn");
const pause_button = document.getElementById("pause-btn");

pause();
let code;
let formattedCode;

function readCode(){
  try{ 
    eval(code);
  } catch(e){
    console.error(e);
  }
}

function play(){
  console.log("play");
  play_button.style.display = "none";
  pause_button.style.display = "block";
  showCodeOutside();
  running = true;
  
}

function pause(){
  console.log("pause");
  pause_button.style.display = "none";
  play_button.style.display = "block";
  running = false;
}

function formatCode(){
  formattedCode = code;
  formattedCode = formattedCode.replace(/({|})/g, '$1<br>');
  formattedCode = formattedCode.replace(/;/g, ';<br>');
  return formatCode;
}

// x
// BASIC BLOCKLY CODE
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

function showCodeOutside() {
  // Generate JavaScript code and display it.
  Blockly.JavaScript.INFINITE_LOOP_TRAP = null;
  code = Blockly.JavaScript.workspaceToCode(workspace);
  formatCode(code);
  code_display_element.innerHTML = formattedCode;
  readCode();
}

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
          ["Forwards", "forwards"],
          ["Backwards", "backwards"]
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
  let value = '\'' + block.getFieldValue('NUMBER') + '\'';
  let direction = '\'' + block.getFieldValue('DIRECTION') + '\'';
  return 'robot.move(' + direction + ', ' + value +');\n';
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
  let value = '\'' + block.getFieldValue('text') + '\'';
  return 'console.log(' + value +');\n';
};

// Turn block
Blockly.common.defineBlocksWithJsonArray([
  {
    "type": "turn",
    "message0": "turn %1 degrees",
    "args0": [
      {
        "type": "field_number",
        "name": "NUMBER",
        "value": 0,
        "min": -180,
        "max": 180,
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": turn_color
  }
]);

javascript.javascriptGenerator.forBlock['turn'] = function(block) {
  let value = '\'' + block.getFieldValue('NUMBER') + '\'';
  return 'robot.turn(' + value +');\n';
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
          ["wave","wave"],
          ["sit","sit"]
        ]
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": 200
  }
]);

javascript.javascriptGenerator.forBlock['play_animation'] = function(block) {
  let value = '\'' + block.getFieldValue('animationInQuestion') + '\'';
  return 'robot.animate(' + value +');\n';
};
