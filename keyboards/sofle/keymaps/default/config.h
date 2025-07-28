// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

#define MASTER_RIGHT
#define AZOTEQ_IQS5XX_TPS43
#define AZOTEQ_IQS5XX_SCROLL_INITIAL_DISTANCE 10

// TPS43 트랙패드 설정
// 두 손가락 탭(우클릭) 비활성화하여 자동 우클릭 방지
#define AZOTEQ_IQS5XX_TWO_FINGER_TAP_ENABLE false
// 트랙패드 리포트 레이트 및 안정화
#define POINTING_DEVICE_TASK_THROTTLE_MS 10
#define AZOTEQ_IQS5XX_REPORT_RATE 10
// 트랙패드 감도 설정
#define AZOTEQ_IQS5XX_TAP_DISTANCE 30
#define AZOTEQ_IQS5XX_TAP_TIME 150

#define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE true

// 트랙패드 방향 설정
#define AZOTEQ_IQS5XX_ROTATION_90

