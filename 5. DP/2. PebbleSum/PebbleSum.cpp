#include <stdio.h>
#include <stdlib.h>

int max2(int A, int B){
	if( A > B) {
		return A;
	}
	else {
		return B;
	}
}

int max3(int A, int B, int C){
	
	if( A> B && A > C ){
		return A;
	}
	else if ( B > A && B > C) {
		return B;
	}
	else if( C > A && C > B) {
		return C;
	}
	else {
		return 0;	
	}
}

int maxArr(int* arr, int size){
	int max = arr[0];
	for(int i = 1 ; i < size ; i++) {
		if(max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int main() {
	
	int m, p, i, j, number;
	
	scanf("%d",  &m);
	
	int **matrix = (int**) malloc ( sizeof(int*) * 3 );
	int **peb = (int**) malloc ( sizeof(int*) * m );
	int **w = (int**) malloc ( sizeof(int*) * m );

	for(i = 0 ; i < 3 ; i ++) {
   		matrix[i] = (int*) malloc ( sizeof(int) * m );
   		for(j = 0; j < m ; j++) {
   			scanf("%d", &number);
   			*(matrix[i] + j) = number;
		}
	}
	
	for(i = 0; i < m; i++) {
		
   		peb[i] = (int*) malloc ( sizeof(int) * 4 );
   		w[i] = (int*) malloc ( sizeof(int) * 4 );
   		
   		for(j = 0 ; j < 4 ; j ++) {
   			
   			if(j < 3) {
   				w[i][j] = matrix[j][i];
			}
			else {
				w[i][j] = matrix[0][i] + matrix[2][i];
			}
	   }
	}
	
	for(p = 0; p < 4; p++) {
		peb[0][p] = w[0][p];
	}
	
	for(i = 1 ; i < m; i++) {
		for(p = 0; p < 4; p++) {
			if(p==0) {
				peb[i][p] = max2(peb[i-1][1], peb[i-1][2]) + w[i][p];
			}
			else if(p==1) {
				peb[i][p] = max3(peb[i-1][0], peb[i-1][2], peb[i-1][3]) + w[i][p];
			}
			else if(p==2) {
				peb[i][p] = max2(peb[i-1][0], peb[i-1][1]) + w[i][p];
			}
			else {
				peb[i][p] = peb[i-1][1] + w[i][p];	
			}
		}
	}
	
	printf("%d", maxArr(peb[m-1], 4) );
	
		
	return 0;
}
