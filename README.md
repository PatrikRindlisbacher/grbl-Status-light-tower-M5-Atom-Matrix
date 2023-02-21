<img width="451" alt="image" src="https://user-images.githubusercontent.com/39780457/220300378-d39288d2-21e3-41ca-96fb-3849ed2d68d9.png">
**This project is the start for more projects like DRO, Pendant, Panel... **

**I'll be working a lot on this project over the next few days. Watch this project in a few days**

**ALL basic functions are ready for testing !!!!**

**Flow of functions:**
* continuous sending of character ? to CNC Controller
* receive all Status messages from CNC controller
* Message type recognition
* parse message Contents
* Provide all values in variables
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
* If you don't use the USB port, you can use RX & TX directly on the controller.
* Some boards / Firmwares offer a separate external TTL UART connector (eg FluidNC)
 
**Connection signal tower**
* A suitable circuit can be built with the DiY Protokit. (or similar)
* I will publish a circuit proposal shortly.
<img width="267" alt="image" src="https://user-images.githubusercontent.com/39780457/220189643-b8c80646-0ddd-4f3d-9b02-51f869ac9268.png">
 
**used libraries (Visual Studio Code & PlatformIO / Arduino )**
* M5Atom https://github.com/m5stack/M5Atom?utm_source=platformio&utm_medium=piohome
* FastLED https://github.com/FastLED/FastLED?utm_source=platformio&utm_medium=piohome

The code is easily ported to any Arduino board with hardware UART.

I am happy about every reaction in the issues or pull request.
I will write detailed instructions in the next few days. "WIKI"

