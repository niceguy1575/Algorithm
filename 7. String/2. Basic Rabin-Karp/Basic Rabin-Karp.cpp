#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int pattern = 0;

void basicRabinKarp(char* A, char* P, int d){
	
	int n = strlen(A);
	int m = strlen(P);
    int *a = (int*)malloc(sizeof (int) * (n-m+1) );
	
	int i;
   	int p = 0;
	a[0] = 0;
	
	// 97 ascii code : a
    for(i = 0 ; i < m ; i++) {
    	p = d * p + (P[i] - 97);
    	a[0] = d*a[0] + (A[i] - 97);
	}
      
    for(i = 0 ; i < n-m+1; i++) {
      	if(i != 0) {
	    	printf("%d ", a[i-1]);
      		a[i] = d*(a[i-1] - (int)pow((double)d, m-1) * (A[i-1]-97) )+ (A[i+m-1] - 97);
		} else{
			printf("%d ", a[i]);
		}
      	if(p == a[i]) {
      	 	pattern++;
		}
	}
	printf("%d", pattern);
}

int main() {
	
	int res, m, n; 
	
	char A[1000], P[15];
	
	scanf("%s %s", A, P);
	
	basicRabinKarp(A, P, 10);

	return 0;
}
