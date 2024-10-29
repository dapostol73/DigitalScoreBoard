#include <Arduino.h>
#include "ButtonsControl.h"
#include "DisplayControl.h"

ButtonsControl buttonsControl;
DisplayControl displayControl;

void setup()
{
    // put your setup code here, to run once:
    buttonsControl.init();
    displayControl.init();
}

void loop()
{
    for (int i = 0; i < 10; i++)
    {
        displayControl.displayTeamScore(i, false);
        delay(1000);
    }
}
