#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int pattern = 0;

int mod(long long x, long long y){
    return (((x%y)+y)%y);
}

int isMatching(char* A, char* P, int m, int i) {
	
	// pattern 만큼 반복 
	for(int j = 0 ; j < m; j++ ) {
		if (A[i+j] != P[j]){
        	return 0;	
		}
	}
	return 1;
}

void RabinKarp(char* A, char* P, int d, int q){
	int n = strlen(A);
	int m = strlen(P);
   int p = 0;
   int *b = (int*)malloc(sizeof (int) * (n-m+1) );
   b[0] = 0;
   int i;
   
   for(i = 0 ; i < m ; i++) {
		p = mod( (d*p + (P[i]-97) ), q );
		b[0] = mod( (d*b[0] + (A[i]-97) ), q );
   }
   
   int h = mod( pow((double)d, m-1) , q) ;
   
   for(i = 0 ; i < n - m + 1 ; i ++) {
      	if(i != 0) {
	    	printf("%d ", b[i-1]);
      		b[i] = mod( ( d*(b[i-1] - h * (A[i-1]-97) ) + (A[i+m-1] - 97) ) , q );
		} else{
			printf("%d ", b[i]);
		}
      	if(p == b[i]) {
		    if(isMatching(A, P, m, i)){
				pattern++;
			}
   		}   	
   }
   printf("%d", pattern);
}

int main() {
	
	int res, m, n; 
	
	char A[1000], P[15];
	
	scanf("%s %s", A, P);
	
	RabinKarp(A, P, 26, 113);

	return 0;
}
