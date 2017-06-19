#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* preProcessing(char* P, int m) {
	int j = 1;
	int k = 0;

	int *pi = (int*)malloc(sizeof (int) * (m+2) );
	pi[1] = 0;
	
	while(j <= m) {
		if(k ==0 || P[j] == P[k] ) {
			j++;
			k++;
			pi[j] = k;
		}
		else {
			k = pi[k];
		}
	}
	return pi;
}

void KMP(char* A, char* P ) {
	int count = 0;

	int n = strlen(A+1);
 	int m = strlen(P+1);
    int i = 1; // 본문 문자열 포인터
    int j = 1; // 패턴 문자열 포인터
   	int *pi = (int*)malloc(sizeof (int) * (m+2) );
   	
	pi = preProcessing(P, m);

 	int match = 0;
 	
    while(i <= n) {
        count++;
        if(j==0 || A[i]==P[j]) {
        	i++;
        	j++;
		}
        else{
        	j = pi[j];
		}
 
        if( j == m+1 ) {
        	printf("%d\n", count);
        	match = 1;
        	j = pi[j];
        }
    }
    
    if(match != 1) {
    	printf("fail");
	}
}

int main() {
		
	char A[1000], P[15];
	
	scanf("%s %s", A+1, P+1);
	
	KMP(A, P);

	return 0;
}
