<img width="452" alt="image" src="https://user-images.githubusercontent.com/39780457/220176753-2b03da7a-5c7c-4f4c-9efd-e3bda6e0efc4.png">


**Flow of functions:**
* continuous sending of character ?
* receive all messages from CNC controller
* Message type recognition
* parse message
* Provide all values in variables
* Shown 10 Status on the display of the Atom Matrix
* Shown 3 Status on the Light-Tower (still at work)

**Connect**

<img width="223" alt="image" src="https://user-images.githubusercontent.com/39780457/220160670-0b9d1765-2e1e-4385-9f77-221070fcda38.png">

* Connect RX to TX and TX to RX (M5 crossed to CNC)
* Look for 3.3V or 5V levels depending on the board.
* Depending on the board, the 5V can also be plugged in directly on the CNC board.

**Selection of the UART**
* If you don't use the USB port, you can use RX & TX directly on the controller.
* Some boards offer a separate external TTL UART connector

**used libraries**
* M5Atom https://github.com/m5stack/M5Atom?utm_source=platformio&utm_medium=piohome
* FastLED https://github.com/FastLED/FastLED?utm_source=platformio&utm_medium=piohome

I am happy about every reaction in the issues or pull request.
I will write detailed instructions in the next few days. "WIKI"
