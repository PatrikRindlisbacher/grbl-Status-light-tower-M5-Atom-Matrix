#include <Arduino.h>

// **********************  T I M E R  F O R  B L I N K  & F L A S H **********************//
void update_blink_and_flash(){

}

// **********************  Determine current GPIO state **********************//

bool current_GPIO_Output_State(){

}

// *************************** L O C A L  G P I O   U P D A T E  *************************//
void grbl_status_to_gpio_update(){
  if (grbl_hub_config.pin_Light_Tower_red !=0){                                                             // if defines the connection for MIST Gpio Output
    digitalWrite(grbl_hub_config.pin_Light_Tower_red, HIGH);          //
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