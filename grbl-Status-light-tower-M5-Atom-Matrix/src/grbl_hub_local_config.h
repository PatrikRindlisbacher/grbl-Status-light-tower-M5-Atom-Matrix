#include <Arduino.h>

//***************** P I N   C O N F I G U R A T I O N **************//
struct grbl_hub_pin_config_t {                                      // Alle Pin Variablen 
  int8_t pin_RXD_Uart_to_cnc = 26;                                  // RXD GPIO 26 grove weiss -->  to Bart Dring 6er CNC Controller  TX or GPIO 13 = TXD
  int8_t pin_TXD_Uart_to_cnc = 32;                                  // TXD GPIO 32 grove gelb  -->  to Bart Dring 6er CNC Controller  RX or GPIO 14 = RXD
  int8_t pin_Spindle_ON_Info_Output = 0;                            // GPIO Pin Info Spindel ON
  int8_t pin_MIST_ON_Info_Output = 0;                               // GPIO Pin Info MIST  Cooling (Nebel)
  int8_t pin_FLOOD_ON_Info_Output = 0;                              // GPIO Pin Info Flood Cooling (Kühlwasser-Flut)
  int8_t pin_Light_Tower_red = 19;                                  // GPIO Pin Light Tower red
  int8_t pin_Light_Tower_orange = 23;                               // GPIO Pin Light Tower orange
  int8_t pin_Light_Tower_green = 33;                                // GPIO Pin Light Tower green
 } grbl_hub_config ;

