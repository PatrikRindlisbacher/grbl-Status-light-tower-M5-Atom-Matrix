#include <Arduino.h>

//******************* L I G H T  T O W E R  S T A T U S  *********************//
//******Here the machine status is assigned to the GPIO_Output_Conditions ****//
void grbl_hub_light_tower_status_update(){
  if (Maschine_State.State_current== State::Idle){                            // Idle = green on
    light_tower_Status.red_lamp=GPIO_Output_Conditions::off;                  // red      GPIO Conditions
    light_tower_Status.orange_lamp=GPIO_Output_Conditions::off;               // orange   GPIO Conditions
    light_tower_Status.green_lamp=GPIO_Output_Conditions::on;                 // green    GPIO Conditions
  }
  else if (Maschine_State.State_current== State::Alarm){                      // Alarm = red flashing
    light_tower_Status.red_lamp=GPIO_Output_Conditions::flashing;             // red      GPIO Conditions
    light_tower_Status.orange_lamp=GPIO_Output_Conditions::off;               // orange   GPIO Conditions
    light_tower_Status.green_lamp=GPIO_Output_Conditions::off;                // green    GPIO Conditions
  }
  else if (Maschine_State.State_current== State::CheckMode){                  // Checkmode = red blinking
    light_tower_Status.red_lamp=GPIO_Output_Conditions::blinking;             // red      GPIO Conditions
    light_tower_Status.orange_lamp=GPIO_Output_Conditions::off;               // orange   GPIO Conditions
    light_tower_Status.green_lamp=GPIO_Output_Conditions::off;                // green    GPIO Conditions   
  }
  else if (Maschine_State.State_current== State::Run){                        // Run = orange on
    light_tower_Status.red_lamp=GPIO_Output_Conditions::off;                  // red      GPIO Conditions
    light_tower_Status.orange_lamp=GPIO_Output_Conditions::on;                // orange   GPIO Conditions
    light_tower_Status.green_lamp=GPIO_Output_Conditions::off;                // green    GPIO Conditions
  }
  else if (Maschine_State.State_current== State::Hold){                       // Hold = orange on & red flashing
    light_tower_Status.red_lamp=GPIO_Output_Conditions::flashing;             // red      GPIO Conditions
    light_tower_Status.orange_lamp=GPIO_Output_Conditions::on;                // orange   GPIO Conditions
    light_tower_Status.green_lamp=GPIO_Output_Conditions::off;                // green    GPIO Conditions
  }
  else if (Maschine_State.State_current== State::Jog){                        // Jog = orange blinking
    light_tower_Status.red_lamp=GPIO_Output_Conditions::off;                  // red      GPIO Conditions
    light_tower_Status.orange_lamp=GPIO_Output_Conditions::blinking;          // orange   GPIO Conditions
    light_tower_Status.green_lamp=GPIO_Output_Conditions::off;                // green    GPIO Conditions
  }
  else if (Maschine_State.State_current== State::SafetyDoor){                 // SafetyDoor = red flashing
    light_tower_Status.red_lamp=GPIO_Output_Conditions::flashing;             // red      GPIO Conditions
    light_tower_Status.orange_lamp=GPIO_Output_Conditions::off;               // orange   GPIO Conditions
    light_tower_Status.green_lamp=GPIO_Output_Conditions::off;                // green    GPIO Conditions
  }
  else if (Maschine_State.State_current== State::Sleep){                      // Sleep = all off
    light_tower_Status.red_lamp=GPIO_Output_Conditions::off;                  // red      GPIO Conditions
    light_tower_Status.orange_lamp=GPIO_Output_Conditions::off;               // orange   GPIO Conditions
    light_tower_Status.green_lamp=GPIO_Output_Conditions::off;                // green    GPIO Conditions
  }
  else if (Maschine_State.State_current== State::ConfigAlarm){                // Config Alarm = red blinking
    light_tower_Status.red_lamp=GPIO_Output_Conditions::blinking;             // red      GPIO Conditions
    light_tower_Status.orange_lamp=GPIO_Output_Conditions::off;               // orange   GPIO Conditions
    light_tower_Status.green_lamp=GPIO_Output_Conditions::off;                // green    GPIO Conditions
  }
}