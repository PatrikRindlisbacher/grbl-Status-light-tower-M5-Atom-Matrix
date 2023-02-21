#include <Arduino.h>
// ***********************************  Message Typ  ************************************//
Message_Type grbl_Message_Type(String grbl_message){                                     // find out the message Type 
  grbl_message.toUpperCase();                                                            // message to Upper Case
  if (grbl_message.startsWith("<")){return Message_Type::reportData ;}                   // start with "<"  Message_Type --> reportData        
  else {return Message_Type::none; }   
}
// *************************** Current Maschine State  ************************************//
State grbl_Maschine_State(String grbl_message){                                            // Return Maschine as State
  grbl_message.toUpperCase();                                                              // message to Upper Case
  if (grbl_message.startsWith("<IDLE")){return State::Idle ;}                              // start with <IDLE
  else if (grbl_message.startsWith("<HOMING")){return State::Homing;}                      // start with <Homing
  else if (grbl_message.startsWith("<RUN")){return State::Run;}                            // start with <Run
  else if (grbl_message.startsWith("<JOG")){return State::Jog;}                            // start with <Jog
  else if (grbl_message.startsWith("<HOLD")){return State::Hold;}                          // start with <Hold
  else if (grbl_message.startsWith("<DOOR")){return State::SafetyDoor;}                    // start with <SafetyDoor
  else if (grbl_message.startsWith("<ALARM")){return State::Alarm;}                        // start with <Alarm
  else if (grbl_message.startsWith("<SLEEP")){return State::Sleep;}                        // start with <Sleep
  else {return State::Sleep; }                                
}
// ******************************* Message without <>  ************************************//
String grbl_message_clean_chevrons(String grbl_message){                                   // Remove chevrons and message to Upper Case
  int startPos = grbl_message.indexOf("<");                                                // Pos <
  int endPos = grbl_message.indexOf(">");                                                  // Pos >
  grbl_message = grbl_message.substring(startPos+1, endPos-0);                             // Substring without chevrons
  return grbl_message;                                                                     // Return without chevrons
}

// ************************************** Main Parser  ************************************//
void grbl_Message_main_parser(){                                                                  // GRBL Parser main
  if (uart_cnc_read_raw.Message_Available == true) {                                              // Check if raw Message String Available
    uart_cnc_read_raw.Message_Typ = grbl_Message_Type(uart_cnc_read_raw.Message);
    
    if (uart_cnc_read_raw.Message_Typ == Message_Type::reportData){
      Maschine_State.State_current = grbl_Maschine_State(uart_cnc_read_raw.Message); 
    }
    uart_cnc_read_raw.Message_Available = false;
    uart_cnc_read_raw.Message = "";
    uart_cnc_read_raw.last_string_reveive_millis= millis();
    uart_cnc_read_raw.heart_beat_current = !uart_cnc_read_raw.heart_beat_current;
  };
}

// *************************** Request to the CNC controller  ************************************//
void grbl_status_update_request(){
  if (uart_cnc_read_raw.last_grbl_status_update + 500 < millis()){
    Serial2.print("?");  
    uart_cnc_read_raw.last_grbl_status_update= millis();
  }
}
