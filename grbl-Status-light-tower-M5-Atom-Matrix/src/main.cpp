// GRBL 1.1 grbl-Status-light-tower-M5-Atom-Matrix  www.cle.ch  Patrik Rindlisbacher  
// https://github.com/PatrikRindlisbacher/grbl-Status-light-tower-M5-Atom-Matrix

// Reveice all GRBL Status and parse in Status struct Variables
// continuous sending of character ? to CNC Controller and receive all Status messages from CNC controller
// grbl Message type recognition, parse message reportData Contents, Provide all values in local variables
// Shown 8 Status on the display of the Atom Matrix (Colors & Letters) and Shown 3 (or more) Status on the Light-Tower
// Each GPIO LED has 4 modes: OFF, ON, Blinking, Flashing.


#include <Arduino.h>                                            // Arduino Include Header
#include "grbl_hub_local_config.h"                              // --> Config for all includes & Pin's for your Board!!!!
#include "grbl_hub_variables.h"                                 // All Variables for GRBL-Hub
#include "grbl_hub_uart.h"                                      // Code for UART from / to Local Board to USB
#include "grbl_hub_parser.h"                                    // Code for GRBL 1.1 Parser to Status struct Variables
#include "grbl_hub_local_control.h"                             // Code for GRBL 1.1 Status to Local GPIO --> for example LED or Buzzer
#include "grbl_hub_rgb_leds.h"                                  // ATOM Matrix Include     --> disable for no M5Stack Atom Matrix
#include "grbl_hub_light_tower.h"                               // Light Tower Status Code

void setup() {                                                  // SETUP
  uart_to_usb_setup();                                          // Setup for UART on USB Local 
  uart_cnc_setup();                                             // Setup for UART to CNC 
  m5_atom_matrix_setup();                                       // Setup M5 Atom Matrix
  grbl_staus_to_gpio_setup();                                   // Setup Local Output Pins
}

void loop() {                                                    // Loop
  grbl_status_update_request();                                  // Poll the CNC Controller with ?
  uart_usb_read();                                               // read data from USB Uart
  uart_cnc_read();                                               // read data from CNC Uart
  grbl_Message_main_parser();                                    // Parse GRBL all GRBL Status information's
  m5_atom_matrix_update();                                       // Update the M5 Matrix Display
  light_tower_status_update();                                   // Update the Light Tower Status Veriables
  grbl_status_to_gpio_update();                                  // Update Local Output Pins
}

