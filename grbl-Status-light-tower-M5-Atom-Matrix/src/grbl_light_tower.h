#include <Arduino.h>

// ************************** L I G H T  T O W E R  S T A T U S  *************************//
void light_tower_status_update(){
  if (Maschine_State.State_current== State::Idle){                // Idle = green on
    light_tower_Status.red_lamp=Lamp_LED_Mode::off;
    light_tower_Status.orange_lamp=Lamp_LED_Mode::off;
    light_tower_Status.green_lamp=Lamp_LED_Mode::on;
  }
  else if (Maschine_State.State_current== State::Alarm){          // Alarm = red on
    light_tower_Status.red_lamp=Lamp_LED_Mode::on;
    light_tower_Status.orange_lamp=Lamp_LED_Mode::off;
    light_tower_Status.green_lamp=Lamp_LED_Mode::off;    
  }
  else if (Maschine_State.State_current== State::CheckMode){      // Checkmode = red blinking
    light_tower_Status.red_lamp=Lamp_LED_Mode::blinking;
    light_tower_Status.orange_lamp=Lamp_LED_Mode::off;
    light_tower_Status.green_lamp=Lamp_LED_Mode::off;    
  }
  else if (Maschine_State.State_current== State::Run){            // Run = orange on
    light_tower_Status.red_lamp=Lamp_LED_Mode::off;
    light_tower_Status.orange_lamp=Lamp_LED_Mode::on;
    light_tower_Status.green_lamp=Lamp_LED_Mode::off;    
  }
  else if (Maschine_State.State_current== State::Hold){           // Hold = orange on & red flashing
    light_tower_Status.red_lamp=Lamp_LED_Mode::flashing;
    light_tower_Status.orange_lamp=Lamp_LED_Mode::on;
    light_tower_Status.green_lamp=Lamp_LED_Mode::off;    
  }
  else if (Maschine_State.State_current== State::Jog){            // Jog = orange blinking
    light_tower_Status.red_lamp=Lamp_LED_Mode::off;
    light_tower_Status.orange_lamp=Lamp_LED_Mode::blinking;
    light_tower_Status.green_lamp=Lamp_LED_Mode::off;    
  }
  else if (Maschine_State.State_current== State::SafetyDoor){     // SafetyDoor = red flashing
    light_tower_Status.red_lamp=Lamp_LED_Mode::flashing;
    light_tower_Status.orange_lamp=Lamp_LED_Mode::off;
    light_tower_Status.green_lamp=Lamp_LED_Mode::off;    
  }
  else if (Maschine_State.State_current== State::Sleep){          // Sleep = all off
    light_tower_Status.red_lamp=Lamp_LED_Mode::off;
    light_tower_Status.orange_lamp=Lamp_LED_Mode::off;
    light_tower_Status.green_lamp=Lamp_LED_Mode::off;    
  }
  else if (Maschine_State.State_current== State::ConfigAlarm){    // Config Alarm = red blinking
    light_tower_Status.red_lamp=Lamp_LED_Mode::blinking;
    light_tower_Status.orange_lamp=Lamp_LED_Mode::off;
    light_tower_Status.green_lamp=Lamp_LED_Mode::off;
  }
}