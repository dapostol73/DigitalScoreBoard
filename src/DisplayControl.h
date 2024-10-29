#ifndef _DISPLAY_CONTROL_H_
#define _DISPLAY_CONTROL_H_

#define FASTLED_EXPERIMENTAL_ESP32_RGBW_ENABLED 1

#include <Arduino.h>
#include <math.h>
#include <FastLED.h>
#include "CRGBW.h"

#define LEDS_STRIP_PINH0 2
#define LEDS_STRIP_PINH1 3
#define LEDS_STRIP_PINA0 4
#define LEDS_STRIP_PINA1 5
#define LEDS_SEGMENTS 7
#define LEDS_PER_SEGMENT 3
#define LEDS_PER_STRIP (LEDS_SEGMENTS * LEDS_PER_SEGMENT)

class DisplayControl
{
	private:
        CRGBW ledsHomeDigit0[LEDS_PER_STRIP];
        CRGB *ledsHomeDigit0RGB = (CRGB *) &ledsHomeDigit0[0];
        CRGBW ledsHomeDigit1[LEDS_PER_STRIP];
        CRGB *ledsHomeDigit1RGB = (CRGB *) &ledsHomeDigit1[0];
        CRGBW ledsAwayDigit0[LEDS_PER_STRIP];
        CRGB *ledsAwayDigit0RGB = (CRGB *) &ledsAwayDigit0[0];
        CRGBW ledsAwayDigit1[LEDS_PER_STRIP];
        CRGB *ledsAwayDigit1RGB = (CRGB *) &ledsAwayDigit1[0];

        CRGB colorHome = CRGB(255, 0, 0);
        CRGB colorAway = CRGB(255, 0, 0);
        CRGB colorOff = CRGB(0, 0, 0);

        int clamp(int value, int minimum, int maximum);
        void displayDigit(CRGBW ledStrip[], CRGB color, int digit);
    
    protected:
    
    public:
        DisplayControl();
        void init();
        void displayTeamScore(int score, bool home = true);
};

#endif