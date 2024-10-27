#include "DisplayControl.h"

DisplayControl::DisplayControl()
{
}

void DisplayControl::init()
{
    FastLED.addLeds<SK6812, LEDS_STRIP_PINH0, RGB>(ledsHomeDigit0RGB, getRGBWsize(LEDS_PER_STRIP));
    FastLED.addLeds<SK6812, LEDS_STRIP_PINH1, RGB>(ledsHomeDigit1RGB, getRGBWsize(LEDS_PER_STRIP));
    FastLED.addLeds<SK6812, LEDS_STRIP_PINA0, RGB>(ledsAwayDigit0RGB, getRGBWsize(LEDS_PER_STRIP));
    FastLED.addLeds<SK6812, LEDS_STRIP_PINA1, RGB>(ledsAwayDigit1RGB, getRGBWsize(LEDS_PER_STRIP));
    FastLED.setBrightness(255);
}

int DisplayControl::clamp(int value, int minimum, int maximum)
{
    return min(max(value, minimum), maximum);
}

/// @brief Control the digit display
/// Layout 
///  5
/// 4 6
///  0
/// 3 1
///  2
/// @param ledStrip 
/// @param color 
/// @param digit 
void DisplayControl::displayDigit(CRGBW ledStrip[], CRGB color, int digit)
{
    byte ids[] = { 0, 0, 0, 0, 0, 0, 0 };
    switch (clamp(digit, -1, 9))
    {
        case 0:
            ids[1] = ids[2] = ids[3] = ids[4] = ids[5] = ids[6] = 1;
            break;
        case 1:
            ids[1] = ids[6] = 1;
            break;
        case 2:
            ids[0] = ids[2] = ids[3] = ids[5] = ids[6] = 1;
            break;
        case 3:
            ids[0] = ids[1] = ids[2] = ids[5] = ids[6] = 1;
            break;
        case 4:
            ids[0] = ids[1] = ids[4] = ids[6] = 1;
            break;
        case 5:
            ids[0] = ids[1] = ids[2] = ids[4] = ids[5] = 1;
            break;
        case 6:
            ids[0] = ids[1] = ids[2] = ids[3] = ids[4] = ids[5] = 1;
            break;
        case 7:
            ids[1] = ids[5] = ids[6] = 1;
            break;
        case 8:
            ids[0] = ids[1] = ids[2] = ids[3] = ids[4] = ids[5] = ids[6] = 1;
            break;
        case 9:
            ids[0] = ids[1] = ids[2] = ids[4] = ids[5] = ids[6] = 1;
            break;
        default:            
            break;
    }

    for (int i = 0; i < LEDS_SEGMENTS; i++)
    {
        int pos = i * LEDS_PER_SEGMENT;
        if (ids[i] == 1)
        {
            ledStrip[pos] = color;
            ledStrip[pos+1] = color;
            ledStrip[pos+2] = color;
        }
        else
        {
            ledStrip[pos] = colorOff;
            ledStrip[pos+1] = colorOff;
            ledStrip[pos+2] = colorOff;
        }
    }
    
    FastLED.show();
}


void DisplayControl::displayTeamScore(int score, bool home)
{
    int value = clamp(score, 0, 99);
    int tens = value / 10;
    int ones = value % 10;
    if (home)
    {
        displayDigit(ledsHomeDigit0, colorHome, tens);
        displayDigit(ledsHomeDigit1, colorHome, ones);
    }
    else
    {
        displayDigit(ledsAwayDigit0, colorAway, tens);
        displayDigit(ledsAwayDigit1, colorAway, ones);       
    }
}