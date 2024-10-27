#include <Arduino.h>
#include "DisplayControl.h"

DisplayControl displayControl;

void setup()
{
    // put your setup code here, to run once:
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
