#ifndef _BUTTON_H
#define _BUTTON_H

#include "Arduino.h"	// Library for Arduino functions

class Button{
  public:
    Button();
    bool IsButtonReleased(char);
  private:
    unsigned long timeLastChange;
    bool lastState;
};

#endif // _BUTTON_H