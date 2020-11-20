# Focus API KeyMap
Focus API is the serial tool to read/write information from the Raise Keyboard, this tool is used by Bazecor to send the customizations the user sets in the app to the keyboard, this customizations require a certain structure so the order in which the information is sent to the Raise Firmware will be mapped in this file

## Key assignations for each function
Each functions reads/writes a different memory map depending on it's target, for example the layers.custom use a 80 key memory map stacked 10 times for each of the available custom layers, if we speak about the default layers, we have 2, and the colorMap has the same distribution than the custom layers.

### Memory map correlation between positions and physical keys
Ansi Map
![ANSI](https://github.com/Dygmalab/Raise-Firmware/blob/better-compilation-support/RaiseANSIKeyMap.png)
Iso Map
![ISO](https://github.com/Dygmalab/Raise-Firmware/blob/better-compilation-support/RaiseISOKeyMap.png)