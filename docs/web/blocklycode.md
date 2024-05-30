# Main code for the blockly dragging
Blockly is the library we use for making draggable blocks that can be used to program the robot. In this file we will be explaining the code and how to add to it.

Blockly uses a workspace for the program and a toolbox for creating new blocks. When clicking the 'showCode' button or the play button the code will be retrieved from the workspace. This code will then be excecuted by the website  using the javascrip `eval` function.

### This is the code for initializing the blockly widget:
```javascript
function showCodeOutside() {
  // Generate JavaScript code, display it and run it.
  Blockly.JavaScript.INFINITE_LOOP_TRAP = null;
  code = Blockly.JavaScript.workspaceToCode(workspace);
  formatCode();
  code_display_element.innerHTML = formattedCode;
  readCode();
}

// Main initialization
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
```
The code here adds the workspace div to the page, and sets a function `showCodeOutside` that can be excecuted from other spaces on the javascript page.
The theme here is applied to Halloween, a set preset that we can later ajust. We just use halloween so that we have a preset which is necessary.

Before the code is displayed by the showCode function, it is first formatted by the formatCode function. This function goes as follows.
```javascript
function formatCode(){
  formattedCode = code;
  formattedCode = formattedCode.replace(/({|})/g, '$1<br>');
  formattedCode = formattedCode.replace(/;/g, ';<br>');
}
```
This code uses regex to add brakes to the displayed code. 

### This is the HTML code for the blockly container
```html
<div id="blocklyDiv" class="blocklyContainer" style="height: 80vh; width: 70%;"></div>
        <xml id="toolbox" style="display: none">
            <block type="move"></block>
            <block type="turn"></block>
            <block type="controls_if"></block>
            <block type="logic_compare"></block>
            <block type="math_number"></block>
            <block type="math_arithmetic"></block>
            <block type="text"></block>
            <block type="print"></block>
        </xml>
```
Here only the toolbox blocks are added, the later workspace is injected by the javascript code. This is also where you further add more custom code blocks.

### This is where the theme is located
in the javascript code is the theme of the blockly widget defined
```javascript
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
```

### Adding custom code blocks
Adding code blocks is explained in the [addingcodeblocks.md](addingblock.md)
