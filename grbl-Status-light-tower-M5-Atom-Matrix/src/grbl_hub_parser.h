#include <Arduino.h>

Message_Type grbl_Message_Type(String grbl_message){                                              // message Type find out
  grbl_message.toUpperCase();                                                                     // message to Upper Case
  if (grbl_message.startsWith("<")){return Message_Type::reportData ;}                            // start with ok        --> Return 1 = OK  
  else {return Message_Type::none; }   
}

State grbl_Maschine_State(String grbl_message){                                                    // Return message typ an int
  grbl_message.toUpperCase();                                                                     // message to Upper Case
  if (grbl_message.startsWith("<IDLE")){return State::Idle ;}                                                   // start with ok        --> Return 1 = OK  
  else if (grbl_message.startsWith("<HOMING")){return State::Homing;}                                               // start with chevrons  --> Return 2 = Real-time status report data
  else if (grbl_message.startsWith("<RUN")){return State::Run;}                                               // start with chevrons  --> Return 2 = Real-time status report data
  else if (grbl_message.startsWith("<JOG")){return State::Jog;}                                          // start with ALARM:    --> Return 3 = Alarm$
  else if (grbl_message.startsWith("<HOLD")){return State::Hold;}                                          // start with ALARM:    --> Return 3 = Alarm
  else if (grbl_message.startsWith("<DOOR")){return State::SafetyDoor;}                                          // start with ALARM:    --> Return 3 = Alarm
  else if (grbl_message.startsWith("<ALARM")){return State::Alarm;}                                          // start with ALARM:    --> Return 3 = Alarm
  else if (grbl_message.startsWith("<SLEEP")){return State::Sleep;}                                          // start with error:    --> Return 4 = error
  else {return State::Sleep; }                                
}

String grbl_message_clean_chevrons(String grbl_message){                                          // Remove chevrons and message to Upper Case
  int startPos = grbl_message.indexOf("<");                                                       // Pos <
  int endPos = grbl_message.indexOf(">");                                                         // Pos >
  grbl_message = grbl_message.substring(startPos+1, endPos-0);                                    // Substring without chevrons
  return grbl_message;                                                                            // Return without chevrons
}

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

void grbl_status_update_request(){
  if (uart_cnc_read_raw.last_grbl_status_update + 500 < millis()){
    Serial2.print("?");  
    uart_cnc_read_raw.last_grbl_status_update= millis();
  }
}
