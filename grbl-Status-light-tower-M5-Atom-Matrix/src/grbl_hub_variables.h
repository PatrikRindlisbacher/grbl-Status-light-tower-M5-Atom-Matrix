#include <Arduino.h>
//******************************** G R B L  M A S C H I N E  S T A T U S *****************//
enum class State : uint8_t {
  Idle = 0,           // I Green Must be zero.
  Alarm,              // A Red   In alarm state. Locks out all g-code processes. Allows settings access.
  CheckMode,          // C G-code check mode. Locks out planner and motion only.
  Homing,             // H Performing homing cycle
  Run,                // R orange Cycle is running or motions are being executed.
  Hold,               // H Active feed hold
  Jog,                // J Jogging mode.
  SafetyDoor,         // D Safety door is ajar. Feed holds and de-energizes system.
  Sleep,              // S Sleep state.
  ConfigAlarm,        // A You can't do anything but fix your config file.
};
//******************************** G R B L  M E S S A G E  T Y P E  *********************//
enum class Message_Type : uint8_t {
  none = 0,           //  none grbl Message
  reportData,         // < > : Enclosed between chevrons. Contains status report data.
  intit,              // Grbl X.Xx indicates initialization.
  alarm,              // ALARM:x : Indicates an alarm has been thrown. Grbl is now in an alarm state.
  printout,           // $x=val and $Nx=line indicate a settings printout from a $ and $N user query, respectively.
  msg,                // [MSG:] : Indicates a non-queried feedback message.
  gc,                 // [GC:] : Indicates a queried $G g-code state message.
  hlp,                // [HLP:] : Indicates the help message.
  G,                  // [G54:], [G55:], [G56:], [G57:], [G58:], [G59:], [G28:], [G30:], [G92:], [TLO:], and [PRB:] messages indicate the parameter data printout from a $# user query
  ver,                // [VER:] : Indicates build info and string from a $I user query.
  echo,               // [echo:] : Indicates an automated line echo from a pre-parsed string prior to g-code parsing. Enabled by config.h option.
  startup,            // >G54G20:ok : The open chevron indicates startup line execution. The :ok suffix shows it executed correctly without adding an unmatched ok response on a new line.
};

//******************************** R A W   D A T A  G R B L  M E S S A G E  **********************//
struct raw_uart_cnc_read_t {                                                                      // Alle Status Variablen 
  String  Message = "";   
  boolean Message_Available = false;
  Message_Type Message_Typ = Message_Type::none;                                                  // If a complete string received from GRBL
  uint32_t last_char_reveive_millis = 0;                                                          // Last Char receive
  uint32_t last_string_reveive_millis = 0;                                                        // Last String receive
  uint32_t last_grbl_status_update =0;
  bool heart_beat_current = false;
  bool heart_beat_last = false;
 } uart_cnc_read_raw ;

//******************************** M A S C H I N E  S T A T E  ***********************************//
struct Maschine_State_t {                                                                         // Maschine Status Information
  State State_current = State::Sleep;
  State State_old = State::Sleep;                                                                 // Maschine State Number
  String  Machine_State_String = "";                                                              // Maschine State Text
}Maschine_State ;


//*************************** G P I O  O U T P U T   M O D E  ***************************//
enum class GPIO_Output_Mode : uint8_t {
    off = 0,                              // GPIO / lamp / LED  is off
    on ,                                  // GPIO / lamp / LED  is on
    blinking,                             // GPIO / lamp / LED  is blinking
    flashing,                             // GPIO / lamp / LED  is flashing
};

//******************************** L I G H T  T O W E R   S T A T E  *******************************//
struct light_tower_Status_t {                                // Light Tower Status 
  GPIO_Output_Mode red_lamp;
  GPIO_Output_Mode orange_lamp;
  GPIO_Output_Mode green_lamp;
} light_tower_Status ;
