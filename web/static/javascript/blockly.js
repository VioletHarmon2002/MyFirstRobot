// BASIC BLOCKLY CODE
document.addEventListener("DOMContentLoaded", function() {
    var workspace = Blockly.inject('blocklyDiv', {
        toolbox: document.getElementById('toolbox')
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
    "colour": 355
  }
]);

javascript.javascriptGenerator.forBlock['move'] = function(block) {
  let value = '\'' + block.getFieldValue('NUMBER') + '\'';
  let direction = '\'' + block.getFieldValue('DIRECTION') + '\'';
  return 'robot.move(' + direction + ', ' + value +');\n';
};
