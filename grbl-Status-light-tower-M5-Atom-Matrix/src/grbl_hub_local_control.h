#include <Arduino.h>

// ************************** L I G H T  T O W E R  S T A T U S  *************************//
void light_tower_status_update(){
  if (Maschine_State.State_current== State::Idle){                // Idle = green on
    light_tower_Status.red_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.orange_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.green_lamp=Light_Tower_Lamp_Mode::on;
  }
  else if (Maschine_State.State_current== State::Alarm){          // Alarm = red on
    light_tower_Status.red_lamp=Light_Tower_Lamp_Mode::on;
    light_tower_Status.orange_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.green_lamp=Light_Tower_Lamp_Mode::off;    
  }
  else if (Maschine_State.State_current== State::CheckMode){      // Checkmode = red blinking
    light_tower_Status.red_lamp=Light_Tower_Lamp_Mode::blinking;
    light_tower_Status.orange_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.green_lamp=Light_Tower_Lamp_Mode::off;    
  }
  else if (Maschine_State.State_current== State::Run){            // Run = orange on
    light_tower_Status.red_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.orange_lamp=Light_Tower_Lamp_Mode::on;
    light_tower_Status.green_lamp=Light_Tower_Lamp_Mode::off;    
  }
  else if (Maschine_State.State_current== State::Hold){           // Hold = orange on & red flashing
    light_tower_Status.red_lamp=Light_Tower_Lamp_Mode::flashing;
    light_tower_Status.orange_lamp=Light_Tower_Lamp_Mode::on;
    light_tower_Status.green_lamp=Light_Tower_Lamp_Mode::off;    
  }
  else if (Maschine_State.State_current== State::Jog){            // Jog = orange blinking
    light_tower_Status.red_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.orange_lamp=Light_Tower_Lamp_Mode::blinking;
    light_tower_Status.green_lamp=Light_Tower_Lamp_Mode::off;    
  }
  else if (Maschine_State.State_current== State::SafetyDoor){     // SafetyDoor = red flashing
    light_tower_Status.red_lamp=Light_Tower_Lamp_Mode::flashing;
    light_tower_Status.orange_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.green_lamp=Light_Tower_Lamp_Mode::off;    
  }
  else if (Maschine_State.State_current== State::Sleep){          // Sleep = all off
    light_tower_Status.red_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.orange_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.green_lamp=Light_Tower_Lamp_Mode::off;    
  }
  else if (Maschine_State.State_current== State::ConfigAlarm){    // Config Alarm = red blinking
    light_tower_Status.red_lamp=Light_Tower_Lamp_Mode::blinking;
    light_tower_Status.orange_lamp=Light_Tower_Lamp_Mode::off;
    light_tower_Status.green_lamp=Light_Tower_Lamp_Mode::off;    
  }
}


// *************************** L O C A L  G P I O   U P D A T E  *************************//
void grbl_status_to_gpio_update(){
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