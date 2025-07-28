// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "timer.h"  // timer_read32() 함수를 사용하기 위한 헤더
#define SCROLL_SCALE_PERCENT 3
// #include "pointing_device.h" // 제거됨
// #include "gpio.h"            // 제거됨

// TPS48 트랙패드 관련 설정 제거됨

// 관련 변수들 제거됨

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_RCLK   // 우클릭 기능을 위한 사용자 정의 키코드 추가
    // KC_TPSCRL, // 제거됨
    // KC_TPTGL   // 제거됨
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_NO, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LCTL, KC_LGUI, MO(2), KC_LALT, KC_SPC, KC_ENT, MO(1), KC_ENT, KC_RCTL, KC_RSFT),
    [1] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, LCTL(KC_UP), KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, KC_TRNS, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RGHT), KC_COLN, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCLK, KC_TRNS),
    [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_TRNS, KC_INS, KC_PSCR, KC_APP, KC_NO, KC_NO, KC_PGUP, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), LCTL(KC_BSPC), KC_BSPC, KC_TRNS, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSPC, KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_HOME, KC_NO, KC_END, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_RCLK, KC_TRNS),
    [3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, KC_NO, KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO, KC_NO, RM_NEXT, RM_HUED, RM_SATD, RM_VALD, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCLK, KC_TRNS)
};

// 관련 함수들 제거됨
// pointing_device_init_kb, pointing_device_task_kb, init_trackpad_pins,
// read_trackpad_pin, update_pin_with_debounce, process_pin_movement


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_RCLK:  // 우클릭 키 처리
            if (record->event.pressed) {
                // 마우스 우클릭 시뮬레이션
                report_mouse_t mouse_report = pointing_device_get_report();
                mouse_report.buttons |= (1 << 1);  // 우클릭 버튼 설정 (POINTING_DEVICE_BUTTON2)
                pointing_device_set_report(mouse_report);
                pointing_device_send();
            } else {
                // 버튼 해제
                report_mouse_t mouse_report = pointing_device_get_report();
                mouse_report.buttons &= ~(1 << 1);  // 우클릭 버튼 해제
                pointing_device_set_report(mouse_report);
                pointing_device_send();
            }
            return false;  // 이벤트를 여기서 처리하므로 false 반환
        // KC_TPSCRL 및 KC_TPTGL 관련 case 제거됨
    }
    return true;
}

// 레이어 상태 변경 시 호출되는 함수
layer_state_t layer_state_set_user(layer_state_t state) {
    // 네 번째 레이어(index 3)에서의 스크롤 모드 로직 제거됨
    return state;
}

int32_t scroll_amount_h = 0;
int32_t scroll_amount_v = 0;

// 마우스 상태 관리를 위한 변수들
static uint32_t last_activity_time = 0;
static bool trackpad_used = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // 마우스가 움직였거나 버튼이 눌렸으면 활동 감지
    if (mouse_report.x != 0 || mouse_report.y != 0 || mouse_report.buttons != 0) {
        uint32_t current_time = timer_read32();
        
        // 두 손가락 탭이 비활성화되었으므로 우클릭이 트랙패드에서 발생하면 안 됨
        // 그러나 자동으로 발생하는 경우를 대비해 완전히 제거
        if (mouse_report.buttons & (1 << 1)) {
            mouse_report.buttons &= ~(1 << 1);  // 우클릭 버튼 비트 제거
        }
        
        trackpad_used = true;
        last_activity_time = current_time;
    }
    
    // 스크롤 처리
    scroll_amount_h += mouse_report.h * SCROLL_SCALE_PERCENT;
    scroll_amount_v += mouse_report.v * SCROLL_SCALE_PERCENT;
    int8_t h = scroll_amount_h / 100;
    int8_t v = scroll_amount_v / 100;
    scroll_amount_h -= h*100;
    scroll_amount_v -= v*100;

    mouse_report.h = h;
    mouse_report.v = v;
    
    return mouse_report;
}