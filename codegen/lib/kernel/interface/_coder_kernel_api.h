/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_kernel_api.h
 *
 * Code generation for function 'kernel'
 *
 */

#ifndef _CODER_KERNEL_API_H
#define _CODER_KERNEL_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void kernel(void);

void kernel_api(void);

void kernel_atexit(void);

void kernel_initialize(void);

void kernel_terminate(void);

void kernel_xil_shutdown(void);

void kernel_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_kernel_api.h) */
