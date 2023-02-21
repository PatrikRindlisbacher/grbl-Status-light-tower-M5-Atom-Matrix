#include <Arduino.h>

// ************************** L I G H T  T O W E R  S T A T U S  *************************//
void light_tower_status_update(){
  if (Maschine_State.State_current== State::Idle){                    // Idle = green on
    light_tower_Status.red_lamp=GPIO_Output_Mode::off;                // red 
    light_tower_Status.orange_lamp=GPIO_Output_Mode::off;             // orange
    light_tower_Status.green_lamp=GPIO_Output_Mode::on;               // green
  }
  else if (Maschine_State.State_current== State::Alarm){              // Alarm = red flashing
    light_tower_Status.red_lamp=GPIO_Output_Mode::flashing;           // red 
    light_tower_Status.orange_lamp=GPIO_Output_Mode::off;             // orange
    light_tower_Status.green_lamp=GPIO_Output_Mode::off;              // green
  }
  else if (Maschine_State.State_current== State::CheckMode){          // Checkmode = red blinking
    light_tower_Status.red_lamp=GPIO_Output_Mode::blinking;           // red 
    light_tower_Status.orange_lamp=GPIO_Output_Mode::off;             // orange
    light_tower_Status.green_lamp=GPIO_Output_Mode::off;    
  }
  else if (Maschine_State.State_current== State::Run){                // Run = orange on
    light_tower_Status.red_lamp=GPIO_Output_Mode::off;                // red 
    light_tower_Status.orange_lamp=GPIO_Output_Mode::on;              // orange
    light_tower_Status.green_lamp=GPIO_Output_Mode::off;              // green
  }
  else if (Maschine_State.State_current== State::Hold){               // Hold = orange on & red flashing
    light_tower_Status.red_lamp=GPIO_Output_Mode::flashing;           // red 
    light_tower_Status.orange_lamp=GPIO_Output_Mode::on;              // orange
    light_tower_Status.green_lamp=GPIO_Output_Mode::off;              // green
  }
  else if (Maschine_State.State_current== State::Jog){                // Jog = orange blinking
    light_tower_Status.red_lamp=GPIO_Output_Mode::off;                // red 
    light_tower_Status.orange_lamp=GPIO_Output_Mode::blinking;        // orange
    light_tower_Status.green_lamp=GPIO_Output_Mode::off;              // green
  }
  else if (Maschine_State.State_current== State::SafetyDoor){         // SafetyDoor = red flashing
    light_tower_Status.red_lamp=GPIO_Output_Mode::flashing;           // red 
    light_tower_Status.orange_lamp=GPIO_Output_Mode::off;             // orange
    light_tower_Status.green_lamp=GPIO_Output_Mode::off;              // green
  }
  else if (Maschine_State.State_current== State::Sleep){              // Sleep = all off
    light_tower_Status.red_lamp=GPIO_Output_Mode::off;                // red 
    light_tower_Status.orange_lamp=GPIO_Output_Mode::off;             // orange
    light_tower_Status.green_lamp=GPIO_Output_Mode::off;              // green
  }
  else if (Maschine_State.State_current== State::ConfigAlarm){        // Config Alarm = red blinking
    light_tower_Status.red_lamp=GPIO_Output_Mode::blinking;           // red 
    light_tower_Status.orange_lamp=GPIO_Output_Mode::off;             // orange
    light_tower_Status.green_lamp=GPIO_Output_Mode::off;              // green
  }
}