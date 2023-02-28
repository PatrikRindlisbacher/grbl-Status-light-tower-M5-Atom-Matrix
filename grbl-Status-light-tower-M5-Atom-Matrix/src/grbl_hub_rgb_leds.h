#include <Arduino.h>
#if  NUM_RGB_LEDS > 0
Adafruit_NeoPixel pixels(NUM_RGB_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);
#endif
//**************************** All RGB LED's Neopixel red ***********************//
void rgb_all_red(){
  for(int i=0; i<NUM_RGB_LEDS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
}
//*************************** All RGB LED's Neopixel orange ********************//
void rgb_all_orange(){
  for(int i=0; i<NUM_RGB_LEDS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(255, 80, 10));
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
}
//************************** All RGB LED's Neopixel green **********************//
void rgb_all_green(){
  for(int i=0; i<NUM_RGB_LEDS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
}

//****************************** Setup RGB LED's Neopixel***********************//
void grbl_hub_rgb_led_setup(){                                                  //
  pixels.begin();                                                               // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();                                                               // Set all pixel colors to 'off'
  rgb_all_green();                                                              // Set all pixel color green
  delay(200);                                                                   // short delay
  rgb_all_orange();                                                             // Set all pixel color green
  delay(200);                                                                   // short delay
  rgb_all_red();                                                                // Set all pixel color RED (default Startup)
}

//***************************** RGB LED needed Update **************************  //
bool grbl_hub_rgb_led_update_needed(){                                            // update needed for RGB Led's
  if (uart_cnc_read_raw.last_string_reveive_millis + 1000 < millis()){            // if no message arrives for a long time
    Maschine_State.State_current = State::Alarm;                                  // change Maschine State = Alarm
  }
  // if (uart_cnc_read_raw.heart_beat_current != uart_cnc_read_raw.heart_beat_last){
  //   uart_cnc_read_raw.heart_beat_last = uart_cnc_read_raw.heart_beat_current;
  //   return true;
  // }  
  if (Maschine_State.State_old != Maschine_State.State_current){                  // if change Maschine State
    Maschine_State.State_old = Maschine_State.State_current;                      // old State = current State
    uart_cnc_read_raw.heart_beat_last = uart_cnc_read_raw.heart_beat_current;     //
    return true;                                                                  //
  }
  else {
      return false;                                                               //
  }
}

//****************************** RGB Led 1x10  Matrix Update *********************// LED STRIPE All the same Collor
#ifdef RGB_LED_STRIPE_ONE_COLOR                                                   // Built Flag --> RGB_LED_STRIPE_ONE_COLOR
void rgb_led_stripe_one_Color_update() {                                          // RGB Led update
  if (Maschine_State.State_current == State::Idle){                               // Idle
    rgb_all_green();                                                              // LED Color Update
  }
  else if(Maschine_State.State_current == State::Alarm){                          // Alarm
    rgb_all_red();                                                                // LED Color Update
  }
  else if(Maschine_State.State_current == State::CheckMode){                      // Checkmode
    rgb_all_red();                                                                // LED Color Update
  }
  else if(Maschine_State.State_current == State::Homing){                         // Homing
    rgb_all_orange();                                                             // LED Color Update
  }
  else if(Maschine_State.State_current == State::Run){                            // Run
    rgb_all_orange();                                                             // LED Color Update
  }
  else if(Maschine_State.State_current == State::Hold){                           // Hold
    rgb_all_red();                                                                // LED Color Update
  }
  else if(Maschine_State.State_current == State::Jog){                            // Jog
    rgb_all_orange();                                                             // LED Color Update
  }
  else if(Maschine_State.State_current == State::SafetyDoor){                     // SafetyDoor
    rgb_all_red();                                                                // LED Color Update
  }
  else if(Maschine_State.State_current == State::Sleep){                          // Sleep
    rgb_all_red();                                                                // LED Color Update
  }
  else if(Maschine_State.State_current == State::ConfigAlarm){                    // ConfigAlarm
    rgb_all_red();                                                                // LED Color Update
  }
}
#endif

//****************************** RGB Led  Update *********************************// RGB Led update
void grbl_hub_rgb_led_update(){                                                   // rgb LED update
  bool update_needed = grbl_hub_rgb_led_update_needed();                          // is led update needed
  if (update_needed){                                                             // LED Update needed 
    #ifdef RGB_LED_STRIPE_ONE_COLOR                                               // BuiltFlag RGB_LED_STRIPE_ONE_COLOR
      rgb_led_stripe_one_Color_update();                                          // Update Led Matrix all LED same Color
    // #elif defined(RGB_LED_1x1)                                                 // BuiltFlag ??
    //   rgb_led_stripe_one_Color_update();                                       // Update ??
    #endif                                                                        // 
  }
}
