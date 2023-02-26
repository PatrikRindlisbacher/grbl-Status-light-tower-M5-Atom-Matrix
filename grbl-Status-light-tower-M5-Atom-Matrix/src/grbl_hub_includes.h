#include <Arduino.h>                                                            // Arduino Include Header


// ******************************** Board dependent includes *******************//
//***************************** M5 Stack Atom-Matrix Setup *********************// M5 ATOM MATRIX
#ifdef BOARD_M5_ATOM_MATRIX                                                     // if Built Flag = BOARD_M5_ATOM_MATRIX
#include "M5Atom.h"
#endif

//****************************** M5 Stack Atom-Lite Setup **********************// M5 ATOM LITE
#ifdef BOARD_M5_ATOM_LITE                                                       // if Built Flag = BOARD_M5_ATOM_LITE
#include "M5Atom.h"
#endif

//********************************* M5 Stack Atom-PSRAM Setup ******************// M5 ATOM PSRAM_LCD
#ifdef BOARD_M5_ATOM_PSRAM_LCD                                                  // if Built Flag = BOARD_M5_ATOM_PSRAM_LCD
#include "M5Atom.h"
#endif

// ******************************** Indlude for all Boards / Projekts ********* //
#include "grbl_hub_local_config.h"                                              // --> Config for all includes & Pin's for your Board!!!!
#include "grbl_hub_variables.h"                                                 // All Variables for GRBL-Hub
#include "grbl_hub_uart.h"                                                      // Code for UART from / to Local Board to USB
#include "grbl_hub_parser.h"                                                    // Code for GRBL 1.1 Parser to Status struct Variables
#include "grbl_hub_local_control.h"                                             // Code for GRBL 1.1 Status to Local GPIO --> for example LED or Buzzer
#include "grbl_hub_rgb_leds.h"                                                  // ATOM Matrix Include     --> disable for no M5Stack Atom Matrix
#include "grbl_hub_light_tower.h"                                               // Light Tower Status Code