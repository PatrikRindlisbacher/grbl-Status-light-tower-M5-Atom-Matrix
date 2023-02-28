#include <Arduino.h>                                                            // Arduino Include Header

// ********************** Board / Projekts dependent includes *******************//
//***************************** M5 Stack Atom-Matrix Setup *********************// M5 ATOM MATRIX
#ifdef BOARD_M5_ATOM_MATRIX                                                     // if Built Flag = BOARD_M5_ATOM_MATRIX
#include <Adafruit_NeoPixel.h>
#endif                                                                          // ***********

//****************************** M5 Stack Atom-Lite Setup **********************// M5 ATOM LITE
#ifdef BOARD_M5_ATOM_LITE                                                       // if Built Flag = BOARD_M5_ATOM_LITE
#include <Adafruit_NeoPixel.h>
#endif                                                                          // ***********

//********************************* M5 Stack Atom-PSRAM Setup ******************// M5 ATOM PSRAM_LCD
#ifdef BOARD_M5_ATOM_PSRAM_LCD                                                  // if Built Flag = BOARD_M5_ATOM_PSRAM_LCD
#include <Adafruit_NeoPixel.h>
// #include <M5GFX.h>
// #include <M5AtomDisplay.h>
#define LGFX_M5STACK                                                            // M5Stack (Basic / Gray / Go / Fire)
#define LGFX_AUTODETECT
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp> 
static LGFX lcd;  
static LGFX_Sprite tftSprite(&lcd);                                             // LGFX_Sprite
#endif                                                                          // ***********

//********************************* M5 Stack CORE FIRE Setup *******************// M5 CORE FIRE with LCD
#ifdef BOARD_M5_CORE_FIRE                                                       // if Built Flag = BOARD_M5_CORE_FIRE
#include <Adafruit_NeoPixel.h>
#define LGFX_M5STACK                                                            // M5Stack (Basic / Gray / Go / Fire)
#define LGFX_AUTODETECT
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp> 
static LGFX lcd;  
static LGFX_Sprite tftSprite(&lcd);                                             // LGFX_Sprite
#endif                                                                          // ***********

// ******************************** Indlude for all Boards / Projekts ********* //
//#include <JC_Button.h>                                                        // https://github.com/JChristensen/JC_Button
#include "grbl_hub_config.h"                                                    // --> Config for all includes & Pin's for your Board!!!!
#include "grbl_hub_variables.h"                                                 // All Variables for GRBL-Hub
#include "grbl_hub_uart.h"                                                      // Code for UART from / to Local Board to USB
#include "grbl_hub_parser.h"                                                    // Code for GRBL 1.1 Parser to Status struct Variables
#include "grbl_hub_gpio_output.h"                                               // Code for Local GPIO Output --> for example Status to -> LED or Buzzer
#include "grbl_hub_gpio_input.h"                                                // Code for Local GPIO Input  --> for example Button's
#include "grbl_hub_rgb_leds.h"                                                  // NEOPIXEL / LED-Stripes
#include "grbl_hub_light_tower.h"                                               // Light Tower Status Code
#include "grbl_hub_display.h"                                                   // Display 
#include "grbl_hub_setup.h"                                                     // Board Setup 