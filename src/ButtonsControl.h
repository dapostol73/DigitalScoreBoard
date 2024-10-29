#ifndef _BUTTONS_CONTROL_H_
#define _BUTTONS_CONTROL_H_

#include <Arduino.h>

#define BUTTON_PIN_HOME_PLUS  6
#define BUTTON_PIN_HOME_MENU  7
#define BUTTON_PIN_HOME_MINUS 8
#define BUTTON_PIN_AWAY_PLUS  9
#define BUTTON_PIN_AWAY_MENU  10
#define BUTTON_PIN_AWAY_MINUS 11

class ButtonsControl
{
	private:
    
    protected:
    
    public:
        ButtonsControl();
        void init();
};

#endif