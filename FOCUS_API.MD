Focus API KeyMap
================
Focus API is the serial tool to read/write information from the Raise Keyboard, this tool is used by Bazecor to send the customizations the user sets in the app to the keyboard, these customizations require a certain structure so the order in which the information is sent to the Raise Firmware will be mapped in this file

## KeyMap assignations to each key
Each functions reads/writes a different memory map depending on it's target, for example the layers.custom use an 80 key memory map stacked 10 times for each of the available custom layers, if we speak about the default layers, we have 2, and the colorMap has the same distribution as the custom layers.

#### Memory map correlation between positions and physical keys
Ansi Map
![ANSI](https://github.com/Dygmalab/Raise-Firmware/blob/master/RaiseANSIKeyMap.png)
Iso Map
![ISO](https://github.com/Dygmalab/Raise-Firmware/blob/master/RaiseISOKeyMap.png)

## ColorMap assignations to each key
In the ColorMap case, we need to assign a palette color (with the color position in the palette, between 0 and 15) to each LED available in the layout, this includes all the under glow LEDs and the neuron, to map the colors for each layer, we need 131 positions multiplied by 10 as we have 10 custom layers.

The default layers do not have colormap as they are only a reserve for a default keymap that will be reloaded when the firmware is erased as the default one.

## Memory map correlation between positions and physical keys
Ansi Map
![ANSI](https://github.com/Dygmalab/Raise-Firmware/blob/master/RaiseANSIColorMap.png)
Iso Map
![ISO](https://github.com/Dygmalab/Raise-Firmware/blob/master/RaiseISOColorMap.png)

## Palette
The color palette works with 16 colors assigned to a numeral position from 0 to 15, this means that the number that represents the color in the colorMap is the position of the color in this palette.

To update it just order the colors as you want them to be represented in the palette.

Each color consists of 3 numbers between 0 and 255 in this order:
- Red component of the color
- Green component of the color
- Blue component of the color

To send white color for example, use '255 255 255' to represent that first color of the palette, just follow with 15 more colors to finish the memory map.