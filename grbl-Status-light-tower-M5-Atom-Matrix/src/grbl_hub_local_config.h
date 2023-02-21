#include <Arduino.h>

struct grbl_hub_pin_config_t {                                // Alle Pin Variablen 
  int8_t pin_RXD_Uart_to_cnc = 26;                            // RXD grove weiss     --> M5 Stack Atom  = 26 --> connnected to Bart Dring 6er CNC Controller  TX or GPIO 13 = TXD
  int8_t pin_TXD_Uart_to_cnc = 32;                            // TXD grove gelb      --> M5 Stack Atom  = 32 --> connnected to Bart Dring 6er CNC Controller  RX or GPIO 14 = RXD
  int8_t pin_Spindle_ON_Info_Output = 0;                      // GPIO Pin Info Spindel ON
  int8_t pin_MIST_ON_Info_Output = 0;                         // GPIO Pin Info MIST  Cooling (Nebel)
  int8_t pin_FLOOD_ON_Info_Output = 0;                        // GPIO Pin Info Flood Cooling (Kühlwasser-Flut)
  int8_t pin_Light_Tower_red = 0;                             // GPIO Pin Light Tower red
  int8_t pin_Light_Tower_orange = 0;                          // GPIO Pin Light Tower orange
  int8_t pin_Light_Tower_green = 0;                           // GPIO Pin Light Tower green
 } grbl_hub_config ;

