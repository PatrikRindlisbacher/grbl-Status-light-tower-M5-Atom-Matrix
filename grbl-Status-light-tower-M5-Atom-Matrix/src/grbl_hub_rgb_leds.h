#include <Arduino.h>

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

//****************************** RGB Led 5x5  Matrix Update **********************// 1x1 Matrix RGB Led (M5 Atom-Lite)
#ifdef RGB_LED_1x1                                                                // Built Flag --> RGB_LED_1x1
void rgb_led_1x1_matrix_update() {                                                // RGB Led update
  if (Maschine_State.State_current == State::Idle){                               // Idle
    M5.dis.drawpix(0,0x00ff00);                                                   // LED Color Update
  }
  else if(Maschine_State.State_current == State::Alarm){                          // Alarm
    M5.dis.drawpix(0,0xff0000);                                                   // LED Color Update
  }
  else if(Maschine_State.State_current == State::CheckMode){                      // Checkmode
    M5.dis.drawpix(0,0xff0000);                                                   // LED Color Update
  }
  else if(Maschine_State.State_current == State::Homing){                         // Homing
    M5.dis.drawpix(0,0xffaa00);                                                   // LED Color Update
  }
  else if(Maschine_State.State_current == State::Run){                            // Run
    M5.dis.drawpix(0,0xffaa00);                                                   // LED Color Update
  }
  else if(Maschine_State.State_current == State::Hold){                           // Hold
    M5.dis.drawpix(0,0xffaa00);                                                   // LED Color Update
  }
  else if(Maschine_State.State_current == State::Jog){                            // Jog
    M5.dis.drawpix(0,0xffaa00);                                                   // LED Color Update
  }
  else if(Maschine_State.State_current == State::SafetyDoor){                     // SafetyDoor
    M5.dis.drawpix(0,0xff0000);                                                   // LED Color Update
  }
  else if(Maschine_State.State_current == State::Sleep){                          // Sleep
    M5.dis.drawpix(0,0x000000);                                                   // LED Color Update
  }
  else if(Maschine_State.State_current == State::ConfigAlarm){                    // ConfigAlarm
    M5.dis.drawpix(0,0xff0000);                                                   // LED Color Update
  }
}
#endif

//****************************** RGB Led 5x5  Matrix Update **********************// 5x5 Matrix RGB Led (M5 Atom-Matrix)
#ifdef RGB_LED_5x5
void rgb_led_5x5_matrix_update() {                                                // RGB Led update
                                                   // 
    // if (uart_cnc_read_raw.heart_beat_current == true){                         // Heart Beat
    //   M5.dis.setBrightness(100) ;                                              // Brightness 100%
    // }
    // else {
    //   M5.dis.setBrightness(80) ;                                               // Brightness 80%
    // }
    
    if (Maschine_State.State_current == State::Idle){                             // Idle
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.drawpix(1,0x00ff00);
      M5.dis.drawpix(2,0x00ff00);
      M5.dis.drawpix(3,0x00ff00);
      M5.dis.drawpix(7,0x00ff00);
      M5.dis.drawpix(12,0x00ff00);
      M5.dis.drawpix(17,0x00ff00);
      M5.dis.drawpix(21,0x00ff00);
      M5.dis.drawpix(22,0x00ff00);
      M5.dis.drawpix(23,0x00ff00);
    }
    else if(Maschine_State.State_current == State::Alarm){                        // Alarm
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.drawpix(1,0xff0000);
      M5.dis.drawpix(2,0xff0000);
      M5.dis.drawpix(5,0xff0000);
      M5.dis.drawpix(8,0xff0000);
      M5.dis.drawpix(10,0xff0000);
      M5.dis.drawpix(11,0xff0000);
      M5.dis.drawpix(12,0xff0000);
      M5.dis.drawpix(13,0xff0000);
      M5.dis.drawpix(15,0xff0000);
      M5.dis.drawpix(18,0xff0000);
      M5.dis.drawpix(20,0xff0000);
      M5.dis.drawpix(23,0xff0000);        
    }
    else if(Maschine_State.State_current == State::CheckMode){                    // Checkmode
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.fillpix(0xff0000);                                                   // Fill Matrix Color
    }
    else if(Maschine_State.State_current == State::Homing){                       // Homing
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.fillpix(0xffaa00);                                                   // Fill Matrix Color
    }
    else if(Maschine_State.State_current == State::Run){                          // Run
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.drawpix(0,0xffaa00);
      M5.dis.drawpix(1,0xffaa00);
      M5.dis.drawpix(2,0xffaa00);
      M5.dis.drawpix(3,0xffaa00);
      M5.dis.drawpix(5,0xffaa00);
      M5.dis.drawpix(8,0xffaa00);
      M5.dis.drawpix(10,0xffaa00);
      M5.dis.drawpix(11,0xffaa00);
      M5.dis.drawpix(12,0xffaa00);
      M5.dis.drawpix(13,0xffaa00);
      M5.dis.drawpix(15,0xffaa00);
      M5.dis.drawpix(17,0xffaa00);
      M5.dis.drawpix(20,0xffaa00);
      M5.dis.drawpix(23,0xffaa00);  
    }
    else if(Maschine_State.State_current == State::Hold){                         // Hold
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.drawpix(0,0xffaa00);
      M5.dis.drawpix(3,0xffaa00);
      M5.dis.drawpix(5,0xffaa00);
      M5.dis.drawpix(8,0xffaa00);
      M5.dis.drawpix(10,0xffaa00);
      M5.dis.drawpix(11,0xffaa00);
      M5.dis.drawpix(12,0xffaa00);
      M5.dis.drawpix(13,0xffaa00);
      M5.dis.drawpix(15,0xffaa00);
      M5.dis.drawpix(18,0xffaa00);
      M5.dis.drawpix(20,0xffaa00);
      M5.dis.drawpix(23,0xffaa00);  
    }
    else if(Maschine_State.State_current == State::Jog){                          // Jog
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.fillpix(0xffaa00);                                                   // Fill Matrix Color
    }
    else if(Maschine_State.State_current == State::SafetyDoor){                   // SafetyDoor
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.fillpix(0xff0000);                                                   // Fill Matrix Color
    }    
    else if(Maschine_State.State_current == State::Sleep){                        // Sleep
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.fillpix(0xff0000);                                                   // Fill Matrix Color
    } 
    else if(Maschine_State.State_current == State::ConfigAlarm){                  // ConfigAlarm
      M5.dis.clear();                                                             // Clear Display Matrix
      M5.dis.fillpix(0xff0000);                                                   // Fill Matrix Color
    } 
  }
#endif

//****************************** RGB Led  Update *********************************// RGB Led update
void grbl_hub_rgb_led_update(){                                                   // rgb LED update
  bool update_needed = grbl_hub_rgb_led_update_needed();                          // is led update needed
  if (update_needed){                                                             // LED Update needed 
    #ifdef RGB_LED_5x5                                                            // BuiltFlag RGB_LED_5x5
      rgb_led_5x5_matrix_update();                                                // Update 5x5 Led Matrix
    #elif defined(RGB_LED_1x1)                                                    // BuiltFlag RGB_LED_5x5
      rgb_led_1x1_matrix_update();                                                // Update 1x1 Led
    #endif                                                                        // 
  }
}
