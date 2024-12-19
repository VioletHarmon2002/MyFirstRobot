## User Documentation

### Using the Sleep Emote
The sleep emote is a visual representation of a sleeping state for the robot. 

#### Activating the Sleep Emote
To activate the sleep emote:

1. Ensure your device is powered on and connected to the OLED display.
2. Send the "sleep" command to your device using website of the project, for example.
3. The OLED display should now show the sleep emote.


### Troubleshooting
If the sleep emote doesn't display correctly:

1. Verify that the `sleep_bitmap.h` file is in the same directory as your main sketch.
2. Check that the bitmap dimensions are correct and match the actual size of your bitmap data.
3. Ensure that the OLED display is properly connected and initialized in your code.

### Customization
If you wish to modify the sleep emote:

1. Open the `sleep_bitmap.h` file in a text editor.
2. Modify the bitmap data array to change the appearance of the emote.
3. Ensure that the `sleep_width` and `sleep_height` definitions match your modifications if you change the size of the bitmap.


