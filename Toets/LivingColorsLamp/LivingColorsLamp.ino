#include <Button.h>

enum mode{    // All the different modes available
  demo,
  preset,
  mix,
  remote
};

const int mPinSwitchPreset = 6, mPinSwitchMix = 7, mPinPot = A0, mPinLedRed = 9, mPinLedGreen = 10, mPinLedBlue = 11, mPinLedRemote = 8;

Button mBtnPresetMode = Button();   // Instantiate preset button
Button mBtnMixMode = Button();      // Instantiate mix button

int mRedValue, mGreenValue, mBlueValue;                                 // These contain the current values of the rgb colors
bool mRedChanged = false, mGreenChanged = false, mBlueChanged = false;  // These keep track if the color has changed

mode mCurrentMode = demo;           // This var holds the current mode

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
  readSerial();   // Read messages

  if(mCurrentMode != preset && mBtnPresetMode.IsButtonReleased(mPinSwitchPreset)){  // Check if preset button is released
    if(mCurrentMode == remote){
      exitRemoteMode();
    }
    mCurrentMode = preset;
  }

  if(mCurrentMode != mix && mBtnMixMode.IsButtonReleased(mPinSwitchMix)){           // Check if mix button is released
    if(mCurrentMode == remote){
      exitRemoteMode();
    }
    mCurrentMode = mix;
  }
  
  switch(mCurrentMode){                        // Execute the current mode
    case demo:
      demoMode();
      break;
    case preset:
      presetMode();
      sendRGBValues();
      break;
    case mix:
      mixMode();
      sendRGBValues();
      break;
  }
}
