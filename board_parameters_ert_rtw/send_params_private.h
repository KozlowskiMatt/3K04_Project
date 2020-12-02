/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params_private.h
 *
 * Code generated for Simulink model 'board_parameters'.
 *
 * Model version                  : 1.118
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Dec  1 20:36:31 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_send_params_private_h_
#define RTW_HEADER_send_params_private_h_
#include <string.h>
#ifndef board_parameters_COMMON_INCLUDES_
#define board_parameters_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_SCI.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#endif                                 /* board_parameters_COMMON_INCLUDES_ */

extern void send_params_Init(void);
extern void send_params_Term(void);

#endif                                 /* RTW_HEADER_send_params_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
