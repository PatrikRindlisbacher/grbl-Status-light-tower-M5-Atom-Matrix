#include <Arduino.h>

void uart_to_usb_setup(){                                            // Local UART on USB Setup
  Serial.begin(115200);                                             // only Baud 115200 (8N1)
}

void uart_cnc_setup(){                                                                 // Setup UART from/to CNC
  Serial2.begin(115200, SERIAL_8N1, grbl_hub_config.pin_RXD_Uart_to_grbl_board, grbl_hub_config.pin_TXD_Uart_to_grbl_board);
}

void uart_cnc_read()                                                                           // Read serial GRBL from CNC Board 
{
  while (Serial2.available())                                                                     // If Data available from CNC Board
   {
    char MinChar = (char)Serial2.read();                                                          // Char received from from CNC Board 
    uart_cnc_read_raw.last_char_reveive_millis = millis();                                        // notice millis from Last Char received 
    Serial.write(MinChar);                                                                        // Passtrouh form CNC to UART USB
    if (MinChar == '\n')
    {
      uart_cnc_read_raw.Message_Available = true;

    }
    else
    {
      if (MinChar >= ' ') {uart_cnc_read_raw.Message += MinChar;}      // >= ' ' to avoid not wanted ctrl char.
    }
  }
}


void uart_usb_read(){
  while (Serial.available()) {                                      // If Data available
    Serial2.print(char(Serial.read()));                             // Passtrouh form USB to CNC
  }
}
