const forward_color = "#1b97b3";
const turn_color = "#16c548";

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
document.addEventListener("DOMContentLoaded", function() {
    var workspace = Blockly.inject('blocklyDiv', {
        toolbox: document.getElementById('toolbox'),
        theme: Blockly.Themes.Halloween,
    });

    function showCode() {
        // Generate JavaScript code and display it.
        Blockly.JavaScript.INFINITE_LOOP_TRAP = null;
        var code = Blockly.JavaScript.workspaceToCode(workspace);
        alert(code);
    }

    // Optionally, you can add a button to show generated code
    var button = document.createElement('button');
    button.innerText = 'Show Code';
    button.onclick = showCode;
    
    document.body.appendChild(button);
});


// ADD BLOCKS HERE
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
