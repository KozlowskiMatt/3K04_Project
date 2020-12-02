/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_parameters.h
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

#ifndef RTW_HEADER_board_parameters_h_
#define RTW_HEADER_board_parameters_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef board_parameters_COMMON_INCLUDES_
#define board_parameters_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_SCI.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#endif                                 /* board_parameters_COMMON_INCLUDES_ */

#include "board_parameters_types.h"

/* Child system includes */
#include "send_params_private.h"
#include "send_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[33];
  uint8_T RxDataLocChar[33];
  real_T csumrev[3];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T PACING_REF_PWM;               /* '<S3>/Chart1' */
  real_T FXOS87006AxesSensor1[3];      /* '<S8>/FXOS8700 6-Axes Sensor1' */
  real_T cumRevIndex;
  real_T csum;
  real_T z;
  real_T Add;                          /* '<S15>/Add' */
  real_T Multiply;
  real_T Multiply1;
  int16_T b_output[3];
  uint8_T output_raw[6];
  real32_T VENT_AMP;
  real32_T VENT_PW;
  real32_T ATR_AMP;
  real32_T ATR_PW;
  real32_T VENT_AMP_m;                 /* '<S1>/Chart' */
  real32_T VENT_PW_n;                  /* '<S1>/Chart' */
  real32_T ATR_AMP_h;                  /* '<S1>/Chart' */
  real32_T ATR_PW_o;                   /* '<S1>/Chart' */
  real32_T f;
  int32_T i;
  int32_T i1;
  uint32_T qY;
  uint16_T VRP;
  uint16_T ARP;
  uint16_T AV_DELAY;
  uint16_T VRP_f;                      /* '<S1>/Chart' */
  uint16_T ARP_p;                      /* '<S1>/Chart' */
  uint16_T AV_DELAY_p;                 /* '<S1>/Chart' */
  uint8_T BytePack4[4];                /* '<S5>/Byte Pack4' */
  uint8_T BytePack5[2];                /* '<S5>/Byte Pack5' */
  uint8_T BytePack6[2];                /* '<S5>/Byte Pack6' */
  uint8_T y[2];
  uint8_T b_x[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T OUTPUT_PACE;                 /* '<S15>/Chart' */
  uint8_T BytePack[4];                 /* '<S5>/Byte Pack' */
  uint8_T BytePack1[4];                /* '<S5>/Byte Pack1' */
  uint8_T BytePack2[2];                /* '<S5>/Byte Pack2' */
  uint8_T BytePack3[4];                /* '<S5>/Byte Pack3' */
  uint8_T MODE;                        /* '<S1>/Chart' */
  uint8_T LRL;                         /* '<S1>/Chart' */
  uint8_T URL;                         /* '<S1>/Chart' */
  uint8_T MSR;                         /* '<S1>/Chart' */
  uint8_T A_THRESH;                    /* '<S1>/Chart' */
  uint8_T REACTION_T;                  /* '<S1>/Chart' */
  uint8_T RESPONSE_FACTOR;             /* '<S1>/Chart' */
  uint8_T RECOVERY_T;                  /* '<S1>/Chart' */
  uint8_T x;
  uint8_T status;
  uint8_T b_RegisterValue;
  uint8_T status_m;
  boolean_T green;                     /* '<S15>/Chart' */
  boolean_T red;                       /* '<S15>/Chart' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S3>/Chart1' */
  boolean_T Z_ATR_CTRL;                /* '<S3>/Chart1' */
  boolean_T ATR_PACE_CTRL;             /* '<S3>/Chart1' */
  boolean_T Z_VENT_CTRL;               /* '<S3>/Chart1' */
  boolean_T VENT_PACE_CTRL;            /* '<S3>/Chart1' */
  boolean_T PACE_GND_CTRL;             /* '<S3>/Chart1' */
  boolean_T ATR_GND_CTRL;              /* '<S3>/Chart1' */
  boolean_T VENT_GND_CTRL;             /* '<S3>/Chart1' */
  boolean_T FRONTEND_CTRL;             /* '<S3>/Chart1' */
  boolean_T DigitalRead1;
  boolean_T DigitalRead;
} B_board_parameters_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_bo_T obj; /* '<S15>/Moving Average' */
  freedomk64f_fxos8700_board_pa_T obj_d;/* '<S8>/FXOS8700 6-Axes Sensor1' */
  freedomk64f_SCIRead_board_par_T obj_m;/* '<S1>/Serial Receive' */
  freedomk64f_DigitalRead_board_T obj_b;/* '<S2>/Digital Read1' */
  freedomk64f_DigitalRead_board_T obj_h;/* '<S2>/Digital Read' */
  freedomk64f_DigitalWrite_boar_T obj_br;/* '<S15>/Digital Write3' */
  freedomk64f_DigitalWrite_boar_T obj_d3;/* '<S15>/Digital Write2' */
  freedomk64f_DigitalWrite_boar_T obj_h5;/* '<S2>/Digital Write9' */
  freedomk64f_DigitalWrite_boar_T obj_p;/* '<S2>/Digital Write8' */
  freedomk64f_DigitalWrite_boar_T obj_k;/* '<S2>/Digital Write7' */
  freedomk64f_DigitalWrite_boar_T obj_c;/* '<S2>/Digital Write6' */
  freedomk64f_DigitalWrite_boar_T obj_m1;/* '<S2>/Digital Write5' */
  freedomk64f_DigitalWrite_boar_T obj_l;/* '<S2>/Digital Write4' */
  freedomk64f_DigitalWrite_boar_T obj_o;/* '<S2>/Digital Write3' */
  freedomk64f_DigitalWrite_boar_T obj_n;/* '<S2>/Digital Write2' */
  freedomk64f_DigitalWrite_boar_T obj_lh;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_boar_T obj_a;/* '<S1>/Digital Write' */
  freedomk64f_SCIWrite_board_pa_T obj_i;/* '<S5>/Serial Transmit' */
  freedomk64f_PWMOutput_board_p_T obj_g;/* '<S2>/PWM Output2' */
  freedomk64f_PWMOutput_board_p_T obj_hb;/* '<S2>/PWM Output1' */
  freedomk64f_PWMOutput_board_p_T obj_ov;/* '<S2>/PWM Output' */
  real_T time;                         /* '<S15>/Chart' */
  uint32_T temporalCounter_i1;         /* '<S3>/Chart1' */
  uint8_T is_active_c7_board_parameters;/* '<S15>/Chart' */
  uint8_T is_c7_board_parameters;      /* '<S15>/Chart' */
  uint8_T REMAINING_RATE;              /* '<S15>/Chart' */
  uint8_T is_active_c5_board_parameters;/* '<S3>/Chart1' */
  uint8_T is_c5_board_parameters;      /* '<S3>/Chart1' */
  uint8_T is_c1_board_parameters;      /* '<S1>/Chart' */
} DW_board_parameters_T;

/* Parameters (default storage) */
struct P_board_parameters_T_ {
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S1>/Serial Receive'
                                        */
  real_T FXOS87006AxesSensor1_SampleTime;/* Expression: 1/100
                                          * Referenced by: '<S8>/FXOS8700 6-Axes Sensor1'
                                          */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S8>/Out1'
                                        */
  real_T Constant14_Value;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant14'
                                        */
  real_T Constant15_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant15'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read1'
                                        */
  real_T Constant_Value;               /* Expression: 60000
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 60000
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 5
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Multiply_Gain;                /* Expression: 100
                                        * Referenced by: '<S6>/Multiply'
                                        */
  real_T Constant_Value_o;             /* Expression: 5
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Multiply_Gain_m;              /* Expression: 100
                                        * Referenced by: '<S7>/Multiply'
                                        */
  real_T Constant_Value_oq;            /* Expression: 5
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Multiply_Gain_b;              /* Expression: 100
                                        * Referenced by: '<S10>/Multiply'
                                        */
  real_T Constant1_Value;              /* Expression: 5
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Multiply1_Gain;               /* Expression: 100
                                        * Referenced by: '<S10>/Multiply1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1.8
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S11>/Switch'
                                        */
  uint8_T Switch1_Threshold;           /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S1>/Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_board_parameters_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_board_parameters_T board_parameters_P;

/* Block signals (default storage) */
extern B_board_parameters_T board_parameters_B;

/* Block states (default storage) */
extern DW_board_parameters_T board_parameters_DW;

/* External function called from main */
extern void board_parameters_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void board_parameters_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void board_parameters_initialize(void);
extern void board_parameters_step(int_T tid);
extern void board_parameters_terminate(void);

/* Real-time Model object */
extern RT_MODEL_board_parameters_T *const board_parameters_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'board_parameters'
 * '<S1>'   : 'board_parameters/INPUT_DATA'
 * '<S2>'   : 'board_parameters/PIN_ASSIGNMENT'
 * '<S3>'   : 'board_parameters/STATE_FLOW'
 * '<S4>'   : 'board_parameters/INPUT_DATA/Chart'
 * '<S5>'   : 'board_parameters/INPUT_DATA/Function-Call Subsystem1'
 * '<S6>'   : 'board_parameters/INPUT_DATA/Subsystem'
 * '<S7>'   : 'board_parameters/INPUT_DATA/Subsystem1'
 * '<S8>'   : 'board_parameters/INPUT_DATA/Subsystem2'
 * '<S9>'   : 'board_parameters/STATE_FLOW/Chart1'
 * '<S10>'  : 'board_parameters/STATE_FLOW/STEPUP_CONVERTER1'
 * '<S11>'  : 'board_parameters/STATE_FLOW/Subsystem1'
 * '<S12>'  : 'board_parameters/STATE_FLOW/Subsystem1/INTERVAL_CALCULATION'
 * '<S13>'  : 'board_parameters/STATE_FLOW/Subsystem1/MATLAB Function'
 * '<S14>'  : 'board_parameters/STATE_FLOW/Subsystem1/RATE ADAPTIVE INTERVAL CALCULATION'
 * '<S15>'  : 'board_parameters/STATE_FLOW/Subsystem1/RATE ADAPTIVE INTERVAL CALCULATION/RATE ADAPTIVE PACE CALCULATION IN PPM'
 * '<S16>'  : 'board_parameters/STATE_FLOW/Subsystem1/RATE ADAPTIVE INTERVAL CALCULATION/RATE ADAPTIVE PACE CALCULATION IN PPM/Chart'
 * '<S17>'  : 'board_parameters/STATE_FLOW/Subsystem1/RATE ADAPTIVE INTERVAL CALCULATION/RATE ADAPTIVE PACE CALCULATION IN PPM/MATLAB Function'
 * '<S18>'  : 'board_parameters/STATE_FLOW/Subsystem1/RATE ADAPTIVE INTERVAL CALCULATION/RATE ADAPTIVE PACE CALCULATION IN PPM/Subsystem'
 */
#endif                                 /* RTW_HEADER_board_parameters_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
