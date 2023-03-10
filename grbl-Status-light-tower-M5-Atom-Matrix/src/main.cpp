// GRBL 1.1 grbl-Status-light-tower-M5-Atom-Matrix  www.cle.ch  Patrik Rindlisbacher  
// https://github.com/PatrikRindlisbacher/grbl-Status-light-tower-M5-Atom-Matrix

// Reveice all GRBL Status and parse in Status struct Variables
// continuous sending of character ? to CNC Controller and receive all Status messages from CNC controller
// grbl Message type recognition, parse message reportData Contents, Provide all values in local variables
// Shown 8 Status on the display of the Atom Matrix (Colors & Letters) and Shown 3 (or more) Status on the Light-Tower
// Each GPIO LED has 4 modes: OFF, ON, Blinking, Flashing.

//*******************************************************************************************
// I have many more extensions planned. DRO / Wireless Pendant / CNC Panel 
// Give me FEEDBACK. I'm happy to help if you have any questions or problems
// https://github.com/PatrikRindlisbacher/grbl-Status-light-tower-M5-Atom-Matrix/issues
//*******************************************************************************************

#include "grbl_hub_includes.h"                                  // All includes are in a separate file. --> Partially controlled via Platfomio.ini Build_Flags

void setup() {                                                  // SETUP
  grbl_hub_board_setup();                                       // Hardware Base setup                  --> Partially controlled via Platfomio.ini Build_Flags
}

void loop() {                                                    // Loop
  grbl_hub_status_update_request();                              // Poll the CNC Controller with ?
  uart_usb_read();                                               // read data from USB Uart
  uart_cnc_read();                                               // read data from CNC Uart
  grbl_hub_Message_main_parser();                                // Parse GRBL all GRBL Status information's
  grbl_hub_rgb_led_update();                                     // Update the rgb Led's (one / Matrix / Stripes)
  grbl_hub_light_tower_status_update();                          // Update the Light Tower Status Veriables
  grbl_hub_status_to_gpio_update();                              // Update Local Output Pins
  grbl_hub_display_update();                                     // Update Display if available       --> Partially controlled via Platfomio.ini Build_Flags
}

