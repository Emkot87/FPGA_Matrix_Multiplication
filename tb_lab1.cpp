#include "lab1.h"
#include <stdio.h>
#include <stdlib.h>

void sw_multiplication(ap_uint<8> A[n][m], ap_uint<8> B[m][p], int out[n][p]){


	for(int i = 0; i < n; i++){
		for(int j = 0; j < p; j++){
			int result = 0;
			for(int k = 0; k < m ; k++){
				result += A[i][k] * B[k][j];
			}
			out[i][j] = result;
		}
	}

}


int main(int argc, char** argv){

	bool check = true;

	ap_uint<8> in1[n][m];
	ap_uint<8> in2[m][p];

	int out_hw[n][p];
	int out_sw[n][p];

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < p ; j++){
			out_hw[i][j] = 0;
			out_sw[i][j] = 0;
		}
	}

	//printf("A:\n");
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			in1[i][j] = rand() % 255;
			//std::cout << in1[i][j] << " ";
		}
		//printf("\n");
	}

	//printf("B:\n");
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < p ; j++){
			in2[i][j] = rand() % 255;
			//std::cout << in2[i][j] << " ";
		}
		//printf("\n");
	}


	sw_multiplication(in1,in2,out_sw);

	MATRIX_MUL(in1,in2,out_hw);

	//printf("Results:\n");
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < p ; j++){
			//std::cout << out_sw[i][j] << " ";
			if(out_hw[i][j] != out_sw[i][j]){
				check = false;
			}
		}
		//printf("\n");
	}



	if(check)
		printf("Test Passed\n");
	else
		printf("Test Failed\n");


}
