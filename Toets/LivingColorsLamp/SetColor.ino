void setColor(int r, int g, int b){    // Set RGB color
  if(r != mRedValue){
    mRedChanged = true;
    mRedValue = r;
    analogWrite(mPinLedRed, r);
  }
  if(g != mGreenValue){
    mGreenChanged = true;
    mGreenValue = g;
    analogWrite(mPinLedGreen, g);
  }
  if(b != mBlueValue){
    mBlueChanged = true;
    mBlueValue = b;
    analogWrite(mPinLedBlue, b);
  }
}

void setRed(byte value){                  // Set red color value
  analogWrite(mPinLedRed, value);
}

void setGreen(byte value){                // Set green color value
  analogWrite(mPinLedGreen, value);
}

void setBlue(byte value){                 // Set blue color value
  analogWrite(mPinLedBlue, value);
}

void showCyan(){
  setColor(0,255,255);
}

void showYellow(){
  setColor(255,255,0);
}

void showMagenta(){
  setColor(255,0,255);
}

