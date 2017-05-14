void presetMode(){
  static byte led = 0;

  if(mBtnPresetMode.IsButtonReleased(mPinSwitchPreset)){
    led++;
    if(led == 3)
      led = 0;
  }

  switch(led){                  // Is this bad, writing color when it's not changing?
      case 0:
        setColor(255,255,0);
        break;
      case 1:
        setColor(0,255,255);
        break;
      case 2:
        setColor(255,0,255);
     }
}

