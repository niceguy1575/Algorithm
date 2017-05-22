#include <stdio.h>
#include <stdlib.h>

void printCharArr(char* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%c ", arr[i] ); 
	}
}

int charArrLen(char* arr){
	int length = 0;
	for(int i = 0; arr[i]!=NULL; i++) {
		length++;
	}
	return length;
}

int max(int A, int B){
	if( A > B) {
		return A;
	}
	else {
		return B;
	}
}


int LCS(char* sequence1, char* sequence2, int m, int n) {
	
	int i, j;
	m = m+1;
	n = n+1;
	
	int **C = (int**) malloc ( sizeof(int*) * m );
	
	for(i = 0 ; i < m ; i ++) {
   		C[i] = (int*) malloc ( sizeof(int) * n );
	}
	
	for(i = 0; i < m ; i++) {
		C[i][0] = 0;
	}
	
	for(j = 0; j < n ; j++) {
		C[0][j] = 0;
	}
	
	for(i = 1; i < m ; i++) {
		for(j = 1; j < n ; j++) {
			if(sequence1[i-1] == sequence2[j-1]) {
				C[i][j] = C[i-1][j-1] + 1;
			}
			else {
				C[i][j] = max(C[i-1][j], C[i][j-1]);
			}
		}
	}
	
	return C[m-1][n-1];
}

int main() {
	
	int res, m, n; 
	
	char sequence1[500], sequence2[500];
	
	scanf("%s %s", sequence1, sequence2);
	
	m = charArrLen(sequence1);
	n = charArrLen(sequence2);

	res = LCS(sequence1, sequence2, m, n);
			
	printf("%d", res);
	return 0;
}
