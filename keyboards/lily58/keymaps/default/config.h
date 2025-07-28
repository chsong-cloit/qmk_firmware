/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MASTER_RIGHT
#define QUICK_TAP_TERM 0
#define TAPPING_TERM 100

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 6
#    define RGBLIGHT_SAT_STEP 6
#    define RGBLIGHT_VAL_STEP 6
#    define RGBLIGHT_SLEEP

    #undef RGBLIGHT_LED_COUNT
    #define RGBLIGHT_LED_COUNT 54
    #define RGBLED_SPLIT { 27, 27 }
#    define RGBLIGHT_SPLIT
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#endif


#define OLED_DISPLAY_128X32
#define OLED_TIMEOUT 120000
#define OLED_BRIGHTNESS 128
#define SPLIT_WPM_ENABLE

#define OLED_FONT_H "lib/glcdfont_lily.c"

#define SPLIT_WPM_ENABLE
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
// Underglow
/*

#define RGBLIGHT_SLEEP
*/

#define ENCODERS_PAD_A { 29 }
#define ENCODERS_PAD_B { 28 }
#define ENCODER_RESOLUTION 4
