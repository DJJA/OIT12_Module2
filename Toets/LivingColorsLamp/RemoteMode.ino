void enterRemoteMode(){
  digitalWrite(mPinLedRemote, HIGH);                  // Turn on led that indicates remote mode is on
  mCurrentMode = remote;                              // Swtich to remote mode
  setColor(0,0,0);                                    // Turn led off
}

void exitRemoteMode(){                  // Exit remote mode
  digitalWrite(mPinLedRemote, LOW);     // Turn off the led that indicates that remote mode is on
  Serial.write("ARDUINO_CONTROL");      // Send message to computer
}

