<img width="452" alt="image" src="https://user-images.githubusercontent.com/39780457/220176753-2b03da7a-5c7c-4f4c-9efd-e3bda6e0efc4.png">


**Flow of functions:**
* continuous sending of character ? to CNC Controller
* receive all Status messages from CNC controller
* Message type recognition
* parse message Contents
* Provide all values in variables
* Shown **8 Status** on the display of the Atom Matrix (Colors & Letters)
* Shown 3 Status on the Light-Tower (still at work)
* Status: Idle, Run, Jog, Homing, Hold, Alarm, Door, Sleep
* Each LED has 4 modes: OFF, ON, Blinking, Flashing

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

