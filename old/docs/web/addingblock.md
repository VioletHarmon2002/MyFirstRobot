### For adding a new block you have to do 3 things
1. Go to the html file and add a new block in the toolbox with the type you want to create, we are for example adding the move block

```html
<xml id="toolbox" style="display: none">
        <block type="move"></block>
        <block type="controls_if"></block>
        <block type="logic_compare"></block>
        <block type="math_number"></block>
        <block type="math_arithmetic"></block>
        <block type="text"></block>
    </xml>
```
2. Then add to the javascript file (`blockly.js`) at the bottom of the file a section like this:
```javascript
Blockly.common.defineBlocksWithJsonArray([
  {
    "type": "move",
    "message0": "move %1",
    "args0": [
      {
        "type": "field_dropdown",
        "name": "DIRECTION",
        "options": [
          ["Forwards", "forwards"],
          ["Backwards", "backwards"]
        ]
      }
    ],
    "previousStatement": null,
    "nextStatement": null,
    "colour": 355
  }
]);
```
Here we add a block with the type move with the direction and time. For adding a new block like this these are the values you need to change:
* "type", this you need to change to the same type you set in the html file.
* "message", this you need to change to the text you want to display. when using multiple arguments, you can add the %1 or %2 to specify which goes where.
* "args0", This is where you specify the arguments you want to pass to the block. You can add multiple arguments by adding another block {} to the [] array.
* "type" under "args0", this you need to specify the type of the argument you want to pass to the block. Look at the blockly documentation for more information, examples: `field_dropdown`, `field_text`, `field_number`
* "name" under "args0", this you need to specify the name of the variable, so you can later retrieve this value from the block into the code.
* "options" under "args0", this you need to specify options for the block. This value can change depending on what block type you want.
* "colour", here you can change the text color of the block. 

3. Add the javascript interpeter
Under the javascript code for adding the code block, we need to add a interpeter to that code block. THis is done like so:
```javascript
javascript.javascriptGenerator.forBlock['move'] = function(block) {
  let value = '\'' + block.getFieldValue('NUMBER') + '\'';
  let direction = '\'' + block.getFieldValue('DIRECTION') + '\'';
  return 'robot.move(' + direction + ', ' + value +');\n';
};
```
you can retrieve a value from the code block and decide what code comes out using the `return` line.

For adding more options for blocks like the emote block, you need to simply add a line like this to the code block:
```javascript
"options": [
    ["*ID SENT TO CODE*", "*DISPLAY NAME"]
    ["Smile", "smile"],
    ["Frown", "frown"]
  ]
```

### Adding a button to the arrow screen
For adding a button to the arrow button screen, you need to head into the html code and add a line like this:
```html
<button class="animate-btn" onclick="sendCommand('animate', 'sit')">Sit</button>
```
This needs to be added to the parent div that you want to add it to, for example:
```html
<div class="animate-container">
  <button class="animate-btn" onclick="sendCommand('animate', 'sit')">Sit</button>
```
After that you need to change the "animate" in all cases to "emote" if you want to add a emote instead of a animation.
The `sendCommand()` function requires you add the type of message you want to send, basically `animate` or `emote` and then the animation type. For now this is pre programmed in the arduino code, but this will be later changed to interpret a array of movements.
