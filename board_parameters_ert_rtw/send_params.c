/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params.c
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

#include "send_params.h"

/* Include model header file for global data */
#include "board_parameters.h"
#include "board_parameters_private.h"

/* Forward declaration for local functions */
static void board_paramete_SystemCore_setup(freedomk64f_SCIWrite_board_pa_T *obj);
static void board_paramete_SystemCore_setup(freedomk64f_SCIWrite_board_pa_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<S1>/Function-Call Subsystem1' */
void send_params_Init(void)
{
  /* Start for MATLABSystem: '<S5>/Serial Transmit' */
  board_parameters_DW.obj_i.isInitialized = 0;
  board_parameters_DW.obj_i.matlabCodegenIsDeleted = false;
  board_paramete_SystemCore_setup(&board_parameters_DW.obj_i);
}

/* Output and update for Simulink Function: '<S1>/Function-Call Subsystem1' */
void send_params(void)
{
  uint8_T TxDataLocChar[30];
  uint8_T rtb_TmpSignalConversionAtSerial[30];
  uint8_T status;

  /* SignalConversion generated from: '<S5>/VENT AMPLITUDE' */
  board_parameters_B.VENT_AMP = board_parameters_B.VENT_AMP_m;

  /* SignalConversion generated from: '<S5>/VRP' */
  board_parameters_B.VRP = board_parameters_B.VRP_f;

  /* SignalConversion generated from: '<S5>/VENT PULSE WIDTH' */
  board_parameters_B.VENT_PW = board_parameters_B.VENT_PW_n;

  /* SignalConversion generated from: '<S5>/ATR AMPLITUDE' */
  board_parameters_B.ATR_AMP = board_parameters_B.ATR_AMP_h;

  /* SignalConversion generated from: '<S5>/ATR PULSE WIDTH' */
  board_parameters_B.ATR_PW = board_parameters_B.ATR_PW_o;

  /* SignalConversion generated from: '<S5>/ARP' */
  board_parameters_B.ARP = board_parameters_B.ARP_p;

  /* SignalConversion generated from: '<S5>/AV DELAY' */
  board_parameters_B.AV_DELAY = board_parameters_B.AV_DELAY_p;

  /* S-Function (any2byte): '<S5>/Byte Pack' */

  /* Pack: <S5>/Byte Pack */
  (void) memcpy(&board_parameters_B.BytePack[0], &board_parameters_B.VENT_AMP,
                4);

  /* S-Function (any2byte): '<S5>/Byte Pack1' */

  /* Pack: <S5>/Byte Pack1 */
  (void) memcpy(&board_parameters_B.BytePack1[0], &board_parameters_B.VENT_PW,
                4);

  /* S-Function (any2byte): '<S5>/Byte Pack2' */

  /* Pack: <S5>/Byte Pack2 */
  (void) memcpy(&board_parameters_B.BytePack2[0], &board_parameters_B.VRP,
                2);

  /* S-Function (any2byte): '<S5>/Byte Pack3' */

  /* Pack: <S5>/Byte Pack3 */
  (void) memcpy(&board_parameters_B.BytePack3[0], &board_parameters_B.ATR_AMP,
                4);

  /* S-Function (any2byte): '<S5>/Byte Pack4' */

  /* Pack: <S5>/Byte Pack4 */
  (void) memcpy(&board_parameters_B.BytePack4[0], &board_parameters_B.ATR_PW,
                4);

  /* S-Function (any2byte): '<S5>/Byte Pack5' */

  /* Pack: <S5>/Byte Pack5 */
  (void) memcpy(&board_parameters_B.BytePack5[0], &board_parameters_B.ARP,
                2);

  /* S-Function (any2byte): '<S5>/Byte Pack6' */

  /* Pack: <S5>/Byte Pack6 */
  (void) memcpy(&board_parameters_B.BytePack6[0], &board_parameters_B.AV_DELAY,
                2);

  /* SignalConversion generated from: '<S5>/Serial Transmit' incorporates:
   *  SignalConversion generated from: '<S5>/ACTIVITY THRESHOLD'
   *  SignalConversion generated from: '<S5>/LOWER RATE LIMIT'
   *  SignalConversion generated from: '<S5>/MAX SENSOR RATE'
   *  SignalConversion generated from: '<S5>/MODE'
   *  SignalConversion generated from: '<S5>/REACTION TIME'
   *  SignalConversion generated from: '<S5>/RECOVERY TIME'
   *  SignalConversion generated from: '<S5>/RESPONSE FACTOR'
   *  SignalConversion generated from: '<S5>/UPPER RATE LIMIT'
   */
  rtb_TmpSignalConversionAtSerial[0] = board_parameters_B.MODE;
  rtb_TmpSignalConversionAtSerial[1] = board_parameters_B.LRL;
  rtb_TmpSignalConversionAtSerial[2] = board_parameters_B.URL;
  rtb_TmpSignalConversionAtSerial[3] = board_parameters_B.MSR;
  rtb_TmpSignalConversionAtSerial[4] = board_parameters_B.BytePack[0];
  rtb_TmpSignalConversionAtSerial[8] = board_parameters_B.BytePack1[0];
  rtb_TmpSignalConversionAtSerial[5] = board_parameters_B.BytePack[1];
  rtb_TmpSignalConversionAtSerial[9] = board_parameters_B.BytePack1[1];
  rtb_TmpSignalConversionAtSerial[6] = board_parameters_B.BytePack[2];
  rtb_TmpSignalConversionAtSerial[10] = board_parameters_B.BytePack1[2];
  rtb_TmpSignalConversionAtSerial[7] = board_parameters_B.BytePack[3];
  rtb_TmpSignalConversionAtSerial[11] = board_parameters_B.BytePack1[3];
  rtb_TmpSignalConversionAtSerial[12] = board_parameters_B.BytePack2[0];
  rtb_TmpSignalConversionAtSerial[13] = board_parameters_B.BytePack2[1];
  rtb_TmpSignalConversionAtSerial[14] = board_parameters_B.BytePack3[0];
  rtb_TmpSignalConversionAtSerial[18] = board_parameters_B.BytePack4[0];
  rtb_TmpSignalConversionAtSerial[15] = board_parameters_B.BytePack3[1];
  rtb_TmpSignalConversionAtSerial[19] = board_parameters_B.BytePack4[1];
  rtb_TmpSignalConversionAtSerial[16] = board_parameters_B.BytePack3[2];
  rtb_TmpSignalConversionAtSerial[20] = board_parameters_B.BytePack4[2];
  rtb_TmpSignalConversionAtSerial[17] = board_parameters_B.BytePack3[3];
  rtb_TmpSignalConversionAtSerial[21] = board_parameters_B.BytePack4[3];
  rtb_TmpSignalConversionAtSerial[24] = board_parameters_B.A_THRESH;
  rtb_TmpSignalConversionAtSerial[25] = board_parameters_B.REACTION_T;
  rtb_TmpSignalConversionAtSerial[26] = board_parameters_B.RESPONSE_FACTOR;
  rtb_TmpSignalConversionAtSerial[27] = board_parameters_B.RECOVERY_T;
  rtb_TmpSignalConversionAtSerial[22] = board_parameters_B.BytePack5[0];
  rtb_TmpSignalConversionAtSerial[28] = board_parameters_B.BytePack6[0];
  rtb_TmpSignalConversionAtSerial[23] = board_parameters_B.BytePack5[1];
  rtb_TmpSignalConversionAtSerial[29] = board_parameters_B.BytePack6[1];

  /* MATLABSystem: '<S5>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&TxDataLocChar[0], (void *)&rtb_TmpSignalConversionAtSerial[0],
           (uint32_T)((size_t)30 * sizeof(uint8_T)));
    status = MW_SCI_Transmit(board_parameters_DW.obj_i.MW_SCIHANDLE,
      &TxDataLocChar[0], 30U);
  }

  /* End of MATLABSystem: '<S5>/Serial Transmit' */
}

/* Termination for Simulink Function: '<S1>/Function-Call Subsystem1' */
void send_params_Term(void)
{
  /* Terminate for MATLABSystem: '<S5>/Serial Transmit' */
  if (!board_parameters_DW.obj_i.matlabCodegenIsDeleted) {
    board_parameters_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((board_parameters_DW.obj_i.isInitialized == 1) &&
        board_parameters_DW.obj_i.isSetupComplete) {
      MW_SCI_Close(board_parameters_DW.obj_i.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
