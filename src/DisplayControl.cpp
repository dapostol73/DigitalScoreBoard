#include "DisplayControl.h"

DisplayControl::DisplayControl()
{
}

void DisplayControl::init()
{
    FastLED.addLeds<SK6812, LEDS_STRIP_PIN1, RGB>(leds1RGB, getRGBWsize(LEDS_PER_STRIP));
    FastLED.addLeds<SK6812, LEDS_STRIP_PIN2, RGB>(leds2RGB, getRGBWsize(LEDS_PER_STRIP));
    FastLED.addLeds<SK6812, LEDS_STRIP_PIN3, RGB>(leds3RGB, getRGBWsize(LEDS_PER_STRIP));
    FastLED.addLeds<SK6812, LEDS_STRIP_PIN4, RGB>(leds4RGB, getRGBWsize(LEDS_PER_STRIP));
    FastLED.setBrightness(255);
}

int DisplayControl::clamp(int value, int max, int min)
{
    return min(max(value, min), max);
}

/// @brief Control the digit display
/// Layout 
///  5
/// 6 4
///  3
/// 0 2
///  1
/// @param ledStrip 
/// @param color 
/// @param digit 
void DisplayControl::displayDigit(CRGBW ledStrip[], CRGB color, int digit)
{
    byte ids[] = { 0, 0, 0, 0, 0, 0, 0 };
    switch (clamp(digit, 9, 0))
    {
        case 1:
            ids[2] = ids[4] = 1;
            break;
        case 2:
            ids[0] = ids[1] = ids[3] = ids[4] = ids[5] = 1;
            break;
        case 3:
            ids[1] = ids[2] = ids[3] = ids[4] = ids[5] = 1;
            break;
        case 4:
            ids[2] = ids[3] = ids[4] = ids[6] = 1;
            break;
        case 5:
            ids[1] = ids[2] = ids[3] = ids[5] = ids[6] = 1;
            break;
        case 6:
            ids[0] = ids[1] = ids[2] = ids[3] = ids[5] = ids[6] = 1;
            break;
        case 7:
            ids[2] = ids[4] = ids[5] = 1;
            break;
        case 8:
            ids[0] = ids[1] = ids[2] = ids[3] = ids[4] = ids[5] = ids[6] = 1;
            break;
        case 9:
            ids[1] = ids[2] = ids[3] = ids[4] = ids[5] = ids[6] = 1;
            break;
        default:            
            break;
    }

    for (int i = 0; i < 7; i++)
    {
        if (ids[i] == 1)
        {
            ledStrip[i] = color;
        }
        else
        {
            ledStrip[i] = CRGB(0, 0, 0);
        }
    }
    
    FastLED.show();
}