#include <Arduino.h>

// All constants "FLAG_" are in the PlatformIO.ini as Debug_Flag defined.
//*************** Local P I N   C O N F I G U R A T I O N ************//
struct grbl_hub_pin_config_t {                                        // All Pin Variables 
  int8_t pin_RXD_Uart_to_cnc = FLAG_PIN_RXD_UART_TO_CNC;              // RXD GPIO 26 grove weiss -->  to Bart Dring 6er CNC Controller  TX or GPIO 13 = TXD
  int8_t pin_TXD_Uart_to_cnc = FLAG_PIN_TXD_UART_TO_CNC;              // TXD GPIO 32 grove gelb  -->  to Bart Dring 6er CNC Controller  RX or GPIO 14 = RXD
  int8_t pin_Info_Output_Spindle_ON = 0;                              // GPIO Pin Info Spindel ON
  int8_t pin_Info_Output_MIST_ON = 0;                                 // GPIO Pin Info MIST  Cooling (Nebel)
  int8_t pin_Info_Output_FLOOD_ON = 0;                                // GPIO Pin Info Flood Cooling (Kühlwasser-Flut)
  int8_t pin_Light_Tower_red = FLAG_PIN_LIGHT_TOWER_RED;              // GPIO Pin Light Tower red
  int8_t pin_Light_Tower_orange = FLAG_PIN_LIGHT_TOWER_ORANGE;        // GPIO Pin Light Tower orange
  int8_t pin_Light_Tower_green = FLAG_PIN_LIGHT_TOWER_GREEN;          // GPIO Pin Light Tower green
 } grbl_hub_config ;

