
**This project is based on ESP32 & GRBL 1.1 for all CNC & 3D printing applications**  
<img width="451" alt="image" src="https://user-images.githubusercontent.com/39780457/220300378-d39288d2-21e3-41ca-96fb-3849ed2d68d9.png">  
**This project is the start for more projects like grbl DRO, Wireless Pendant, CNC Panel... **

**NEUE Version in Arbeit** Stand 28.02.2023 ohne M5 Lib's  - > Universal ESP32

**ALL functions are ready to work ad for testing with M5 Atom Matrix !!!!**  
The Light Tower is already supported by 3 boards.

**Flow of functions: (grbl Light-Tower  Controller)**
* continuous sending of character ? to CNC Controller
* receive all Status messages from CNC controller
* grbl Message type recognition
* parse message reportData Contents
* Provide all values in local variables
* Shown **8 Status** on the display of the Atom Matrix (Colors & Letters)
* Shown 3 (or more) Status on the Light-Tower 
* Each LED has 4 modes: OFF, ON, Blinking, Flashing. 

**Signal Light Tower by default**
* Idle = green on
* Alarm = red flashing
* Checkmode = red blinking
* Run = orange on
* Hold = orange on and red flashing
* Jog = orange blinking
* SafetyDoor = red flashing
* Sleep = all off
* Config Alarm = red blinking

**Connect**
* Connect RX to TX and TX to RX (M5 crossed to CNC)
* Look for 3.3V or 5V Input / Output levels depending on the board.
* Depending on the board, the 5V can also be plugged in directly on the CNC board.
<img width="223" alt="image" src="https://user-images.githubusercontent.com/39780457/220160670-0b9d1765-2e1e-4385-9f77-221070fcda38.png">
 
**Selection of the UART**  
* you can use RX & TX directly on the controller. (if you don't use the USB port simultaneously)
* Some boards / Firmwares offer a separate external TTL UART connector (eg FluidNC)
 
**Connection signal tower**
* A suitable circuit can be built with the DiY Protokit. (or similar)
* I will publish a circuit proposal shortly.
<img width="267" alt="image" src="https://user-images.githubusercontent.com/39780457/220189643-b8c80646-0ddd-4f3d-9b02-51f869ac9268.png">

**used libraries (Visual Studio Code & PlatformIO / Arduino )**  
All libraries are automatically installed with PlatformIO  
  
The code is easily ported to any Arduino board with hardware UART.
****
**GBL compatibility**  
It should support GRBL from the current version 1.1 https://github.com/gnea/grbl/wiki/Grbl-v1.1-Interface
****

**final word**  
I am happy about every reaction in the [issues](https://github.com/PatrikRindlisbacher/grbl-Status-light-tower-M5-Atom-Matrix/issues).  
I will write detailed instructions in the next few days. [WIKI](https://github.com/PatrikRindlisbacher/grbl-Status-light-tower-M5-Atom-Matrix/wiki)
