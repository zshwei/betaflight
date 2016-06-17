
#include <stdbool.h>
#include <stdint.h>

#include <platform.h>
#include "drivers/pwm_mapping.h"

const uint16_t multiPPM[] = {
    PWM1  | (MAP_TO_PPM_INPUT << 8),     // PPM input
    PWM9  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM10 | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM11 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM12 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM13 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM14 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM5  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM6  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM7  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM8  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    0xFFFF
};

const uint16_t multiPWM[] = {
    PWM1  | (MAP_TO_PWM_INPUT << 8),     // input #1
    PWM2  | (MAP_TO_PWM_INPUT << 8),
    PWM3  | (MAP_TO_PWM_INPUT << 8),
    PWM4  | (MAP_TO_PWM_INPUT << 8),
    PWM5  | (MAP_TO_PWM_INPUT << 8),
    PWM6  | (MAP_TO_PWM_INPUT << 8),
    PWM7  | (MAP_TO_PWM_INPUT << 8),
    PWM8  | (MAP_TO_PWM_INPUT << 8),     // input #8
    PWM9  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1 or servo #1 (swap to servo if needed)
    PWM10 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #2 or servo #2 (swap to servo if needed)
    PWM11 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1 or #3
    PWM12 | (MAP_TO_MOTOR_OUTPUT  << 8),
    PWM13 | (MAP_TO_MOTOR_OUTPUT  << 8),
    PWM14 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #4 or #6
    0xFFFF
};

const uint16_t airPPM[] = {
    PWM1  | (MAP_TO_PPM_INPUT << 8),     // PPM input
    PWM9  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1
    PWM10 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #2
    PWM11 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #1
    PWM12 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM13 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM14 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #4
    PWM5  | (MAP_TO_SERVO_OUTPUT  << 8), // servo #5
    PWM6  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM7  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM8  | (MAP_TO_SERVO_OUTPUT  << 8), // servo #8
    0xFFFF
};

const uint16_t airPWM[] = {
    PWM1  | (MAP_TO_PWM_INPUT << 8),     // input #1
    PWM2  | (MAP_TO_PWM_INPUT << 8),
    PWM3  | (MAP_TO_PWM_INPUT << 8),
    PWM4  | (MAP_TO_PWM_INPUT << 8),
    PWM5  | (MAP_TO_PWM_INPUT << 8),
    PWM6  | (MAP_TO_PWM_INPUT << 8),
    PWM7  | (MAP_TO_PWM_INPUT << 8),
    PWM8  | (MAP_TO_PWM_INPUT << 8),     // input #8
    PWM9  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1
    PWM10 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #2
    PWM11 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #1
    PWM12 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM13 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM14 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #4
    0xFFFF
};

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    { TIM2, IO_TAG(PA0), TIM_Channel_1, TIM2_IRQn,    0, IOCFG_IPD, 0},   // PWM1 - RC1
    { TIM2, IO_TAG(PA1), TIM_Channel_2, TIM2_IRQn,    0, IOCFG_IPD, 0},   // PWM2 - RC2
    { TIM2, IO_TAG(PA2), TIM_Channel_3, TIM2_IRQn,    0, IOCFG_IPD, 0},   // PWM3 - RC3
    { TIM2, IO_TAG(PA3), TIM_Channel_4, TIM2_IRQn,    0, IOCFG_IPD, 0},   // PWM4 - RC4
    { TIM3, IO_TAG(PA6), TIM_Channel_1, TIM3_IRQn,    0, IOCFG_IPD, 0},   // PWM5 - RC5
    { TIM3, IO_TAG(PA7), TIM_Channel_2, TIM3_IRQn,    0, IOCFG_IPD, 0},   // PWM6 - RC6
    { TIM3, IO_TAG(PB0), TIM_Channel_3, TIM3_IRQn,    0, IOCFG_IPD, 0},   // PWM7 - RC7
    { TIM3, IO_TAG(PB1), TIM_Channel_4, TIM3_IRQn,    0, IOCFG_IPD, 0},   // PWM8 - RC8
    { TIM1, IO_TAG(PA8), TIM_Channel_1, TIM1_CC_IRQn, 1, IOCFG_IPD, 0},   // PWM9 - OUT1
    { TIM1, IO_TAG(PA11),TIM_Channel_4, TIM1_CC_IRQn, 1, IOCFG_IPD, 0},   // PWM10 - OUT2
    { TIM4, IO_TAG(PB6), TIM_Channel_1, TIM4_IRQn,    0, IOCFG_IPD, 0},   // PWM11 - OUT3
    { TIM4, IO_TAG(PB7), TIM_Channel_2, TIM4_IRQn,    0, IOCFG_IPD, 0},   // PWM12 - OUT4
    { TIM4, IO_TAG(PB8), TIM_Channel_3, TIM4_IRQn,    0, IOCFG_IPD, 0},   // PWM13 - OUT5
    { TIM4, IO_TAG(PB9), TIM_Channel_4, TIM4_IRQn,    0, IOCFG_IPD, 0}    // PWM14 - OUT6
};

