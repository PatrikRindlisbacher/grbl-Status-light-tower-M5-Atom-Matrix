#include <Arduino.h>

// **********************  T I M E R  F O R  GPIO  B L I N K  ******************// Timer
bool GPIO_state_blink(){                                                        // Timer for Blink on GPIO
  if ( millis() > blink_and_flash.last_blink_start_millis + blink_and_flash.blink_duration_on + blink_and_flash.blink_duration_off){
    blink_and_flash.last_blink_start_millis = millis();                         // notice the aktual start cycle millis
    return HIGH;                                                                // Response GPIO High
  }
  if (millis() < blink_and_flash.last_blink_start_millis + blink_and_flash.blink_duration_on){
    return HIGH;                                                                // Response GPIO High
  }
  else {
    return LOW;                                                                 // Response GPIO Low
  }
}
// **********************  T I M E R  F O R  GPIO  F L A S H *******************// Timer
bool GPIO_state_flash(){                                                        // Timer for Flash on GPIO
  if ( millis() > blink_and_flash.last_flash_start_millis + blink_and_flash.flash_duration_on + blink_and_flash.flash_duration_off){
    blink_and_flash.last_flash_start_millis= millis();                          // notice the aktual start cycle millis
    return HIGH;                                                                // Response GPIO High
  }
  if (millis() < blink_and_flash.last_flash_start_millis + blink_and_flash.flash_duration_on){
    return HIGH;                                                                // Response GPIO High
  }
  else {
    return LOW;                                                                 // Response GPIO Low
  }
}

// **********************  Determine current GPIO state ************************// GPIO State according to Output Conditions
bool current_GPIO_Output_State(GPIO_Output_Conditions GPIO_Mode){               // Determine current GPIO state (off / on / Blink / flash)
  if (GPIO_Mode == GPIO_Output_Conditions::off){                                // if Condition OFF
    return LOW;                                                                 // current LOW 
  }
  else if (GPIO_Mode == GPIO_Output_Conditions::on){                            // if Condition ON
    return HIGH;                                                                // current HIGH
  }
  else if (GPIO_Mode == GPIO_Output_Conditions::blinking){                      // if Condition blinking slow
    return GPIO_state_blink();                                                  // Determine Blink Condition
  }
  else if (GPIO_Mode == GPIO_Output_Conditions::flashing){                      // if Condition flashing short 
    return GPIO_state_flash();                                                  // Determine Flash Condition
  }
  else {
    return LOW;                                                                 // On program error LOW
  }
}

// *************************** L O C A L  G P I O   U P D A T E  *********************// GPIO Update
void grbl_hub_status_to_gpio_update(){                                                // Update all Local GPIO's
  bool GPIO_New_State;                                                                // Variable for the new state
  if (grbl_hub_config.pin_Light_Tower_red !=0){                                       // Light Tower RED --> if defined                                                        // if defines the connection for MIST Gpio Output
    GPIO_New_State = current_GPIO_Output_State(light_tower_Status.red_lamp);          // determine the current status
    digitalWrite(grbl_hub_config.pin_Light_Tower_red, GPIO_New_State);                // Set the current Status to GPIO 
  }
  if (grbl_hub_config.pin_Light_Tower_orange !=0){                                    // Light Tower Oragnge --> if defined                                                        // if defines the connection for MIST Gpio Output
    GPIO_New_State = current_GPIO_Output_State(light_tower_Status.orange_lamp);       // determine the current status
    digitalWrite(grbl_hub_config.pin_Light_Tower_orange, GPIO_New_State);             // Set the current Status to GPIO  
  }
  if (grbl_hub_config.pin_Light_Tower_green !=0){                                     // Light Tower Green --> if defined                                                         // if defines the connection for MIST Gpio Output
    GPIO_New_State = current_GPIO_Output_State(light_tower_Status.green_lamp);        // determine the current status
    digitalWrite(grbl_hub_config.pin_Light_Tower_green, GPIO_New_State);              // Set the current Status to GPIO 
  }
}

// ***************************** L O C A L  G P I O   S E T U P ********************* // GPIO Setup --> if is defined / needed
void grbl_hub_status_to_gpio_setup(){                                                 // Setup all local GPIO's
  if (grbl_hub_config.pin_Light_Tower_red !=0){                                       // Light Tower red --> if is defined                                                                                            // if defines the connection for MIST Gpio Output
    pinMode(grbl_hub_config.pin_Light_Tower_red, OUTPUT);                             // sets the digital pin as output
  }
  if (grbl_hub_config.pin_Light_Tower_orange !=0){                                    // Light Tower orange --> if is defined                                                           // if defines the connection for MIST Gpio Output
    pinMode(grbl_hub_config.pin_Light_Tower_orange, OUTPUT);                          // sets the digital pin as output
  }
  if (grbl_hub_config.pin_Light_Tower_green !=0){                                     // Light Tower green --> if is defined                                                           // if defines the connection for MIST Gpio Output
    pinMode(grbl_hub_config.pin_Light_Tower_green, OUTPUT);                           // sets the digital pin as output
  }
}