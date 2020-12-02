/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_parameters.c
 *
 * Code generated for Simulink model 'board_parameters'.
 *
 * Model version                  : 1.120
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Dec  1 22:14:33 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "board_parameters.h"
#include "board_parameters_private.h"
#include "rt_roundd_snf.h"

/* Named constants for Chart: '<S1>/Chart' */
#define board_parameter_IN_ECHO_PARAMS1 ((uint8_T)2U)
#define board_parameters_IN_ECHO_PARAMS ((uint8_T)1U)
#define board_parameters_IN_SET_PARAMS ((uint8_T)3U)
#define board_parameters_IN_STANDBY    ((uint8_T)4U)
#define board_parameters_IN_initial    ((uint8_T)5U)

/* Named constants for Chart: '<S3>/Chart1' */
#define board_pa_IN_VENT_CHARGING_caiqs ((uint8_T)27U)
#define board_par_IN_VENT_CHARGING_caiq ((uint8_T)24U)
#define board_para_IN_ATRIAL_CHARGING_k ((uint8_T)9U)
#define board_para_IN_VENT_CHARGING_cai ((uint8_T)22U)
#define board_para_IN_VENT_PACING_fwph3 ((uint8_T)28U)
#define board_param_IN_VENT_CHARGING_ca ((uint8_T)20U)
#define board_param_IN_VENT_PACING_fwph ((uint8_T)25U)
#define board_parame_IN_ATRIAL_CHARGING ((uint8_T)7U)
#define board_parame_IN_ATRIAL_PACING_e ((uint8_T)10U)
#define board_parame_IN_VENT_CHARGING_c ((uint8_T)17U)
#define board_parame_IN_VENT_PACING_fwp ((uint8_T)23U)
#define board_paramet_IN_ATR_CHARGING_f ((uint8_T)15U)
#define board_paramet_IN_VENT_PACING_fw ((uint8_T)21U)
#define board_paramete_IN_ARP_WAITING_b ((uint8_T)4U)
#define board_paramete_IN_ATRIAL_PACING ((uint8_T)8U)
#define board_paramete_IN_VENT_CHARGING ((uint8_T)13U)
#define board_paramete_IN_VENT_PACING_f ((uint8_T)18U)
#define board_paramete_IN_VRP_WAITING_i ((uint8_T)29U)
#define board_parameter_IN_ATR_CHARGING ((uint8_T)11U)
#define board_parameter_IN_ATR_PACING_m ((uint8_T)16U)
#define board_parameters_IN_ARP_WAITING ((uint8_T)1U)
#define board_parameters_IN_ATR_PACING ((uint8_T)12U)
#define board_parameters_IN_CHARGING   ((uint8_T)2U)
#define board_parameters_IN_CHARGING_h ((uint8_T)5U)
#define board_parameters_IN_PACING     ((uint8_T)3U)
#define board_parameters_IN_PACING_i   ((uint8_T)6U)
#define board_parameters_IN_Start      ((uint8_T)19U)
#define board_parameters_IN_VENT_PACING ((uint8_T)14U)
#define board_parameters_IN_VRP_WAITING ((uint8_T)26U)

/* Named constants for Chart: '<S15>/Chart' */
#define board_paramete_IN_PACE_DECREASE ((uint8_T)3U)
#define board_paramete_IN_PACE_INCREASE ((uint8_T)4U)
#define board_parameters_IN_HIT_MAX    ((uint8_T)1U)
#define board_parameters_IN_HIT_MIN    ((uint8_T)2U)
#define board_parameters_IN_START      ((uint8_T)5U)

/* Block signals (default storage) */
B_board_parameters_T board_parameters_B;

/* Block states (default storage) */
DW_board_parameters_T board_parameters_DW;

/* Real-time model */
static RT_MODEL_board_parameters_T board_parameters_M_;
RT_MODEL_board_parameters_T *const board_parameters_M = &board_parameters_M_;

/* Forward declaration for local functions */
static int16_T function_handle_parenReference(int16_T varargin_1, real_T
  varargin_2);
static void board_parameters_VRP_WAITING(const real_T *Multiply1);
static void board_parameters_CHARGING_h(const real_T *Multiply, const boolean_T *
  DigitalRead1, const real_T *Switch);
static void board_parameters_CHARGING(const real_T *Multiply, const boolean_T
  *DigitalRead1, const real_T *Switch);
static void board_paramet_ATRIAL_CHARGING_c(const real_T *Multiply, const real_T
  *Switch);
static void board_parameter_ATRIAL_CHARGING(const real_T *Multiply, const real_T
  *Switch);
static void board_parameters_ATR_CHARGING(const real_T *Multiply, const real_T
  *Switch);
static void board_paramete_VENT_CHARGING_fa(const real_T *Multiply1);
static void board_parameters_ATR_CHARGING_j(const real_T *Multiply, const real_T
  *Switch);
static void board_paramet_VENT_CHARGING_fac(const real_T *Multiply1);
static void board_parameters_Start(void);
static void board_parame_VENT_CHARGING_fach(const real_T *Switch, const real_T
  *Multiply1);
static void board_parameters_VENT_CHARGING(const real_T *Switch, const real_T
  *Multiply1);
static void board_param_VENT_CHARGING_facho(const boolean_T *DigitalRead, const
  real_T *Switch, const real_T *Multiply1);
static void board_parameters_VRP_WAITING_d(const real_T *Multiply1);
static void board_parameter_VENT_CHARGING_f(const boolean_T *DigitalRead, const
  real_T *Switch, const real_T *Multiply1);
static void board_param_SystemCore_setup_dt(freedomk64f_fxos8700_board_pa_T *obj);
static void board_parame_SystemCore_setup_d(freedomk64f_SCIRead_board_par_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void board_parameters_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(board_parameters_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (board_parameters_M->Timing.TaskCounters.TID[1])++;
  if ((board_parameters_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    board_parameters_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static int16_T function_handle_parenReference(int16_T varargin_1, real_T
  varargin_2)
{
  int16_T varargout_1;
  if (varargin_2 >= 0.0) {
    if (varargin_2 <= 15.0) {
      varargout_1 = (int16_T)(varargin_1 << (uint8_T)varargin_2);
    } else {
      varargout_1 = 0;
    }
  } else if (varargin_2 >= -15.0) {
    varargout_1 = (int16_T)(varargin_1 >> (uint8_T)-varargin_2);
  } else if (varargin_1 < 0) {
    varargout_1 = -1;
  } else {
    varargout_1 = 0;
  }

  return varargout_1;
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameters_VRP_WAITING(const real_T *Multiply1)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      board_parameters_B.VRP_f) {
    board_parameters_DW.is_c5_board_parameters = board_pa_IN_VENT_CHARGING_caiqs;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply1;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.VENT_GND_CTRL = true;
    board_parameters_B.ATR_GND_CTRL = false;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameters_CHARGING_h(const real_T *Multiply, const boolean_T *
  DigitalRead1, const real_T *Switch)
{
  real32_T tmp;
  tmp = (real32_T)(uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 *
    10);
  if ((tmp >= board_parameters_B.ATR_PW_o) && (*DigitalRead1)) {
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_ARP_WAITING;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (tmp >= ((real32_T)*Switch - board_parameters_B.ATR_PW_o) -
             (real32_T)board_parameters_B.ARP_p) {
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_PACING;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 3) {
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = true;
    board_parameters_B.VENT_GND_CTRL = false;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameters_CHARGING(const real_T *Multiply, const boolean_T
  *DigitalRead1, const real_T *Switch)
{
  real32_T tmp;
  tmp = (real32_T)(uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 *
    10);
  if ((tmp >= board_parameters_B.ATR_PW_o) && (*DigitalRead1)) {
    board_parameters_DW.is_c5_board_parameters = board_paramete_IN_ARP_WAITING_b;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (tmp >= ((real32_T)*Switch - board_parameters_B.ATR_PW_o) -
             (real32_T)board_parameters_B.ARP_p) {
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_PACING_i;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 3) {
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = true;
    board_parameters_B.VENT_GND_CTRL = false;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_paramet_ATRIAL_CHARGING_c(const real_T *Multiply, const real_T
  *Switch)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      (real32_T)*Switch - board_parameters_B.ATR_PW_o) {
    board_parameters_DW.is_c5_board_parameters = board_paramete_IN_ATRIAL_PACING;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 1) {
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = true;
    board_parameters_B.VENT_GND_CTRL = false;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameter_ATRIAL_CHARGING(const real_T *Multiply, const real_T
  *Switch)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      (real32_T)*Switch - board_parameters_B.ATR_PW_o) {
    board_parameters_DW.is_c5_board_parameters = board_parame_IN_ATRIAL_PACING_e;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 6) {
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = true;
    board_parameters_B.VENT_GND_CTRL = false;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameters_ATR_CHARGING(const real_T *Multiply, const real_T
  *Switch)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      ((real32_T)*Switch - board_parameters_B.VENT_PW_n) - (real32_T)
      board_parameters_B.AV_DELAY_p) {
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_ATR_PACING;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 5) {
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = true;
    board_parameters_B.VENT_GND_CTRL = false;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_paramete_VENT_CHARGING_fa(const real_T *Multiply1)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      (real32_T)board_parameters_B.AV_DELAY_p - board_parameters_B.ATR_PW_o) {
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_VENT_PACING;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply1;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = false;
    board_parameters_B.VENT_GND_CTRL = true;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameters_ATR_CHARGING_j(const real_T *Multiply, const real_T
  *Switch)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      ((real32_T)*Switch - board_parameters_B.VENT_PW_n) - (real32_T)
      board_parameters_B.AV_DELAY_p) {
    board_parameters_DW.is_c5_board_parameters = board_parameter_IN_ATR_PACING_m;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 10) {
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = true;
    board_parameters_B.VENT_GND_CTRL = false;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_paramet_VENT_CHARGING_fac(const real_T *Multiply1)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      (real32_T)board_parameters_B.AV_DELAY_p - board_parameters_B.ATR_PW_o) {
    board_parameters_DW.is_c5_board_parameters = board_paramete_IN_VENT_PACING_f;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply1;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = false;
    board_parameters_B.VENT_GND_CTRL = true;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameters_Start(void)
{
  switch (board_parameters_B.MODE) {
   case 10:
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_paramet_IN_ATR_CHARGING_f;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;

   case 9:
    board_parameters_B.FRONTEND_CTRL = true;
    board_parameters_DW.is_c5_board_parameters = board_pa_IN_VENT_CHARGING_caiqs;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;

   case 5:
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parameter_IN_ATR_CHARGING;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;

   case 8:
    board_parameters_B.FRONTEND_CTRL = true;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_CHARGING_h;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;

   case 6:
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_para_IN_ATRIAL_CHARGING_k;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;

   case 7:
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_para_IN_VENT_CHARGING_cai;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;

   case 1:
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parame_IN_ATRIAL_CHARGING;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;

   case 2:
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_param_IN_VENT_CHARGING_ca;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;

   case 3:
    board_parameters_B.FRONTEND_CTRL = true;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_CHARGING;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;

   case 4:
    board_parameters_B.FRONTEND_CTRL = true;
    board_parameters_DW.is_c5_board_parameters = board_par_IN_VENT_CHARGING_caiq;
    board_parameters_DW.temporalCounter_i1 = 0U;
    break;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parame_VENT_CHARGING_fach(const real_T *Switch, const real_T
  *Multiply1)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      (real32_T)*Switch - board_parameters_B.VENT_PW_n) {
    board_parameters_DW.is_c5_board_parameters = board_paramet_IN_VENT_PACING_fw;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 2) {
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply1;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = false;
    board_parameters_B.VENT_GND_CTRL = true;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameters_VENT_CHARGING(const real_T *Switch, const real_T
  *Multiply1)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      (real32_T)*Switch - board_parameters_B.VENT_PW_n) {
    board_parameters_DW.is_c5_board_parameters = board_parame_IN_VENT_PACING_fwp;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 7) {
    board_parameters_B.FRONTEND_CTRL = false;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply1;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.ATR_GND_CTRL = false;
    board_parameters_B.VENT_GND_CTRL = true;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_param_VENT_CHARGING_facho(const boolean_T *DigitalRead, const
  real_T *Switch, const real_T *Multiply1)
{
  real32_T tmp;
  tmp = (real32_T)(uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 *
    10);
  if ((tmp >= board_parameters_B.VENT_PW_n) && (*DigitalRead)) {
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_VRP_WAITING;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (tmp >= ((real32_T)*Switch - board_parameters_B.VENT_PW_n) -
             (real32_T)board_parameters_B.VRP_f) {
    board_parameters_DW.is_c5_board_parameters = board_param_IN_VENT_PACING_fwph;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 4) {
    board_parameters_B.FRONTEND_CTRL = true;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply1;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.VENT_GND_CTRL = true;
    board_parameters_B.ATR_GND_CTRL = false;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameters_VRP_WAITING_d(const real_T *Multiply1)
{
  if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
      board_parameters_B.VRP_f) {
    board_parameters_DW.is_c5_board_parameters = board_par_IN_VENT_CHARGING_caiq;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply1;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.VENT_GND_CTRL = true;
    board_parameters_B.ATR_GND_CTRL = false;
  }
}

/* Function for Chart: '<S3>/Chart1' */
static void board_parameter_VENT_CHARGING_f(const boolean_T *DigitalRead, const
  real_T *Switch, const real_T *Multiply1)
{
  board_parameters_B.f = (real32_T)(uint32_T)((int32_T)
    board_parameters_DW.temporalCounter_i1 * 10);
  if ((board_parameters_B.f >= board_parameters_B.VENT_PW_n) && (*DigitalRead))
  {
    board_parameters_DW.is_c5_board_parameters = board_paramete_IN_VRP_WAITING_i;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.f >= ((real32_T)*Switch -
              board_parameters_B.VENT_PW_n) - (real32_T)board_parameters_B.VRP_f)
  {
    board_parameters_DW.is_c5_board_parameters = board_para_IN_VENT_PACING_fwph3;
    board_parameters_DW.temporalCounter_i1 = 0U;
  } else if (board_parameters_B.MODE != 9) {
    board_parameters_B.FRONTEND_CTRL = true;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    board_parameters_B.PACING_REF_PWM = *Multiply1;
    board_parameters_B.PACE_CHARGE_CTRL = true;
    board_parameters_B.PACE_GND_CTRL = true;
    board_parameters_B.ATR_PACE_CTRL = false;
    board_parameters_B.Z_VENT_CTRL = false;
    board_parameters_B.Z_ATR_CTRL = false;
    board_parameters_B.VENT_PACE_CTRL = false;
    board_parameters_B.VENT_GND_CTRL = true;
    board_parameters_B.ATR_GND_CTRL = false;
  }
}

static void board_param_SystemCore_setup_dt(freedomk64f_fxos8700_board_pa_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  board_parameters_B.ModeType = MW_I2C_MASTER;
  board_parameters_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(board_parameters_B.i2cname,
    board_parameters_B.ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  board_parameters_B.b_SwappedDataBytes[0] = 43U;
  board_parameters_B.b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &board_parameters_B.b_SwappedDataBytes[0], 2U, false, false);
  OSA_TimeDelay(500U);
  board_parameters_B.status_m = 42U;
  board_parameters_B.status_m = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE,
    29U, &board_parameters_B.status_m, 1U, true, false);
  if (0 == board_parameters_B.status_m) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U,
                      &board_parameters_B.status_m, 1U, false, true);
    memcpy((void *)&board_parameters_B.b_RegisterValue, (void *)
           &board_parameters_B.status_m, (uint32_T)((size_t)1 * sizeof(uint8_T)));
  } else {
    board_parameters_B.b_RegisterValue = 0U;
  }

  board_parameters_B.b_SwappedDataBytes[0] = 42U;
  board_parameters_B.b_SwappedDataBytes[1] = (uint8_T)
    (board_parameters_B.b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &board_parameters_B.b_SwappedDataBytes[0], 2U, false, false);
  board_parameters_B.b_SwappedDataBytes[0] = 14U;
  board_parameters_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &board_parameters_B.b_SwappedDataBytes[0], 2U, false, false);
  board_parameters_B.b_SwappedDataBytes[0] = 91U;
  board_parameters_B.b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &board_parameters_B.b_SwappedDataBytes[0], 2U, false, false);
  board_parameters_B.b_SwappedDataBytes[0] = 42U;
  board_parameters_B.b_SwappedDataBytes[1] = 25U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &board_parameters_B.b_SwappedDataBytes[0], 2U, false, false);
  obj->isSetupComplete = true;
}

static void board_parame_SystemCore_setup_d(freedomk64f_SCIRead_board_par_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  board_parameters_B.TxPinLoc = MW_UNDEFINED_VALUE;
  board_parameters_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&board_parameters_B.SCIModuleLoc, false, 10U,
    board_parameters_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  board_parameters_B.StopBitsValue = MW_SCI_STOPBITS_1;
  board_parameters_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, board_parameters_B.ParityValue,
                        board_parameters_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void board_parameters_step0(void)      /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void board_parameters_step1(void)      /* Sample time: [0.01s, 0.0s] */
{
  static const real_T b[16] = { 1.0, 1.3333333333333333, 1.6666666666666665, 2.0,
    2.333333333333333, 2.6666666666666665, 3.0, 3.333333333333333,
    3.666666666666667, 4.0, 4.3333333333333339, 4.666666666666667, 5.0,
    5.333333333333333, 5.666666666666667, 6.0 };

  g_dsp_private_SlidingWindowAv_T *obj;

  /* MATLABSystem: '<S1>/Serial Receive' */
  if (board_parameters_DW.obj_m.SampleTime !=
      board_parameters_P.SerialReceive_SampleTime) {
    board_parameters_DW.obj_m.SampleTime =
      board_parameters_P.SerialReceive_SampleTime;
  }

  board_parameters_B.status = MW_SCI_Receive
    (board_parameters_DW.obj_m.MW_SCIHANDLE, &board_parameters_B.RxDataLocChar[0],
     33U);
  memcpy((void *)&board_parameters_B.RxData[0], (void *)
         &board_parameters_B.RxDataLocChar[0], (uint32_T)((size_t)33 * sizeof
          (uint8_T)));

  /* MATLABSystem: '<S1>/Digital Write' incorporates:
   *  Logic: '<S1>/NOT'
   *  MATLABSystem: '<S1>/Serial Receive'
   */
  MW_digitalIO_write(board_parameters_DW.obj_a.MW_DIGITALIO_HANDLE,
                     board_parameters_B.status == 0);

  /* Chart: '<S1>/Chart' incorporates:
   *  MATLABSystem: '<S1>/Serial Receive'
   */
  switch (board_parameters_DW.is_c1_board_parameters) {
   case board_parameters_IN_ECHO_PARAMS:
    board_parameters_DW.is_c1_board_parameters = board_parameters_IN_STANDBY;
    break;

   case board_parameter_IN_ECHO_PARAMS1:
    board_parameters_DW.is_c1_board_parameters = board_parameters_IN_STANDBY;
    break;

   case board_parameters_IN_SET_PARAMS:
    board_parameters_DW.is_c1_board_parameters = board_parameters_IN_STANDBY;
    break;

   case board_parameters_IN_STANDBY:
    if (board_parameters_B.status == 0) {
      if (board_parameters_B.RxData[0] == 22) {
        switch (board_parameters_B.RxData[1]) {
         case 32:
          board_parameters_DW.is_c1_board_parameters =
            board_parameters_IN_SET_PARAMS;
          board_parameters_B.MODE = board_parameters_B.RxData[3];
          board_parameters_B.LRL = board_parameters_B.RxData[4];
          board_parameters_B.URL = board_parameters_B.RxData[5];
          board_parameters_B.MSR = board_parameters_B.RxData[6];
          memcpy((void *)&board_parameters_B.VENT_AMP_m, (void *)
                 &board_parameters_B.RxData[7], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          memcpy((void *)&board_parameters_B.VENT_PW_n, (void *)
                 &board_parameters_B.RxData[10], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          memcpy((void *)&board_parameters_B.VRP_f, (void *)
                 &board_parameters_B.RxData[14], (uint32_T)((size_t)1 * sizeof
                  (uint16_T)));
          memcpy((void *)&board_parameters_B.ATR_AMP_h, (void *)
                 &board_parameters_B.RxData[16], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          memcpy((void *)&board_parameters_B.ATR_PW_o, (void *)
                 &board_parameters_B.RxData[20], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          memcpy((void *)&board_parameters_B.ARP_p, (void *)
                 &board_parameters_B.RxData[24], (uint32_T)((size_t)1 * sizeof
                  (uint16_T)));
          board_parameters_B.A_THRESH = board_parameters_B.RxData[26];
          board_parameters_B.REACTION_T = board_parameters_B.RxData[27];
          board_parameters_B.RESPONSE_FACTOR = board_parameters_B.RxData[28];
          board_parameters_B.RECOVERY_T = board_parameters_B.RxData[29];
          memcpy((void *)&board_parameters_B.AV_DELAY_p, (void *)
                 &board_parameters_B.RxData[30], (uint32_T)((size_t)1 * sizeof
                  (uint16_T)));
          break;

         case 16:
          switch (board_parameters_B.RxData[2]) {
           case 0:
            board_parameters_DW.is_c1_board_parameters =
              board_parameter_IN_ECHO_PARAMS1;
            send_params();
            break;

           case 1:
            board_parameters_DW.is_c1_board_parameters =
              board_parameters_IN_ECHO_PARAMS;
            send_params();
            break;

           default:
            board_parameters_DW.is_c1_board_parameters =
              board_parameters_IN_STANDBY;
            break;
          }
          break;

         default:
          board_parameters_DW.is_c1_board_parameters =
            board_parameters_IN_STANDBY;
          break;
        }
      } else {
        board_parameters_DW.is_c1_board_parameters = board_parameters_IN_STANDBY;
      }
    }
    break;

   default:
    /* case IN_initial: */
    board_parameters_DW.is_c1_board_parameters = board_parameters_IN_STANDBY;
    break;
  }

  /* End of Chart: '<S1>/Chart' */

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant14'
   *  Constant: '<S1>/Constant15'
   */
  if (board_parameters_B.MODE > board_parameters_P.Switch1_Threshold) {
    board_parameters_B.Add = board_parameters_P.Constant14_Value;
  } else {
    board_parameters_B.Add = board_parameters_P.Constant15_Value;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem2' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (board_parameters_B.Add > 0.0) {
    /* MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor1' */
    if (board_parameters_DW.obj_d.SampleTime !=
        board_parameters_P.FXOS87006AxesSensor1_SampleTime) {
      board_parameters_DW.obj_d.SampleTime =
        board_parameters_P.FXOS87006AxesSensor1_SampleTime;
    }

    board_parameters_B.status = 1U;
    board_parameters_B.status = MW_I2C_MasterWrite
      (board_parameters_DW.obj_d.i2cobj.MW_I2C_HANDLE, 29U,
       &board_parameters_B.status, 1U, true, false);
    if (0 == board_parameters_B.status) {
      MW_I2C_MasterRead(board_parameters_DW.obj_d.i2cobj.MW_I2C_HANDLE, 29U,
                        &board_parameters_B.output_raw[0], 6U, false, true);
      memcpy((void *)&board_parameters_B.b_output[0], (void *)
             &board_parameters_B.output_raw[0], (uint32_T)((size_t)3 * sizeof
              (int16_T)));
      memcpy((void *)&board_parameters_B.y[0], (void *)
             &board_parameters_B.b_output[0], (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      board_parameters_B.b_x[0] = board_parameters_B.y[1];
      board_parameters_B.b_x[1] = board_parameters_B.y[0];
      memcpy((void *)&board_parameters_B.b_output[0], (void *)
             &board_parameters_B.b_x[0], (uint32_T)((size_t)1 * sizeof(int16_T)));
      memcpy((void *)&board_parameters_B.y[0], (void *)
             &board_parameters_B.b_output[1], (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      board_parameters_B.b_x[0] = board_parameters_B.y[1];
      board_parameters_B.b_x[1] = board_parameters_B.y[0];
      memcpy((void *)&board_parameters_B.b_output[1], (void *)
             &board_parameters_B.b_x[0], (uint32_T)((size_t)1 * sizeof(int16_T)));
      memcpy((void *)&board_parameters_B.y[0], (void *)
             &board_parameters_B.b_output[2], (uint32_T)((size_t)2 * sizeof
              (uint8_T)));
      board_parameters_B.b_x[0] = board_parameters_B.y[1];
      board_parameters_B.b_x[1] = board_parameters_B.y[0];
      memcpy((void *)&board_parameters_B.b_output[2], (void *)
             &board_parameters_B.b_x[0], (uint32_T)((size_t)1 * sizeof(int16_T)));
    } else {
      board_parameters_B.b_output[0] = 0;
      board_parameters_B.b_output[1] = 0;
      board_parameters_B.b_output[2] = 0;
    }

    /* MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor1' */
    board_parameters_B.FXOS87006AxesSensor1[0] = (real_T)
      function_handle_parenReference(board_parameters_B.b_output[0], -2.0) * 2.0
      * 0.244 / 1000.0;
    board_parameters_B.FXOS87006AxesSensor1[1] = (real_T)
      function_handle_parenReference(board_parameters_B.b_output[1], -2.0) * 2.0
      * 0.244 / 1000.0;
    board_parameters_B.FXOS87006AxesSensor1[2] = (real_T)
      function_handle_parenReference(board_parameters_B.b_output[2], -2.0) * 2.0
      * 0.244 / 1000.0;
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem2' */

  /* MATLABSystem: '<S2>/Digital Read' */
  if (board_parameters_DW.obj_h.SampleTime !=
      board_parameters_P.DigitalRead_SampleTime) {
    board_parameters_DW.obj_h.SampleTime =
      board_parameters_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<S2>/Digital Read' */
  board_parameters_B.DigitalRead = MW_digitalIO_read
    (board_parameters_DW.obj_h.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/Digital Read1' */
  if (board_parameters_DW.obj_b.SampleTime !=
      board_parameters_P.DigitalRead1_SampleTime) {
    board_parameters_DW.obj_b.SampleTime =
      board_parameters_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<S2>/Digital Read1' */
  board_parameters_B.DigitalRead1 = MW_digitalIO_read
    (board_parameters_DW.obj_b.MW_DIGITALIO_HANDLE);

  /* Gain: '<S10>/Multiply' incorporates:
   *  Constant: '<S10>/Constant'
   *  Product: '<S10>/Product'
   */
  board_parameters_B.Multiply = board_parameters_B.ATR_AMP_h /
    board_parameters_P.Constant_Value_oq * board_parameters_P.Multiply_Gain_b;

  /* Gain: '<S10>/Multiply1' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Product: '<S10>/Product1'
   */
  board_parameters_B.Multiply1 = board_parameters_B.VENT_AMP_m /
    board_parameters_P.Constant1_Value * board_parameters_P.Multiply1_Gain;

  /* Sum: '<S15>/Add' incorporates:
   *  Abs: '<S15>/Abs'
   *  Abs: '<S15>/Abs1'
   *  Abs: '<S15>/Abs2'
   *  Constant: '<S15>/Constant'
   *  Sum: '<S15>/Sum'
   */
  board_parameters_B.Add = (fabs(board_parameters_B.FXOS87006AxesSensor1[0]) +
    fabs(board_parameters_B.FXOS87006AxesSensor1[1])) + fabs
    (board_parameters_B.FXOS87006AxesSensor1[2] -
     board_parameters_P.Constant_Value_h);

  /* MATLABSystem: '<S15>/Moving Average' */
  if (board_parameters_DW.obj.TunablePropsChanged) {
    board_parameters_DW.obj.TunablePropsChanged = false;
  }

  obj = board_parameters_DW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
  }

  board_parameters_B.cumRevIndex = obj->pCumRevIndex;
  board_parameters_B.csum = obj->pCumSum;
  board_parameters_B.csumrev[0] = obj->pCumSumRev[0];
  board_parameters_B.csumrev[1] = obj->pCumSumRev[1];
  board_parameters_B.csumrev[2] = obj->pCumSumRev[2];
  board_parameters_B.csum += board_parameters_B.Add;
  board_parameters_B.z = board_parameters_B.csumrev[(int32_T)
    board_parameters_B.cumRevIndex - 1] + board_parameters_B.csum;
  board_parameters_B.csumrev[(int32_T)board_parameters_B.cumRevIndex - 1] =
    board_parameters_B.Add;
  if (board_parameters_B.cumRevIndex != 3.0) {
    board_parameters_B.cumRevIndex++;
  } else {
    board_parameters_B.cumRevIndex = 1.0;
    board_parameters_B.csum = 0.0;
    board_parameters_B.csumrev[1] += board_parameters_B.csumrev[2];
    board_parameters_B.csumrev[0] += board_parameters_B.csumrev[1];
  }

  obj->pCumSum = board_parameters_B.csum;
  obj->pCumSumRev[0] = board_parameters_B.csumrev[0];
  obj->pCumSumRev[1] = board_parameters_B.csumrev[1];
  obj->pCumSumRev[2] = board_parameters_B.csumrev[2];
  obj->pCumRevIndex = board_parameters_B.cumRevIndex;
  board_parameters_B.cumRevIndex = board_parameters_B.z / 4.0;

  /* End of MATLABSystem: '<S15>/Moving Average' */

  /* Chart: '<S15>/Chart' incorporates:
   *  Constant: '<S18>/Constant'
   *  MATLAB Function: '<S15>/MATLAB Function'
   *  Product: '<S18>/Divide'
   *  Product: '<S18>/Product'
   *  Sum: '<S18>/Subtract'
   *  Sum: '<S18>/Subtract1'
   */
  if (board_parameters_DW.is_active_c7_board_parameters == 0U) {
    board_parameters_DW.is_active_c7_board_parameters = 1U;
    board_parameters_DW.is_c7_board_parameters = board_parameters_IN_START;
    board_parameters_B.red = true;
    board_parameters_B.OUTPUT_PACE = board_parameters_B.LRL;
  } else {
    switch (board_parameters_DW.is_c7_board_parameters) {
     case board_parameters_IN_HIT_MAX:
      if (board_parameters_B.cumRevIndex < board_parameters_B.A_THRESH) {
        board_parameters_DW.is_c7_board_parameters =
          board_paramete_IN_PACE_DECREASE;
        board_parameters_DW.time = 0.0;
        board_parameters_B.red = false;
        board_parameters_B.green = false;
        board_parameters_B.qY = (uint32_T)board_parameters_B.OUTPUT_PACE -
          /*MW:OvSatOk*/ board_parameters_B.LRL;
        if (board_parameters_B.qY > board_parameters_B.OUTPUT_PACE) {
          board_parameters_B.qY = 0U;
        }

        board_parameters_DW.REMAINING_RATE = (uint8_T)board_parameters_B.qY;
      } else {
        board_parameters_B.green = true;
      }
      break;

     case board_parameters_IN_HIT_MIN:
      if (board_parameters_B.cumRevIndex >= board_parameters_B.A_THRESH) {
        board_parameters_DW.is_c7_board_parameters =
          board_paramete_IN_PACE_INCREASE;
        board_parameters_B.red = false;
        board_parameters_B.green = false;
        board_parameters_DW.time = 0.0;
      } else {
        board_parameters_B.red = true;
      }
      break;

     case board_paramete_IN_PACE_DECREASE:
      if (board_parameters_B.OUTPUT_PACE == board_parameters_B.LRL) {
        board_parameters_DW.time = 0.0;
        board_parameters_DW.is_c7_board_parameters = board_parameters_IN_HIT_MIN;
        board_parameters_B.red = true;
      } else if (board_parameters_B.cumRevIndex >= board_parameters_B.A_THRESH)
      {
        board_parameters_DW.is_c7_board_parameters =
          board_paramete_IN_PACE_INCREASE;
        board_parameters_B.red = false;
        board_parameters_B.green = false;
        board_parameters_DW.time = 0.0;
      } else if (board_parameters_DW.time >= board_parameters_B.REACTION_T) {
        board_parameters_DW.is_c7_board_parameters =
          board_paramete_IN_PACE_DECREASE;
        board_parameters_DW.time = 0.0;
        board_parameters_B.red = false;
        board_parameters_B.green = false;
        board_parameters_B.qY = (uint32_T)board_parameters_B.OUTPUT_PACE -
          /*MW:OvSatOk*/ board_parameters_B.LRL;
        if (board_parameters_B.qY > board_parameters_B.OUTPUT_PACE) {
          board_parameters_B.qY = 0U;
        }

        board_parameters_DW.REMAINING_RATE = (uint8_T)board_parameters_B.qY;
      } else {
        if (board_parameters_B.RECOVERY_T == 0) {
          if (board_parameters_DW.REMAINING_RATE == 0) {
            board_parameters_B.status = 0U;
          } else {
            board_parameters_B.status = MAX_uint8_T;
          }
        } else {
          board_parameters_B.status = (uint8_T)(board_parameters_B.RECOVERY_T ==
            0U ? MAX_uint32_T : (uint32_T)board_parameters_DW.REMAINING_RATE /
            board_parameters_B.RECOVERY_T);
          board_parameters_B.x = (uint8_T)((uint32_T)
            board_parameters_DW.REMAINING_RATE - (uint8_T)((uint32_T)
            board_parameters_B.status * board_parameters_B.RECOVERY_T));
          if ((board_parameters_B.x > 0) && (board_parameters_B.x >= (int32_T)
               ((uint32_T)board_parameters_B.RECOVERY_T >> 1) +
               (board_parameters_B.RECOVERY_T & 1))) {
            board_parameters_B.status++;
          }
        }

        board_parameters_B.Add = rt_roundd_snf((real_T)board_parameters_B.status
          * board_parameters_DW.time);
        if (board_parameters_B.Add < 256.0) {
          if (board_parameters_B.Add >= 0.0) {
            board_parameters_B.status = (uint8_T)board_parameters_B.Add;
          } else {
            board_parameters_B.status = 0U;
          }
        } else {
          board_parameters_B.status = MAX_uint8_T;
        }

        board_parameters_B.qY = (uint32_T)board_parameters_B.OUTPUT_PACE -
          /*MW:OvSatOk*/ board_parameters_B.status;
        if (board_parameters_B.qY > board_parameters_B.OUTPUT_PACE) {
          board_parameters_B.qY = 0U;
        }

        board_parameters_B.OUTPUT_PACE = (uint8_T)board_parameters_B.qY;
        board_parameters_DW.time += 0.001;
      }
      break;

     case board_paramete_IN_PACE_INCREASE:
      if (board_parameters_B.OUTPUT_PACE == board_parameters_B.MSR) {
        board_parameters_DW.time = 0.0;
        board_parameters_DW.is_c7_board_parameters = board_parameters_IN_HIT_MAX;
        board_parameters_B.green = true;
      } else if (board_parameters_B.cumRevIndex < board_parameters_B.A_THRESH) {
        board_parameters_DW.is_c7_board_parameters =
          board_paramete_IN_PACE_DECREASE;
        board_parameters_DW.time = 0.0;
        board_parameters_B.red = false;
        board_parameters_B.green = false;
        board_parameters_B.qY = (uint32_T)board_parameters_B.OUTPUT_PACE -
          /*MW:OvSatOk*/ board_parameters_B.LRL;
        if (board_parameters_B.qY > board_parameters_B.OUTPUT_PACE) {
          board_parameters_B.qY = 0U;
        }

        board_parameters_DW.REMAINING_RATE = (uint8_T)board_parameters_B.qY;
      } else if (board_parameters_DW.time >= board_parameters_B.REACTION_T) {
        board_parameters_DW.is_c7_board_parameters =
          board_paramete_IN_PACE_INCREASE;
        board_parameters_B.red = false;
        board_parameters_B.green = false;
        board_parameters_DW.time = 0.0;
      } else {
        board_parameters_B.Add = rt_roundd_snf(board_parameters_DW.time /
          (real_T)board_parameters_B.REACTION_T);
        if (board_parameters_B.Add < 256.0) {
          if (board_parameters_B.Add >= 0.0) {
            board_parameters_B.status = (uint8_T)board_parameters_B.Add;
          } else {
            board_parameters_B.status = 0U;
          }
        } else {
          board_parameters_B.status = MAX_uint8_T;
        }

        /* MATLAB Function: '<S15>/MATLAB Function' */
        board_parameters_B.Add = b[board_parameters_B.RESPONSE_FACTOR - 1];
        board_parameters_B.i1 = (int32_T)rt_roundd_snf(board_parameters_B.Add *
          (real_T)board_parameters_B.status);
        if (board_parameters_B.i1 < 256) {
          board_parameters_B.x = (uint8_T)board_parameters_B.i1;
        } else {
          board_parameters_B.x = MAX_uint8_T;
        }

        board_parameters_B.csum = rt_roundd_snf(board_parameters_DW.time /
          (real_T)board_parameters_B.REACTION_T);
        if (board_parameters_B.csum < 256.0) {
          if (board_parameters_B.csum >= 0.0) {
            board_parameters_B.status = (uint8_T)board_parameters_B.csum;
          } else {
            board_parameters_B.status = 0U;
          }
        } else {
          board_parameters_B.status = MAX_uint8_T;
        }

        board_parameters_B.i1 = (int32_T)rt_roundd_snf((board_parameters_B.Add -
          1.0) * (real_T)board_parameters_B.status);
        if (board_parameters_B.i1 < 256) {
          board_parameters_B.status = (uint8_T)board_parameters_B.i1;
        } else {
          board_parameters_B.status = MAX_uint8_T;
        }

        board_parameters_B.i = (int32_T)(board_parameters_B.status + 1U);
        if (board_parameters_B.i1 < 256) {
          board_parameters_B.status = (uint8_T)board_parameters_B.i1;
        } else {
          board_parameters_B.status = MAX_uint8_T;
        }

        if (board_parameters_B.status + 1U > 255U) {
          board_parameters_B.i = 255;
        }

        board_parameters_B.status = (uint8_T)((uint32_T)board_parameters_B.x /
          (uint8_T)board_parameters_B.i);
        board_parameters_B.x = (uint8_T)((uint32_T)board_parameters_B.x -
          (uint8_T)((uint32_T)board_parameters_B.status * (uint8_T)
                    board_parameters_B.i));
        if ((board_parameters_B.x > 0) && (board_parameters_B.x >= (int32_T)
             ((uint32_T)(uint8_T)board_parameters_B.i >> 1) + ((uint8_T)
              board_parameters_B.i & 1))) {
          board_parameters_B.status++;
        }

        board_parameters_B.Add = rt_roundd_snf((real_T)(uint8_T)
          (board_parameters_B.MSR - board_parameters_B.LRL) /
          (board_parameters_P.Constant_Value_n - (real_T)
           board_parameters_B.A_THRESH) * board_parameters_B.cumRevIndex *
          (real_T)board_parameters_B.status);
        if (board_parameters_B.Add < 256.0) {
          if (board_parameters_B.Add >= 0.0) {
            board_parameters_B.status = (uint8_T)board_parameters_B.Add;
          } else {
            board_parameters_B.status = 0U;
          }
        } else {
          board_parameters_B.status = MAX_uint8_T;
        }

        board_parameters_B.i1 = (int32_T)((uint32_T)board_parameters_B.status +
          board_parameters_B.LRL);
        if ((uint32_T)board_parameters_B.i1 > 255U) {
          board_parameters_B.i1 = 255;
        }

        board_parameters_B.OUTPUT_PACE = (uint8_T)board_parameters_B.i1;
        board_parameters_DW.time += 0.001;
      }
      break;

     default:
      /* case IN_START: */
      board_parameters_DW.is_c7_board_parameters =
        board_paramete_IN_PACE_DECREASE;
      board_parameters_DW.time = 0.0;
      board_parameters_B.red = false;
      board_parameters_B.green = false;
      board_parameters_B.qY = (uint32_T)board_parameters_B.OUTPUT_PACE -
        /*MW:OvSatOk*/ board_parameters_B.LRL;
      if (board_parameters_B.qY > board_parameters_B.OUTPUT_PACE) {
        board_parameters_B.qY = 0U;
      }

      board_parameters_DW.REMAINING_RATE = (uint8_T)board_parameters_B.qY;
      break;
    }
  }

  /* End of Chart: '<S15>/Chart' */

  /* Switch: '<S11>/Switch' incorporates:
   *  MATLAB Function: '<S11>/MATLAB Function'
   */
  if ((board_parameters_B.MODE > 5) > board_parameters_P.Switch_Threshold) {
    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S14>/Constant'
     *  Product: '<S14>/Divide'
     */
    board_parameters_B.Add = board_parameters_P.Constant_Value / (real_T)
      board_parameters_B.OUTPUT_PACE;
  } else {
    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S12>/Constant'
     *  Product: '<S12>/Product'
     */
    board_parameters_B.Add = board_parameters_P.Constant_Value_j / (real_T)
      board_parameters_B.LRL;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Chart: '<S3>/Chart1' */
  if (board_parameters_DW.temporalCounter_i1 < MAX_uint32_T) {
    board_parameters_DW.temporalCounter_i1++;
  }

  if (board_parameters_DW.is_active_c5_board_parameters == 0U) {
    board_parameters_DW.is_active_c5_board_parameters = 1U;
    board_parameters_DW.is_c5_board_parameters = board_parameters_IN_Start;
  } else {
    switch (board_parameters_DW.is_c5_board_parameters) {
     case board_parameters_IN_ARP_WAITING:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ARP_p) {
        board_parameters_DW.is_c5_board_parameters =
          board_parameters_IN_CHARGING;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACING_REF_PWM = board_parameters_B.Multiply;
        board_parameters_B.PACE_CHARGE_CTRL = true;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.VENT_PACE_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.ATR_PACE_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = true;
        board_parameters_B.VENT_GND_CTRL = false;
      }
      break;

     case board_parameters_IN_CHARGING:
      board_parameters_CHARGING_h(&board_parameters_B.Multiply,
        &board_parameters_B.DigitalRead1, &board_parameters_B.Add);
      break;

     case board_parameters_IN_PACING:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ATR_PW_o) {
        board_parameters_DW.is_c5_board_parameters =
          board_parameters_IN_ARP_WAITING;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.VENT_PACE_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.ATR_PACE_CTRL = true;
      }
      break;

     case board_paramete_IN_ARP_WAITING_b:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ARP_p) {
        board_parameters_DW.is_c5_board_parameters =
          board_parameters_IN_CHARGING_h;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACING_REF_PWM = board_parameters_B.Multiply;
        board_parameters_B.PACE_CHARGE_CTRL = true;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.VENT_PACE_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.ATR_PACE_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = true;
        board_parameters_B.VENT_GND_CTRL = false;
      }
      break;

     case board_parameters_IN_CHARGING_h:
      board_parameters_CHARGING(&board_parameters_B.Multiply,
        &board_parameters_B.DigitalRead1, &board_parameters_B.Add);
      break;

     case board_parameters_IN_PACING_i:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ATR_PW_o) {
        board_parameters_DW.is_c5_board_parameters =
          board_paramete_IN_ARP_WAITING_b;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.VENT_PACE_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.ATR_PACE_CTRL = true;
      }
      break;

     case board_parame_IN_ATRIAL_CHARGING:
      board_paramet_ATRIAL_CHARGING_c(&board_parameters_B.Multiply,
        &board_parameters_B.Add);
      break;

     case board_paramete_IN_ATRIAL_PACING:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ATR_PW_o) {
        board_parameters_DW.is_c5_board_parameters =
          board_parame_IN_ATRIAL_CHARGING;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.VENT_PACE_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.ATR_PACE_CTRL = true;
      }
      break;

     case board_para_IN_ATRIAL_CHARGING_k:
      board_parameter_ATRIAL_CHARGING(&board_parameters_B.Multiply,
        &board_parameters_B.Add);
      break;

     case board_parame_IN_ATRIAL_PACING_e:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ATR_PW_o) {
        board_parameters_DW.is_c5_board_parameters =
          board_para_IN_ATRIAL_CHARGING_k;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.VENT_PACE_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.ATR_PACE_CTRL = true;
      }
      break;

     case board_parameter_IN_ATR_CHARGING:
      board_parameters_ATR_CHARGING(&board_parameters_B.Multiply,
        &board_parameters_B.Add);
      break;

     case board_parameters_IN_ATR_PACING:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ATR_PW_o) {
        board_parameters_DW.is_c5_board_parameters =
          board_paramete_IN_VENT_CHARGING;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.VENT_PACE_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.ATR_PACE_CTRL = true;
      }
      break;

     case board_paramete_IN_VENT_CHARGING:
      board_paramete_VENT_CHARGING_fa(&board_parameters_B.Multiply1);
      break;

     case board_parameters_IN_VENT_PACING:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.VENT_PW_n) {
        board_parameters_DW.is_c5_board_parameters =
          board_parameter_IN_ATR_CHARGING;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.ATR_PACE_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.VENT_PACE_CTRL = true;
      }
      break;

     case board_paramet_IN_ATR_CHARGING_f:
      board_parameters_ATR_CHARGING_j(&board_parameters_B.Multiply,
        &board_parameters_B.Add);
      break;

     case board_parameter_IN_ATR_PACING_m:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ATR_PW_o) {
        board_parameters_DW.is_c5_board_parameters =
          board_parame_IN_VENT_CHARGING_c;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.VENT_PACE_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.ATR_PACE_CTRL = true;
      }
      break;

     case board_parame_IN_VENT_CHARGING_c:
      board_paramet_VENT_CHARGING_fac(&board_parameters_B.Multiply1);
      break;

     case board_paramete_IN_VENT_PACING_f:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.VENT_PW_n) {
        board_parameters_DW.is_c5_board_parameters =
          board_paramet_IN_ATR_CHARGING_f;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.ATR_PACE_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.VENT_PACE_CTRL = true;
      }
      break;

     case board_parameters_IN_Start:
      board_parameters_Start();
      break;

     case board_param_IN_VENT_CHARGING_ca:
      board_parame_VENT_CHARGING_fach(&board_parameters_B.Add,
        &board_parameters_B.Multiply1);
      break;

     case board_paramet_IN_VENT_PACING_fw:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.VENT_PW_n) {
        board_parameters_DW.is_c5_board_parameters =
          board_param_IN_VENT_CHARGING_ca;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.ATR_PACE_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.VENT_PACE_CTRL = true;
      }
      break;

     case board_para_IN_VENT_CHARGING_cai:
      board_parameters_VENT_CHARGING(&board_parameters_B.Add,
        &board_parameters_B.Multiply1);
      break;

     case board_parame_IN_VENT_PACING_fwp:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.VENT_PW_n) {
        board_parameters_DW.is_c5_board_parameters =
          board_para_IN_VENT_CHARGING_cai;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.ATR_PACE_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.VENT_PACE_CTRL = true;
      }
      break;

     case board_par_IN_VENT_CHARGING_caiq:
      board_param_VENT_CHARGING_facho(&board_parameters_B.DigitalRead,
        &board_parameters_B.Add, &board_parameters_B.Multiply1);
      break;

     case board_param_IN_VENT_PACING_fwph:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ATR_PW_o) {
        board_parameters_DW.is_c5_board_parameters =
          board_parameters_IN_VRP_WAITING;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.ATR_PACE_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.VENT_PACE_CTRL = true;
      }
      break;

     case board_parameters_IN_VRP_WAITING:
      board_parameters_VRP_WAITING_d(&board_parameters_B.Multiply1);
      break;

     case board_pa_IN_VENT_CHARGING_caiqs:
      board_parameter_VENT_CHARGING_f(&board_parameters_B.DigitalRead,
        &board_parameters_B.Add, &board_parameters_B.Multiply1);
      break;

     case board_para_IN_VENT_PACING_fwph3:
      if ((uint32_T)((int32_T)board_parameters_DW.temporalCounter_i1 * 10) >=
          board_parameters_B.ATR_PW_o) {
        board_parameters_DW.is_c5_board_parameters =
          board_paramete_IN_VRP_WAITING_i;
        board_parameters_DW.temporalCounter_i1 = 0U;
      } else {
        board_parameters_B.PACE_CHARGE_CTRL = false;
        board_parameters_B.PACE_GND_CTRL = true;
        board_parameters_B.ATR_PACE_CTRL = false;
        board_parameters_B.ATR_GND_CTRL = false;
        board_parameters_B.Z_ATR_CTRL = false;
        board_parameters_B.Z_VENT_CTRL = false;
        board_parameters_B.VENT_GND_CTRL = false;
        board_parameters_B.VENT_PACE_CTRL = true;
      }
      break;

     default:
      /* case IN_VRP_WAITING: */
      board_parameters_VRP_WAITING(&board_parameters_B.Multiply1);
      break;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* MATLABSystem: '<S2>/Digital Write1' */
  MW_digitalIO_write(board_parameters_DW.obj_lh.MW_DIGITALIO_HANDLE,
                     board_parameters_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S2>/Digital Write2' */
  MW_digitalIO_write(board_parameters_DW.obj_n.MW_DIGITALIO_HANDLE,
                     board_parameters_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write3' */
  MW_digitalIO_write(board_parameters_DW.obj_o.MW_DIGITALIO_HANDLE,
                     board_parameters_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write4' */
  MW_digitalIO_write(board_parameters_DW.obj_l.MW_DIGITALIO_HANDLE,
                     board_parameters_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S2>/Digital Write5' */
  MW_digitalIO_write(board_parameters_DW.obj_m1.MW_DIGITALIO_HANDLE,
                     board_parameters_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write6' */
  MW_digitalIO_write(board_parameters_DW.obj_c.MW_DIGITALIO_HANDLE,
                     board_parameters_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write7' */
  MW_digitalIO_write(board_parameters_DW.obj_k.MW_DIGITALIO_HANDLE,
                     board_parameters_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write8' */
  MW_digitalIO_write(board_parameters_DW.obj_p.MW_DIGITALIO_HANDLE,
                     board_parameters_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write9' */
  MW_digitalIO_write(board_parameters_DW.obj_h5.MW_DIGITALIO_HANDLE,
                     board_parameters_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S2>/PWM Output2' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Multiply'
   *  Product: '<S6>/Divide'
   */
  MW_PWM_SetDutyCycle(board_parameters_DW.obj_g.MW_PWM_HANDLE,
                      board_parameters_P.Multiply_Gain *
                      (board_parameters_B.VENT_AMP_m /
                       board_parameters_P.Constant_Value_k));

  /* MATLABSystem: '<S2>/PWM Output' */
  MW_PWM_SetDutyCycle(board_parameters_DW.obj_ov.MW_PWM_HANDLE,
                      board_parameters_B.PACING_REF_PWM);

  /* MATLABSystem: '<S2>/PWM Output1' incorporates:
   *  Constant: '<S7>/Constant'
   *  Gain: '<S7>/Multiply'
   *  Product: '<S7>/Divide'
   */
  MW_PWM_SetDutyCycle(board_parameters_DW.obj_hb.MW_PWM_HANDLE,
                      board_parameters_P.Multiply_Gain_m *
                      (board_parameters_B.ATR_AMP_h /
                       board_parameters_P.Constant_Value_o));

  /* MATLABSystem: '<S15>/Digital Write2' */
  MW_digitalIO_write(board_parameters_DW.obj_d3.MW_DIGITALIO_HANDLE,
                     board_parameters_B.red);

  /* MATLABSystem: '<S15>/Digital Write3' */
  MW_digitalIO_write(board_parameters_DW.obj_br.MW_DIGITALIO_HANDLE,
                     board_parameters_B.green);
}

/* Model step wrapper function for compatibility with a static main program */
void board_parameters_step(int_T tid)
{
  switch (tid) {
   case 0 :
    board_parameters_step0();
    break;

   case 1 :
    board_parameters_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void board_parameters_initialize(void)
{
  {
    dsp_simulink_MovingAverage_bo_T *obj_1;
    freedomk64f_DigitalRead_board_T *obj_0;
    freedomk64f_DigitalWrite_boar_T *obj;
    freedomk64f_PWMOutput_board_p_T *obj_3;
    freedomk64f_fxos8700_board_pa_T *obj_4;
    g_dsp_private_SlidingWindowAv_T *obj_2;

    /* Chart: '<S1>/Chart' */
    board_parameters_DW.is_c1_board_parameters = board_parameters_IN_initial;
    board_parameters_B.MODE = 2U;
    board_parameters_B.LRL = 100U;
    board_parameters_B.URL = 120U;
    board_parameters_B.MSR = 120U;
    board_parameters_B.VENT_AMP_m = 4.5F;
    board_parameters_B.VENT_PW_n = 10.5F;
    board_parameters_B.VRP_f = 310U;
    board_parameters_B.ATR_AMP_h = 3.5F;
    board_parameters_B.ATR_PW_o = 12.5F;
    board_parameters_B.ARP_p = 400U;
    board_parameters_B.A_THRESH = 20U;
    board_parameters_B.REACTION_T = 10U;
    board_parameters_B.RESPONSE_FACTOR = 10U;
    board_parameters_B.RECOVERY_T = 15U;
    board_parameters_B.AV_DELAY_p = 500U;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S1>/Function-Call Subsystem1' incorporates:
     *  SubSystem: '<S1>/Function-Call Subsystem1'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S1>/Function-Call Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S1>/Subsystem2' */
    /* Start for MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor1' */
    board_parameters_DW.obj_d.i2cobj.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_d.matlabCodegenIsDeleted = true;
    obj_4 = &board_parameters_DW.obj_d;
    board_parameters_DW.obj_d.isInitialized = 0;
    board_parameters_DW.obj_d.SampleTime = -1.0;
    obj_4->i2cobj.isInitialized = 0;
    obj_4->i2cobj.matlabCodegenIsDeleted = false;
    board_parameters_DW.obj_d.matlabCodegenIsDeleted = false;
    board_parameters_DW.obj_d.SampleTime =
      board_parameters_P.FXOS87006AxesSensor1_SampleTime;
    board_param_SystemCore_setup_dt(&board_parameters_DW.obj_d);

    /* SystemInitialize for MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor1' incorporates:
     *  Outport: '<S8>/Out1'
     */
    board_parameters_B.FXOS87006AxesSensor1[0] = board_parameters_P.Out1_Y0;
    board_parameters_B.FXOS87006AxesSensor1[1] = board_parameters_P.Out1_Y0;
    board_parameters_B.FXOS87006AxesSensor1[2] = board_parameters_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem2' */

    /* Start for MATLABSystem: '<S1>/Serial Receive' */
    board_parameters_DW.obj_m.isInitialized = 0;
    board_parameters_DW.obj_m.matlabCodegenIsDeleted = false;
    board_parameters_DW.obj_m.SampleTime =
      board_parameters_P.SerialReceive_SampleTime;
    board_parame_SystemCore_setup_d(&board_parameters_DW.obj_m);

    /* Start for MATLABSystem: '<S1>/Digital Write' */
    board_parameters_DW.obj_a.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_a.isInitialized = 0;
    board_parameters_DW.obj_a.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_a;
    board_parameters_DW.obj_a.isSetupComplete = false;
    board_parameters_DW.obj_a.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    board_parameters_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Read' */
    board_parameters_DW.obj_h.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_h.isInitialized = 0;
    board_parameters_DW.obj_h.SampleTime = -1.0;
    board_parameters_DW.obj_h.matlabCodegenIsDeleted = false;
    board_parameters_DW.obj_h.SampleTime =
      board_parameters_P.DigitalRead_SampleTime;
    obj_0 = &board_parameters_DW.obj_h;
    board_parameters_DW.obj_h.isSetupComplete = false;
    board_parameters_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    board_parameters_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Read1' */
    board_parameters_DW.obj_b.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_b.isInitialized = 0;
    board_parameters_DW.obj_b.SampleTime = -1.0;
    board_parameters_DW.obj_b.matlabCodegenIsDeleted = false;
    board_parameters_DW.obj_b.SampleTime =
      board_parameters_P.DigitalRead1_SampleTime;
    obj_0 = &board_parameters_DW.obj_b;
    board_parameters_DW.obj_b.isSetupComplete = false;
    board_parameters_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    board_parameters_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S15>/Moving Average' */
    board_parameters_DW.obj.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj.isInitialized = 0;
    board_parameters_DW.obj.NumChannels = -1;
    board_parameters_DW.obj.matlabCodegenIsDeleted = false;
    obj_1 = &board_parameters_DW.obj;
    board_parameters_DW.obj.isSetupComplete = false;
    board_parameters_DW.obj.isInitialized = 1;
    board_parameters_DW.obj.NumChannels = 1;
    obj_1->_pobj0.isInitialized = 0;
    board_parameters_DW.obj.pStatistic = &obj_1->_pobj0;
    board_parameters_DW.obj.isSetupComplete = true;
    board_parameters_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S15>/Moving Average' */
    obj_2 = board_parameters_DW.obj.pStatistic;
    if (obj_2->isInitialized == 1) {
      obj_2->pCumSum = 0.0;
      obj_2->pCumSumRev[0] = 0.0;
      obj_2->pCumSumRev[1] = 0.0;
      obj_2->pCumSumRev[2] = 0.0;
      obj_2->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S15>/Moving Average' */

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    board_parameters_DW.obj_lh.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_lh.isInitialized = 0;
    board_parameters_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_lh;
    board_parameters_DW.obj_lh.isSetupComplete = false;
    board_parameters_DW.obj_lh.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    board_parameters_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write2' */
    board_parameters_DW.obj_n.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_n.isInitialized = 0;
    board_parameters_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_n;
    board_parameters_DW.obj_n.isSetupComplete = false;
    board_parameters_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    board_parameters_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write3' */
    board_parameters_DW.obj_o.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_o.isInitialized = 0;
    board_parameters_DW.obj_o.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_o;
    board_parameters_DW.obj_o.isSetupComplete = false;
    board_parameters_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    board_parameters_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write4' */
    board_parameters_DW.obj_l.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_l.isInitialized = 0;
    board_parameters_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_l;
    board_parameters_DW.obj_l.isSetupComplete = false;
    board_parameters_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    board_parameters_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write5' */
    board_parameters_DW.obj_m1.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_m1.isInitialized = 0;
    board_parameters_DW.obj_m1.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_m1;
    board_parameters_DW.obj_m1.isSetupComplete = false;
    board_parameters_DW.obj_m1.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    board_parameters_DW.obj_m1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write6' */
    board_parameters_DW.obj_c.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_c.isInitialized = 0;
    board_parameters_DW.obj_c.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_c;
    board_parameters_DW.obj_c.isSetupComplete = false;
    board_parameters_DW.obj_c.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    board_parameters_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write7' */
    board_parameters_DW.obj_k.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_k.isInitialized = 0;
    board_parameters_DW.obj_k.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_k;
    board_parameters_DW.obj_k.isSetupComplete = false;
    board_parameters_DW.obj_k.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    board_parameters_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write8' */
    board_parameters_DW.obj_p.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_p.isInitialized = 0;
    board_parameters_DW.obj_p.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_p;
    board_parameters_DW.obj_p.isSetupComplete = false;
    board_parameters_DW.obj_p.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    board_parameters_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write9' */
    board_parameters_DW.obj_h5.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_h5.isInitialized = 0;
    board_parameters_DW.obj_h5.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_h5;
    board_parameters_DW.obj_h5.isSetupComplete = false;
    board_parameters_DW.obj_h5.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    board_parameters_DW.obj_h5.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output2' */
    board_parameters_DW.obj_g.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_g.isInitialized = 0;
    board_parameters_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_3 = &board_parameters_DW.obj_g;
    board_parameters_DW.obj_g.isSetupComplete = false;
    board_parameters_DW.obj_g.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(board_parameters_DW.obj_g.MW_PWM_HANDLE);
    board_parameters_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output' */
    board_parameters_DW.obj_ov.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_ov.isInitialized = 0;
    board_parameters_DW.obj_ov.matlabCodegenIsDeleted = false;
    obj_3 = &board_parameters_DW.obj_ov;
    board_parameters_DW.obj_ov.isSetupComplete = false;
    board_parameters_DW.obj_ov.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(board_parameters_DW.obj_ov.MW_PWM_HANDLE);
    board_parameters_DW.obj_ov.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output1' */
    board_parameters_DW.obj_hb.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_hb.isInitialized = 0;
    board_parameters_DW.obj_hb.matlabCodegenIsDeleted = false;
    obj_3 = &board_parameters_DW.obj_hb;
    board_parameters_DW.obj_hb.isSetupComplete = false;
    board_parameters_DW.obj_hb.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(board_parameters_DW.obj_hb.MW_PWM_HANDLE);
    board_parameters_DW.obj_hb.isSetupComplete = true;

    /* Start for MATLABSystem: '<S15>/Digital Write2' */
    board_parameters_DW.obj_d3.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_d3.isInitialized = 0;
    board_parameters_DW.obj_d3.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_d3;
    board_parameters_DW.obj_d3.isSetupComplete = false;
    board_parameters_DW.obj_d3.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    board_parameters_DW.obj_d3.isSetupComplete = true;

    /* Start for MATLABSystem: '<S15>/Digital Write3' */
    board_parameters_DW.obj_br.matlabCodegenIsDeleted = true;
    board_parameters_DW.obj_br.isInitialized = 0;
    board_parameters_DW.obj_br.matlabCodegenIsDeleted = false;
    obj = &board_parameters_DW.obj_br;
    board_parameters_DW.obj_br.isSetupComplete = false;
    board_parameters_DW.obj_br.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    board_parameters_DW.obj_br.isSetupComplete = true;
  }
}

/* Model terminate function */
void board_parameters_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj_1;
  freedomk64f_fxos8700_board_pa_T *obj_0;
  g_dsp_private_SlidingWindowAv_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Serial Receive' */
  if (!board_parameters_DW.obj_m.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_m.isInitialized == 1) &&
        board_parameters_DW.obj_m.isSetupComplete) {
      MW_SCI_Close(board_parameters_DW.obj_m.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Serial Receive' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  if (!board_parameters_DW.obj_a.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_a.isInitialized == 1) &&
        board_parameters_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<S1>/Function-Call Subsystem1' incorporates:
   *  SubSystem: '<S1>/Function-Call Subsystem1'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S1>/Function-Call Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S1>/Subsystem2' */
  /* Terminate for MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor1' */
  obj_0 = &board_parameters_DW.obj_d;
  if (!board_parameters_DW.obj_d.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_d.isInitialized == 1) &&
        board_parameters_DW.obj_d.isSetupComplete) {
      MW_I2C_Close(obj_0->i2cobj.MW_I2C_HANDLE);
    }
  }

  obj_1 = &board_parameters_DW.obj_d.i2cobj;
  if (!obj_1->matlabCodegenIsDeleted) {
    obj_1->matlabCodegenIsDeleted = true;
    if (obj_1->isInitialized == 1) {
      obj_1->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor1' */
  /* End of Terminate for SubSystem: '<S1>/Subsystem2' */

  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  if (!board_parameters_DW.obj_h.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_h.isInitialized == 1) &&
        board_parameters_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Read' */

  /* Terminate for MATLABSystem: '<S2>/Digital Read1' */
  if (!board_parameters_DW.obj_b.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_b.isInitialized == 1) &&
        board_parameters_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S15>/Moving Average' */
  if (!board_parameters_DW.obj.matlabCodegenIsDeleted) {
    board_parameters_DW.obj.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj.isInitialized == 1) &&
        board_parameters_DW.obj.isSetupComplete) {
      obj = board_parameters_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      board_parameters_DW.obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Moving Average' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  if (!board_parameters_DW.obj_lh.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_lh.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_lh.isInitialized == 1) &&
        board_parameters_DW.obj_lh.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_lh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write2' */
  if (!board_parameters_DW.obj_n.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_n.isInitialized == 1) &&
        board_parameters_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write3' */
  if (!board_parameters_DW.obj_o.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_o.isInitialized == 1) &&
        board_parameters_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write4' */
  if (!board_parameters_DW.obj_l.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_l.isInitialized == 1) &&
        board_parameters_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write5' */
  if (!board_parameters_DW.obj_m1.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_m1.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_m1.isInitialized == 1) &&
        board_parameters_DW.obj_m1.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_m1.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write6' */
  if (!board_parameters_DW.obj_c.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_c.isInitialized == 1) &&
        board_parameters_DW.obj_c.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_c.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write7' */
  if (!board_parameters_DW.obj_k.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_k.isInitialized == 1) &&
        board_parameters_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write8' */
  if (!board_parameters_DW.obj_p.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_p.isInitialized == 1) &&
        board_parameters_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write9' */
  if (!board_parameters_DW.obj_h5.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_h5.isInitialized == 1) &&
        board_parameters_DW.obj_h5.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_h5.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write9' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output2' */
  if (!board_parameters_DW.obj_g.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_g.isInitialized == 1) &&
        board_parameters_DW.obj_g.isSetupComplete) {
      MW_PWM_Stop(board_parameters_DW.obj_g.MW_PWM_HANDLE);
      MW_PWM_Close(board_parameters_DW.obj_g.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output2' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output' */
  if (!board_parameters_DW.obj_ov.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_ov.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_ov.isInitialized == 1) &&
        board_parameters_DW.obj_ov.isSetupComplete) {
      MW_PWM_Stop(board_parameters_DW.obj_ov.MW_PWM_HANDLE);
      MW_PWM_Close(board_parameters_DW.obj_ov.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output1' */
  if (!board_parameters_DW.obj_hb.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_hb.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_hb.isInitialized == 1) &&
        board_parameters_DW.obj_hb.isSetupComplete) {
      MW_PWM_Stop(board_parameters_DW.obj_hb.MW_PWM_HANDLE);
      MW_PWM_Close(board_parameters_DW.obj_hb.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S15>/Digital Write2' */
  if (!board_parameters_DW.obj_d3.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_d3.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_d3.isInitialized == 1) &&
        board_parameters_DW.obj_d3.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_d3.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S15>/Digital Write3' */
  if (!board_parameters_DW.obj_br.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_br.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_br.isInitialized == 1) &&
        board_parameters_DW.obj_br.isSetupComplete) {
      MW_digitalIO_close(board_parameters_DW.obj_br.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Digital Write3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
