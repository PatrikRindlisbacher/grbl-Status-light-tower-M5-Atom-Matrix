#include <Arduino.h>

void grbl_staus_to_gpio_update(){
  if (grbl_hub_config.pin_MIST_ON_Info_Output !=0){                                                             // if defines the connection for MIST Gpio Output

  }
}

// ***************************** L O C A L  G P I O   S E T U P *************************//
void grbl_staus_to_gpio_setup(){
  if (grbl_hub_config.pin_Light_Tower_red !=0){                   // Light Tower red                                                                                             // if defines the connection for MIST Gpio Output
    pinMode(grbl_hub_config.pin_Light_Tower_red, OUTPUT);         // sets the digital pin as output
  }
  if (grbl_hub_config.pin_Light_Tower_orange !=0){                // Light Tower orange                                                           // if defines the connection for MIST Gpio Output
    pinMode(grbl_hub_config.pin_Light_Tower_orange, OUTPUT);      // sets the digital pin as output
  }
  if (grbl_hub_config.pin_Light_Tower_green !=0){                 // Light Tower green                                                           // if defines the connection for MIST Gpio Output
    pinMode(grbl_hub_config.pin_Light_Tower_green, OUTPUT);       // sets the digital pin as output
  }
}