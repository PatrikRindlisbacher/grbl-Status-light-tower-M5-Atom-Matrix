#include <Arduino.h>

// **********************  T I M E R  F O R  B L I N K   **********************//
bool GPIO_state_blink(){
  if ( millis() > blink_and_flash.last_blink_start_millis + blink_and_flash.blink_duration_on + blink_and_flash.blink_duration_off){
    blink_and_flash.last_blink_start_millis = millis();                       // notice the aktual start cycle millis
    return HIGH;                                                              // Response GPIO High
  }
  if (millis() < blink_and_flash.last_blink_start_millis + blink_and_flash.blink_duration_on){
    return HIGH;                                                              // Response GPIO High
  }
  else {
    return LOW;                                                               // Response GPIO Low
  }
}
// **********************  T I M E R  F O R   F L A S H **********************//
bool GPIO_state_flash(){
  if ( millis() > blink_and_flash.last_flash_start_millis + blink_and_flash.flash_duration_on + blink_and_flash.flash_duration_off){
    blink_and_flash.last_flash_start_millis= millis();                        // notice the aktual start cycle millis
    return HIGH;                                                              // Response GPIO High
  }
  if (millis() < blink_and_flash.last_flash_start_millis + blink_and_flash.flash_duration_on){
    return HIGH;                                                              // Response GPIO High
  }
  else {
    return LOW;                                                               // Response GPIO Low
  }
}

// **********************  Determine current GPIO state **********************//
bool current_GPIO_Output_State(GPIO_Output_Conditions GPIO_Mode){             //
  if (GPIO_Mode == GPIO_Output_Conditions::off){                              // if OFF
    return LOW;                                                               // current LOW 
  }
  else if (GPIO_Mode == GPIO_Output_Conditions::on){                          // if ON
    return HIGH;                                                              // current HIGH
  }
  else if (GPIO_Mode == GPIO_Output_Conditions::blinking){                    // if blinking slow
    return GPIO_state_blink();                                                // Determine Blink Condition
  }
  else if (GPIO_Mode == GPIO_Output_Conditions::flashing){                    // if flashing short 
    return GPIO_state_flash();                                                // Determine Flash Condition
  }
  else {
    return LOW;                                                               // On program error LOW
  }
}

// *************************** L O C A L  G P I O   U P D A T E  *********************//
void grbl_status_to_gpio_update(){
  bool GPIO_New_State;
  if (grbl_hub_config.pin_Light_Tower_red !=0){                                       // Light Tower RED                                                        // if defines the connection for MIST Gpio Output
    GPIO_New_State = current_GPIO_Output_State(light_tower_Status.red_lamp);          // determine the current status
    digitalWrite(grbl_hub_config.pin_Light_Tower_red, GPIO_New_State);                // Set the current Status to GPIO 
  }
  if (grbl_hub_config.pin_Light_Tower_orange !=0){                                    // Light Tower Oragnge                                                        // if defines the connection for MIST Gpio Output
    GPIO_New_State = current_GPIO_Output_State(light_tower_Status.orange_lamp);       // determine the current status
    digitalWrite(grbl_hub_config.pin_Light_Tower_orange, GPIO_New_State);             // Set the current Status to GPIO  
  }
  if (grbl_hub_config.pin_Light_Tower_green !=0){                                     // Light Tower Green                                                        // if defines the connection for MIST Gpio Output
    GPIO_New_State = current_GPIO_Output_State(light_tower_Status.green_lamp);        // determine the current status
    digitalWrite(grbl_hub_config.pin_Light_Tower_green, GPIO_New_State);              // Set the current Status to GPIO 
  }
}

// ***************************** L O C A L  G P I O   S E T U P *********************//
void grbl_staus_to_gpio_setup(){
  if (grbl_hub_config.pin_Light_Tower_red !=0){                                       // Light Tower red                                                                                             // if defines the connection for MIST Gpio Output
    pinMode(grbl_hub_config.pin_Light_Tower_red, OUTPUT);                             // sets the digital pin as output
  }
  if (grbl_hub_config.pin_Light_Tower_orange !=0){                                    // Light Tower orange                                                           // if defines the connection for MIST Gpio Output
    pinMode(grbl_hub_config.pin_Light_Tower_orange, OUTPUT);                          // sets the digital pin as output
  }
  if (grbl_hub_config.pin_Light_Tower_green !=0){                                     // Light Tower green                                                           // if defines the connection for MIST Gpio Output
    pinMode(grbl_hub_config.pin_Light_Tower_green, OUTPUT);                           // sets the digital pin as output
  }
}