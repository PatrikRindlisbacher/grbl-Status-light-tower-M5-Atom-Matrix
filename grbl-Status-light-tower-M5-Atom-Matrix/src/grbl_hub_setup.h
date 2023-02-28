#include <Arduino.h>

//************************ M5 Stack Atom-Matrix Setup *************** // M5 ATOM MATRIX
#ifdef BOARD_M5_ATOM_MATRIX                                           // if Built Flag = BOARD_M5_ATOM_MATRIX
void m5_atom_matrix_setup() {                                         // Setup M5 Atom Matrix
  grbl_hub_status_to_gpio_setup();                                    // Setup Local Output Pins
  uart_to_usb_setup();                                                // Setup for UART on USB Local 
  uart_cnc_setup();                                                   // Setup for UART to CNC 
  grbl_hub_rgb_led_setup();                                           // Setup for LCD Neopixel
}
#endif

//************************ M5 Stack Atom-Lite Setup ***************** // M5 ATOM LITE
#ifdef BOARD_M5_ATOM_LITE                                             // if Built Flag = BOARD_M5_ATOM_LITE
void m5_atom_lite_setup() {                                           // Setup M5 Atom Matrix
  grbl_hub_status_to_gpio_setup();                                    // Setup Local Output Pins
  uart_to_usb_setup();                                                // Setup for UART on USB Local 
  uart_cnc_setup();                                                   // Setup for UART to CNC 
  grbl_hub_rgb_led_setup();                                           // Setup for LCD Neopixel --> SK6812 RGBW --> on GPIO 27
}
#endif

//************************ M5 Stack Atom-PSRAM Setup *****************// M5 ATOM PSRAM_LCD
#ifdef BOARD_M5_ATOM_PSRAM_LCD                                        // if Built Flag = BOARD_M5_ATOM_PSRAM_LCD
void m5_atom_psram_lcd_setup() {                                      // Setup M5 Atom PSRAM LCD
  grbl_hub_status_to_gpio_setup();                                    // Setup Local Output Pins
  uart_to_usb_setup();                                                // Setup for UART on USB Local 
  uart_cnc_setup();                                                   // Setup for UART to CNC 
  grbl_hub_rgb_led_setup();                                           // Setup for LCD Neopixel
  ui_anzeige_setup();                                                 // Setup LCD Display
}
#endif

//************************ M5 Stack Core Fire  Setup *****************// M5 Core Fire  with LCD
#ifdef BOARD_M5_CORE_FIRE                                             // if Built Flag = BOARD_M5_CORE_FIRE
void m5_core_fire_setup() {                                           // Setup M5 Core Fire
  grbl_hub_status_to_gpio_setup();                                    // Setup Local Output Pins
  uart_to_usb_setup();                                                // Setup for UART on USB Local 
  uart_cnc_setup();                                                   // Setup for UART to CNC 
  grbl_hub_rgb_led_setup();                                           // Setup for LCD Neopixel
  ui_anzeige_setup();                                                 // Setup LCD Display
}
#endif

//****************************** Board  Setup ************************//
void grbl_hub_board_setup() {                                         // Setup Hardware
#ifdef BOARD_M5_ATOM_MATRIX                                           // if M5 Atom Matrix
  m5_atom_matrix_setup();                                             // Setup
#elif defined(BOARD_M5_ATOM_LITE)                                     // if M5 ATOM Lite
  m5_atom_lite_setup();                                               // Setup
#elif defined(BOARD_M5_ATOM_PSRAM_LCD)                                // if M5 Atom PSRAM LCD
  m5_atom_psram_lcd_setup();                                          // Setup
#elif defined(BOARD_M5_CORE_FIRE)                                     // if M5 CORE Fire with LCD
  m5_core_fire_setup();                                               // Setup 
#endif
}
