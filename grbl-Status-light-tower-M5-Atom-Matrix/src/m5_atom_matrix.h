#include <Arduino.h>
#include "M5Atom.h"
//********************************* M5 Stack Atom Matix Setup ************* //
void m5_atom_matrix_setup() {                                               // Setup M5 Atom Matrix
  M5.begin(true, false, true);                                              // Init Atom-Matrix(Initialize serial port, LED).  
  delay(50);                                                                // short delay 50ms. 
  M5.dis.drawpix(12, 0xffffff);                                             // Light the LED with the specified RGB color
  delay(150);                                                               // delay 150ms. for white Start Pix show
}

//****************************** M5 Stack Atom Matrix Update *************  //
void m5_atom_matrix_update() {                                              // M5 Atom Display Update
  bool update_needed = false;                                               // is update needed
  if (uart_cnc_read_raw.last_string_reveive_millis + 1000 < millis()){
    Maschine_State.State_current = State::Alarm;
  }
  if (uart_cnc_read_raw.heart_beat_current != uart_cnc_read_raw.heart_beat_last){
    uart_cnc_read_raw.heart_beat_last = uart_cnc_read_raw.heart_beat_current;
    update_needed = true;
  }  
  if (Maschine_State.State_old != Maschine_State.State_current){
    update_needed = true;
    Maschine_State.State_old = Maschine_State.State_current;
    uart_cnc_read_raw.heart_beat_last = uart_cnc_read_raw.heart_beat_current;
  }
  if (update_needed){
    if (uart_cnc_read_raw.heart_beat_current == true){                            // Heart Beat
      M5.dis.setBrightness(100) ;                                                 // Brightness 100%
    }
    else {
      M5.dis.setBrightness(80) ;                                                  // Brightness 80%
    }
    
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
}