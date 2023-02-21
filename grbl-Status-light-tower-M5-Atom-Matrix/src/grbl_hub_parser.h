#include <Arduino.h>
// **************************************  Message Typ  ************************************//
Message_Type grbl_Message_Type(String grbl_message){                                        // find out the message Type
  grbl_message.toUpperCase();                                                               // message to Upper Case
  if (grbl_message.startsWith("<")){return Message_Type::reportData ;}                      // start with "<"  Message_Type --> reportData        
  else {return Message_Type::none; }   
}
// **************************** Current Maschine State  ************************************//
State grbl_Maschine_State(String grbl_message){                                             // find out the Maschine State
  grbl_message.toUpperCase();                                                               // message to Upper Case
  if (grbl_message.startsWith("<IDLE")){return State::Idle ;}                               // start with <IDLE
  else if (grbl_message.startsWith("<HOMING")){return State::Homing;}                       // start with <Homing
  else if (grbl_message.startsWith("<RUN")){return State::Run;}                             // start with <Run
  else if (grbl_message.startsWith("<JOG")){return State::Jog;}                             // start with <Jog
  else if (grbl_message.startsWith("<HOLD")){return State::Hold;}                           // start with <Hold
  else if (grbl_message.startsWith("<DOOR")){return State::SafetyDoor;}                     // start with <SafetyDoor
  else if (grbl_message.startsWith("<ALARM")){return State::Alarm;}                         // start with <Alarm
  else if (grbl_message.startsWith("<SLEEP")){return State::Sleep;}                         // start with <Sleep
  else {return State::Sleep; }                                                              // Default Sleep
}
// ******************************* Message without <>  *************************************//
String grbl_message_clean_chevrons(String grbl_message){                                    // Remove chevrons and message to Upper Case
  int startPos = grbl_message.indexOf("<");                                                 // Pos <
  int endPos = grbl_message.indexOf(">");                                                   // Pos >
  grbl_message = grbl_message.substring(startPos+1, endPos-0);                              // Substring without chevrons
  return grbl_message;                                                                      // Return without chevrons
}                                                                                           //

// ************************************** Main Parser  *************************************//
void grbl_Message_main_parser(){                                                            // GRBL main Parser 
  if (uart_cnc_read_raw.Message_Available == true) {                                        // Check if raw Message String Available
    uart_cnc_read_raw.Message_Typ = grbl_Message_Type(uart_cnc_read_raw.Message);           // find out the message Type
    if (uart_cnc_read_raw.Message_Typ == Message_Type::reportData){                         // if reportData
      Maschine_State.State_current = grbl_Maschine_State(uart_cnc_read_raw.Message);        // find out the Maschine State
    }                                                                                       //
    uart_cnc_read_raw.Message_Available = false;                                            // message is processed
    uart_cnc_read_raw.Message = "";                                                         // delete current message
    uart_cnc_read_raw.last_string_reveive_millis= millis();                                 // Last message reveive_millis
    uart_cnc_read_raw.heart_beat_current = !uart_cnc_read_raw.heart_beat_current;           // heartbeat for UART Communication
  };                                                                                        //
}

// ************************** Request to the CNC controller  *******************************//
void grbl_status_update_request(){                                                          // status request
  if (uart_cnc_read_raw.last_grbl_status_update + 500 < millis()){                          // all 500ms
    Serial2.print("?");                                                                     // send ? to the CNC Controller
    uart_cnc_read_raw.last_grbl_status_update = millis();                                   // notice last request
  }
}
