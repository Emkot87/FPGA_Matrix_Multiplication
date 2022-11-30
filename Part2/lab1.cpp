#include "lab1.h"


void MATRIX_MUL(ap_uint<8> A[n][m], ap_uint<8> B[m][p], int out[n][p]){

	const int loop = m;

	ap_uint<8> A_bram[n][m];
	ap_uint<8> B_bram[m][p];

#pragma HLS ARRAY_PARTITION variable=A_bram cyclic factor 32 dim=2
#pragma HLS ARRAY_PARTITION variable=B_bram cyclic factor 32 dim=1


	for(int i = 0; i < n; i++){
#pragma HLS loop_tripcount min=loop max=loop
			for(int j = 0; j < m; j++){
#pragma HLS loop_tripcount min=loop max=loop
#pragma HLS PIPELINE II=1
				A_bram[i][j] = A[i][j];
			}
		}


	for(int i = 0; i < m; i++){
		#pragma HLS loop_tripcount min=loop max=loop
			for(int j = 0; j < p; j++){
			#pragma HLS loop_tripcount min=loop max=loop

				#pragma HLS PIPELINE II=1
				B_bram[i][j] = B[i][j];
			}
		}


	for(int i = 0; i < n; i++){
		#pragma HLS loop_tripcount min=loop max=loop
			for(int j = 0; j < p; j++){
			#pragma HLS loop_tripcount min=loop max=loop

				#pragma HLS PIPELINE II=1
				int result = 0;
				for(int k = 0 ; k < m ; k++){
					result += A_bram[i][k] * B_bram[k][j];
				}
				out[i][j] = result;
			}
		}






}


//void MATRIX_MUL(ap_uint<8> A[n][m], ap_uint<8> B[m][p], int out[n][p]){
//
//	const int loop = m;
//
//	for(int i = 0; i < n; i++){
//		#pragma HLS loop_tripcount min=loop max=loop
//			for(int j = 0; j < p; j++){
//			#pragma HLS loop_tripcount min=loop max=loop
//
//				int result = 0;
//				for(int k = 0 ; k < m ; k++){
//					result += A[i][k] * B[k][j];
//				}
//				out[i][j] = result;
//			}
//		}
//
//}
