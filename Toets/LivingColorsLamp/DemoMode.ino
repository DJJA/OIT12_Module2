void demoMode(){
  static unsigned long timeLastColorChange = 1000;  // 1000 ms so the led is not turned off when the program starts
  static byte iCurColor = 0;                        // Used to indicate what the current color is

  unsigned long curMillis = millis();
  
  if((curMillis - timeLastColorChange) >= 1000){    // Check if 1 second has passed
    timeLastColorChange = curMillis;
    
    switch(iCurColor){
      case 0:
        setColor(255,0,0);
        iCurColor = 1;
        break;
      case 1:
        setColor(0,255,0);
        iCurColor = 2;
        break;
      case 2:
        setColor(0,0,255);
        iCurColor = 0;
     }
  }
}

