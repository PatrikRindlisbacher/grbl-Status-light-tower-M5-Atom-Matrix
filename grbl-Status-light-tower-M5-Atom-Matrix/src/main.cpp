// GRBL 1.1 UART Hub Universal www.cle.ch Patrik Rindlisbacher  (https://github.com/PatrikRindlisbacher/FluidNC-or-GRBL-UART-Gateway-an-IO-Module-)
// Reveice all GRBL Status and parse in Status struct Variables
// Passtrouh bidirectional UART CNC <--> UART USB all Commands & Status
// GRBL Status to GPIO  // GRBL Status to Display // GRBL Status to ESPNow ... and more

#include <Arduino.h>                                            // Arduino Include Header
#include "grbl_hub_local_config.h"                              // --> Config for all Pin's for your Board!!!!
#include "grbl_hub_variables.h"                                 // All Variables for GRBL-Hub
#include "grbl_hub_uart.h"                                      // Code for UART from / to Local Board to USB
#include "grbl_hub_parser.h"                                    // Code for GRBL 1.1 Parser to Status struct Variables
#include "grbl_hub_local_control.h"                             // Code for GRBL 1.1 Status to Local GPIO --> for example LED or Buzzer
#include "m5_atom_matrix.h"                                     // ATOM Matrix Include     --> disable for no M5Stack Atom Matrix

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
  grbl_staus_to_gpio_update();                                   // Update Local Output Pins
}

