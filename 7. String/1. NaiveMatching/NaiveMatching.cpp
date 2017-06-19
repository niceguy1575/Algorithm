#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int cnt = 0;
int pattern = 0;

int charArrLen(char* arr){
	int length = 0;
	for(int i = 0; arr[i]!=NULL; i++) {
		length++;
	}
	return length;
}

int isMatching(char* A, char* P, int m, int i) {
	
	// pattern 만큼 반복 
	for(int j = 0 ; j < m; j++ ) {
		cnt++;
		if (A[i+j] != P[j]){
        	return 0;	
		}
	}
	return 1;
}

void naiveMatching(char* A, char* P, int n, int m) {
   for(int i = 0 ; i < n-m+1; i++) {
        if(isMatching(A, P, m, i)){
			pattern++;
		}
   }
    printf("%d %d ", cnt, pattern);
}

int main() {
	
	int res, m, n; 
	
	char A[MAX], P[MAX];
	
	scanf("%s %s", A, P);
	
	n = charArrLen(A);
	m = charArrLen(P);

	naiveMatching(A, P, n, m);

	return 0;
}
