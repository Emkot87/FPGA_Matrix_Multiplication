#ifndef LAB1_H
#define LAB1_H

#include <ap_int.h>

#define lm 6
#define ln 6
#define lp 6

#define m  1<<lm
#define n  1<<ln
#define p  1<<lp

void MATRIX_MUL(ap_uint<8> A[n][m], ap_uint<8> B[m][p], int out[n][p]);

#endif
