#ifndef _DISPLAY_CONTROL_H_
#define _DISPLAY_CONTROL_H_

#define FASTLED_EXPERIMENTAL_ESP32_RGBW_ENABLED 1

#include <Arduino.h>
#include <math.h>
#include <FastLED.h>
#include "CRGBW.h"

#define LEDS_STRIP_PIN1 2
#define LEDS_STRIP_PIN2 3
#define LEDS_STRIP_PIN3 4
#define LEDS_STRIP_PIN4 5
#define LEDS_PER_STRIP 21

class DisplayControl
{
	private:
        CRGBW leds1[LEDS_PER_STRIP];
        CRGB *leds1RGB = (CRGB *) &leds1[0];
        CRGBW leds2[LEDS_PER_STRIP];
        CRGB *leds2RGB = (CRGB *) &leds2[0];
        CRGBW leds3[LEDS_PER_STRIP];
        CRGB *leds3RGB = (CRGB *) &leds3[0];
        CRGBW leds4[LEDS_PER_STRIP];
        CRGB *leds4RGB = (CRGB *) &leds4[0];

        int clamp(int value, int max, int min);
        void displayDigit(CRGBW ledStrip[], CRGB color, int digit);
    
    protected:
    
    public:
        DisplayControl();
		void init();
};

#endif