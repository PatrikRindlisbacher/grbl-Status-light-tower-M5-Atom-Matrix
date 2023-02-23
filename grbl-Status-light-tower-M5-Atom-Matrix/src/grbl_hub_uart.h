#include <Arduino.h>
//********************************** S E T U P   U A R T  T O  U S B **********//
void uart_to_usb_setup(){                                                      // Local UART on USB Setup
  Serial.begin(115200);                                                        // Baud 115200 (8N1)
}
//************************ S E T U P   U A R T  T O  C N C ********************//
void uart_cnc_setup(){                                                         // Setup UART from/to CNC
  Serial2.begin(115200, SERIAL_8N1, grbl_hub_config.pin_RXD_Uart_to_cnc, grbl_hub_config.pin_TXD_Uart_to_cnc);
}
//************************************  R E A D   U A R T   C N C *************//
void uart_cnc_read(){                                                          // Read serial GRBL from CNC Board 
  while (Serial2.available()) {                                                // If Data available from CNC Board
    char MinChar = (char)Serial2.read();                                       // Char received from from CNC Board 
    uart_cnc_read_raw.last_char_reveive_millis = millis();                     // notice millis from Last Char received 
    Serial.write(MinChar);                                                     // Passtrouh form CNC to UART USB
    if (MinChar == '\n'){                                                      // end of message
      uart_cnc_read_raw.Message_Available = true;                              // new message are available
    }                                                                          //
    else{                                                                      //
      if (MinChar >= ' ') {uart_cnc_read_raw.Message += MinChar;}              // >= ' ' to avoid not wanted ctrl char.
    }                                                                          //
  }                                                                            //
}
//****************************  R E A D   U A R T   U S B *********************//
void uart_usb_read(){                                                          // read data from USB
  while (Serial.available()) {                                                 // If Data available
    Serial2.print(char(Serial.read()));                                        // Passtrouh form USB to CNC
  }
}
