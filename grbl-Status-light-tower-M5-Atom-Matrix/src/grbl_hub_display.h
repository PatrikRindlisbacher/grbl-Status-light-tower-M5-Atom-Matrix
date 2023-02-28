#include <Arduino.h>   

void grbl_hub_display_update(){
#ifdef BOARD_HAS_DISPLAY
  tftSprite.drawNumber(int(Maschine_State.State_current),50,50);
  tftSprite.drawString(Maschine_State.Machine_State_String,50,100);
  tftSprite.pushSprite(0, 0);                                                                   // Sprite kopieren
#endif
}

//-------------------------------- Anzeige Vorbereiten  ------------------------------------------//
void ui_anzeige_setup(){                                                                          // Initialisieren Anzeige
#ifdef BOARD_HAS_DISPLAY
  lcd.init();
  lcd.setRotation(1);
  lcd.setBrightness(128);
  tftSprite.setColorDepth(8);     // 4ビット(16色)パレットモードに設定
  tftSprite.createSprite(320, 240);
  tftSprite.setFont(&FreeSans12pt7b);                                                           // Schiftart
#endif
}

