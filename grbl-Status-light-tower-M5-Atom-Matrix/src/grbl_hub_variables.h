#include <Arduino.h>
//******************************** G R B L  M A S C H I N E  S T A T U S *****************//
enum class State : uint8_t {
  Idle = 0,                 // I Idle = Zero
  Alarm,                    // A In alarm state. Locks out all g-code processes. Allows settings access.
  CheckMode,                // C G-code check mode. Locks out planner and motion only.
  Homing,                   // H Performing homing cycle
  Run,                      // R Run Cycle is running or motions are being executed.
  Hold,                     // H Active feed hold
  Jog,                      // J Jogging mode.
  SafetyDoor,               // D Safety door is ajar. Feed holds and de-energizes system.
  Sleep,                    // S Sleep state.
  ConfigAlarm,              // A You can't do anything but fix your config file.
};
//******************************** G R B L  M E S S A G E  T Y P E  *********************//
enum class Message_Type : uint8_t {
  none = 0,                 //  none grbl Message
  reportData,               // < > : Enclosed between chevrons. Contains status report data.
  init,                     // Grbl X.Xx indicates initialization.
  alarm,                    // ALARM:x : Indicates an alarm has been thrown. Grbl is now in an alarm state.
  printout,                 // $x=val and $Nx=line indicate a settings printout from a $ and $N user query, respectively.
  msg,                      // [MSG:] : Indicates a non-queried feedback message.
  gc,                       // [GC:] : Indicates a queried $G g-code state message.
  hlp,                      // [HLP:] : Indicates the help message.
  G,                        // [G54:], [G55:], [G56:], [G57:], [G58:], [G59:], [G28:], [G30:], [G92:], [TLO:], and [PRB:] messages indicate the parameter data printout from a $# user query
  ver,                      // [VER:] : Indicates build info and string from a $I user query.
  echo,                     // [echo:] : Indicates an automated line echo from a pre-parsed string prior to g-code parsing. Enabled by config.h option.
  startup,                  // >G54G20:ok : The open chevron indicates startup line execution. The :ok suffix shows it executed correctly without adding an unmatched ok response on a new line.
};

//************************** R A W   D A T A  G R B L  M E S S A G E  ********************// structure type
struct raw_uart_cnc_read_t {                                                              // Alle Status Variablen 
  String  Message = "";                                                                   // Message from CNC UART
  boolean Message_Available = false;                                                      // New Message Available
  Message_Type Message_Typ = Message_Type::none;                                          // If a complete string received from GRBL
  uint32_t last_char_reveive_millis = 0;                                                  // Last Char receive
  uint32_t last_string_reveive_millis = 0;                                                // Last String receive
  uint32_t last_grbl_status_update = 0;                                                   // Last Status receive
  bool heart_beat_current = false;                                                        // Heart Beat / Watch Dog
  bool heart_beat_last = false;                                                           // Heart Beat / Watch Dog
 } uart_cnc_read_raw ;

//******************************** M A S C H I N E  S T A T E  ************************** // structure type
struct Maschine_State_t {                                                                 // Maschine Status Information
  State State_current = State::Sleep;                                                     // Start State Sleep
  State State_old = State::Sleep;                                                         // Maschine State old
  String  Machine_State_String = "";                                                      // Maschine State For language translations
}Maschine_State ;

//********************* G P I O  O U T P U T   C O N D I T I O N S  ********************* // enum class
enum class GPIO_Output_Conditions : uint8_t {                                             // GPIO CONDITIONS  ON OFF BLINK FLASH
    off = 0,                                                                              // GPIO / lamp / LED  is off
    on ,                                                                                  // GPIO / lamp / LED  is on
    blinking,                                                                             // GPIO / lamp / LED  is blinking
    flashing,                                                                             // GPIO / lamp / LED  is flashing
};

//******************************** L I G H T  T O W E R   S T A T E  *********************// structure type
struct light_tower_Status_t {                                                             // Light Tower Status 
  GPIO_Output_Conditions red_lamp;                                                        // CONDITION RED      (ON OFF BLINK FLASH)
  GPIO_Output_Conditions orange_lamp;                                                     // CONDITION Organge  (ON OFF BLINK FLASH)
  GPIO_Output_Conditions green_lamp;                                                      // CONDITION Green    (ON OFF BLINK FLASH)
} light_tower_Status ;                                                                    // 


//********************* BLINK & Flash for all GPIO's at the same time ********************// structure type
struct blink_and_flash_t {                                                                // All blink_and_flash vars 
  uint32_t blink_duration_on = 1000;                                                      // Blink duration ON
  uint32_t blink_duration_off = 1000;                                                     // Blink duration OFF
  uint32_t flash_duration_on = 100;                                                       // Flash duration ON
  uint32_t flash_duration_off = 1900;                                                     // Flash duration OFF
  uint32_t last_blink_start_millis = 0;                                                   // Last Start Blink in millis seconds
  uint32_t last_flash_start_millis = 0;                                                   // Last Start Flash in millis seconds
 } blink_and_flash ;
