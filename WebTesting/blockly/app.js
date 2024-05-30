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

Blockly.common.defineBlocksWithJsonArray([
    {
      "type": "play_sound",
      "message0": "Play %1",
      "args0": [
        {
          "type": "field_dropdown",
          "name": "VALUE",
          "options": [
            ["C4", "sounds/c4.m4a"],
            ["D4", "sounds/d4.m4a"],
            ["E4", "sounds/e4.m4a"],
            ["F4", "sounds/f4.m4a"],
            ["G4", "sounds/g4.m4a"]
          ]
        }
      ],
      "previousStatement": null,
      "nextStatement": null,
      "colour": 355
    }
  ]);
