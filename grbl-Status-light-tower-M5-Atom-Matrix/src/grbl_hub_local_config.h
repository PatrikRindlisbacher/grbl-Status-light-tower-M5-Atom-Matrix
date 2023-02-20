#include <Arduino.h>

struct grbl_hub_pin_config_t {                                                                    // Alle Pin Variablen 
  int8_t pin_RXD_Uart_to_grbl_board = 26;                                                         // grove weiss   --> M5 Stack Core 2 = 33  --> M5 Stack Atom PSRAM = 26 --> connnected to Bart Dring 6er CNC Controller  GPIO 13 = TXD
  int8_t pin_TXD_Uart_to_grbl_board = 32;                                                         // grove gelb    --> M5 Stack Core 2 = 32  --> M5 Stack Atom PSRAM = 32 --> connnected to Bart Dring 6er CNC Controller  GPIO 14 = RXD
  int8_t pin_Spindle_ON_Info_Output = 0;                                                          // GPIO Pin Spindel
  int8_t pin_MIST_ON_Info_Output = 0;                                                             // GPIO Pin MIST  Cooling (Nebel)
  int8_t pin_FLOOD_ON_Info_Output = 0;                                                            // GPIO Pin Flood Cooling (Kühlwasser-Flut)
 } grbl_hub_config ;