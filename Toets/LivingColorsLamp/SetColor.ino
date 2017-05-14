void setColor(byte r, byte g, byte b){
  analogWrite(mPinLedRed, r);
  analogWrite(mPinLedGreen, g);
  analogWrite(mPinLedBlue, b);
}

