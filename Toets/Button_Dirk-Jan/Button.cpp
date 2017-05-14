#include "Button.h"

Button::Button(){
  unsigned long timeLastChange = 0;
  bool lastState = false;
}

bool Button::IsButtonReleased(char pin){
  const int debounceTime = 50;
  
  bool stateChanged = false;  					// The return var
  
  bool reading = digitalRead(pin);
  
	if(reading != lastState && (millis() - debounceTime) > timeLastChange){		// Current reading different than last and the switch is not debouncing
		if(lastState == HIGH){ 													// Only register when button is released
			stateChanged = true;
		}
	}

	if(reading != lastState){
		timeLastChange = millis();
		lastState = reading;
	}
	return stateChanged;
}