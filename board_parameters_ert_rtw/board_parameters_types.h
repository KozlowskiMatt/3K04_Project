/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: board_parameters_types.h
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

#ifndef RTW_HEADER_board_parameters_types_h_
#define RTW_HEADER_board_parameters_types_h_
#include "rtwtypes.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S5>/Serial Transmit' */
#include "MW_SVD.h"
#ifndef struct_tag_bvK2L41g8z1P0jzpdjsJhE
#define struct_tag_bvK2L41g8z1P0jzpdjsJhE

struct tag_bvK2L41g8z1P0jzpdjsJhE
{
  int32_T __dummy;
};

#endif                                 /*struct_tag_bvK2L41g8z1P0jzpdjsJhE*/

#ifndef typedef_b_freedomk64f_Hardware_board__T
#define typedef_b_freedomk64f_Hardware_board__T

typedef struct tag_bvK2L41g8z1P0jzpdjsJhE b_freedomk64f_Hardware_board__T;

#endif                               /*typedef_b_freedomk64f_Hardware_board__T*/

#ifndef struct_tag_WltE1qT51p3S2KRQQd2Zd
#define struct_tag_WltE1qT51p3S2KRQQd2Zd

struct tag_WltE1qT51p3S2KRQQd2Zd
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_board__T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /*struct_tag_WltE1qT51p3S2KRQQd2Zd*/

#ifndef typedef_freedomk64f_SCIWrite_board_pa_T
#define typedef_freedomk64f_SCIWrite_board_pa_T

typedef struct tag_WltE1qT51p3S2KRQQd2Zd freedomk64f_SCIWrite_board_pa_T;

#endif                               /*typedef_freedomk64f_SCIWrite_board_pa_T*/

/* Custom Type definition for MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor1' */
#include "MW_I2C.h"
#ifndef struct_tag_n6PybfofDJX1nilXyEd0pE
#define struct_tag_n6PybfofDJX1nilXyEd0pE

struct tag_n6PybfofDJX1nilXyEd0pE
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[3];
  real_T pCumRevIndex;
};

#endif                                 /*struct_tag_n6PybfofDJX1nilXyEd0pE*/

#ifndef typedef_g_dsp_private_SlidingWindowAv_T
#define typedef_g_dsp_private_SlidingWindowAv_T

typedef struct tag_n6PybfofDJX1nilXyEd0pE g_dsp_private_SlidingWindowAv_T;

#endif                               /*typedef_g_dsp_private_SlidingWindowAv_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_board_parameters_T
#define typedef_cell_wrap_board_parameters_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_board_parameters_T;

#endif                                 /*typedef_cell_wrap_board_parameters_T*/

#ifndef struct_tag_i9IfhfSX0XccmEaqGxzasC
#define struct_tag_i9IfhfSX0XccmEaqGxzasC

struct tag_i9IfhfSX0XccmEaqGxzasC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_board_parameters_T inputVarSize;
  g_dsp_private_SlidingWindowAv_T *pStatistic;
  int32_T NumChannels;
  g_dsp_private_SlidingWindowAv_T _pobj0;
};

#endif                                 /*struct_tag_i9IfhfSX0XccmEaqGxzasC*/

#ifndef typedef_dsp_simulink_MovingAverage_bo_T
#define typedef_dsp_simulink_MovingAverage_bo_T

typedef struct tag_i9IfhfSX0XccmEaqGxzasC dsp_simulink_MovingAverage_bo_T;

#endif                               /*typedef_dsp_simulink_MovingAverage_bo_T*/

#ifndef struct_tag_62aCTDKRGQaAsT8vVipI2D
#define struct_tag_62aCTDKRGQaAsT8vVipI2D

struct tag_62aCTDKRGQaAsT8vVipI2D
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_board__T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /*struct_tag_62aCTDKRGQaAsT8vVipI2D*/

#ifndef typedef_freedomk64f_DigitalWrite_boar_T
#define typedef_freedomk64f_DigitalWrite_boar_T

typedef struct tag_62aCTDKRGQaAsT8vVipI2D freedomk64f_DigitalWrite_boar_T;

#endif                               /*typedef_freedomk64f_DigitalWrite_boar_T*/

#ifndef struct_tag_79weVYaslRFZRGk3pNTXC
#define struct_tag_79weVYaslRFZRGk3pNTXC

struct tag_79weVYaslRFZRGk3pNTXC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_board__T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_79weVYaslRFZRGk3pNTXC*/

#ifndef typedef_freedomk64f_SCIRead_board_par_T
#define typedef_freedomk64f_SCIRead_board_par_T

typedef struct tag_79weVYaslRFZRGk3pNTXC freedomk64f_SCIRead_board_par_T;

#endif                               /*typedef_freedomk64f_SCIRead_board_par_T*/

#ifndef struct_tag_dJFZzmsGU3XebjMxPxDlh
#define struct_tag_dJFZzmsGU3XebjMxPxDlh

struct tag_dJFZzmsGU3XebjMxPxDlh
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  b_freedomk64f_Hardware_board__T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /*struct_tag_dJFZzmsGU3XebjMxPxDlh*/

#ifndef typedef_b_freedomk64f_I2CMasterWrite__T
#define typedef_b_freedomk64f_I2CMasterWrite__T

typedef struct tag_dJFZzmsGU3XebjMxPxDlh b_freedomk64f_I2CMasterWrite__T;

#endif                               /*typedef_b_freedomk64f_I2CMasterWrite__T*/

#ifndef struct_tag_IfyqWdTTOITb2iei5A9qmC
#define struct_tag_IfyqWdTTOITb2iei5A9qmC

struct tag_IfyqWdTTOITb2iei5A9qmC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  b_freedomk64f_I2CMasterWrite__T i2cobj;
};

#endif                                 /*struct_tag_IfyqWdTTOITb2iei5A9qmC*/

#ifndef typedef_freedomk64f_fxos8700_board_pa_T
#define typedef_freedomk64f_fxos8700_board_pa_T

typedef struct tag_IfyqWdTTOITb2iei5A9qmC freedomk64f_fxos8700_board_pa_T;

#endif                               /*typedef_freedomk64f_fxos8700_board_pa_T*/

#ifndef struct_tag_gY1zYXXyNHJpvdqiHJr34G
#define struct_tag_gY1zYXXyNHJpvdqiHJr34G

struct tag_gY1zYXXyNHJpvdqiHJr34G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_board__T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_gY1zYXXyNHJpvdqiHJr34G*/

#ifndef typedef_freedomk64f_DigitalRead_board_T
#define typedef_freedomk64f_DigitalRead_board_T

typedef struct tag_gY1zYXXyNHJpvdqiHJr34G freedomk64f_DigitalRead_board_T;

#endif                               /*typedef_freedomk64f_DigitalRead_board_T*/

#ifndef struct_tag_asB9FwAteE1VObOuq1LwyE
#define struct_tag_asB9FwAteE1VObOuq1LwyE

struct tag_asB9FwAteE1VObOuq1LwyE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_board__T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /*struct_tag_asB9FwAteE1VObOuq1LwyE*/

#ifndef typedef_freedomk64f_PWMOutput_board_p_T
#define typedef_freedomk64f_PWMOutput_board_p_T

typedef struct tag_asB9FwAteE1VObOuq1LwyE freedomk64f_PWMOutput_board_p_T;

#endif                               /*typedef_freedomk64f_PWMOutput_board_p_T*/

/* Parameters (default storage) */
typedef struct P_board_parameters_T_ P_board_parameters_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_board_parameters_T RT_MODEL_board_parameters_T;

#endif                                /* RTW_HEADER_board_parameters_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
