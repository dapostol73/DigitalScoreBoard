#include "ButtonsControl.h"

ButtonsControl::ButtonsControl()
{
}

void ButtonsControl::init()
{
    pinMode(BUTTON_PIN_HOME_PLUS, INPUT_PULLUP);
    pinMode(BUTTON_PIN_HOME_MENU, INPUT_PULLUP);
    pinMode(BUTTON_PIN_AWAY_MINUS, INPUT_PULLUP);
    pinMode(BUTTON_PIN_AWAY_PLUS, INPUT_PULLUP);
    pinMode(BUTTON_PIN_AWAY_MENU, INPUT_PULLUP);
    pinMode(BUTTON_PIN_AWAY_MINUS, INPUT_PULLUP);
}