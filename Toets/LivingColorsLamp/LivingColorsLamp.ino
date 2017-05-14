#include <Button.h>

enum mode{
  demo,
  preset,
  mix,
  remote
};

const int mPinSwitchPreset = 6, mPinSwitchMix = 7, mPinPot = A0, mPinLedRed = 9, mPinLedGreen = 10, mPinLedBlue = 11, mPinLedRemote = 8;

Button mBtnPresetMode = Button();
Button mBtnMixMode = Button();

mode mCurrentMode = demo;

void setup() {
  pinMode(mPinSwitchMix, INPUT);
  pinMode(mPinSwitchPreset, INPUT);
  pinMode(mPinPot, INPUT);
  pinMode(mPinLedRed, OUTPUT);
  pinMode(mPinLedGreen, OUTPUT);
  pinMode(mPinLedBlue, OUTPUT);
  pinMode(mPinLedRemote, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  readSerial();

  if(mCurrentMode != preset && mBtnPresetMode.IsButtonReleased(mPinSwitchPreset)){
    if(mCurrentMode == remote){
      digitalWrite(mPinLedRemote, LOW);         // Turn off the led that indicates that remote mode is on
      Serial.write("ARDUINO_CONTROL");          // Send message to computer
    }
    mCurrentMode = preset;
    Serial.println("Going to preset mode");
  }

  if(mCurrentMode != mix && mBtnMixMode.IsButtonReleased(mPinSwitchMix)){
    if(mCurrentMode == remote){
      digitalWrite(mPinLedRemote, LOW);         // Turn off the led that indicates that remote mode is on
      Serial.write("ARDUINO_CONTROL");          // Send message to computer
    }
    mCurrentMode = mix;
    Serial.println("Going to mix mode");
  }
  
  switch(mCurrentMode){
    case demo:
      demoMode();
      break;
    case preset:
      presetMode();
      break;
    case mix:
      mixMode();
      break;
  }
}
