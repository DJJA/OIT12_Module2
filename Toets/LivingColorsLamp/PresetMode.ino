void presetMode(){
  static byte led = 0;

  if(mBtnPresetMode.IsButtonReleased(mPinSwitchPreset)){
    led++;
    if(led == 3)
      led = 0;
  }

  switch(led){
      case 0:
        showYellow();
        break;
      case 1:
        showCyan();
        break;
      case 2:
        showMagenta();
        break;
     }
}

