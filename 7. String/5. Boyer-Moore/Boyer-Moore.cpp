#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000
#define JUMPIDX 26

int cnt = 0;
int pattern = 0;

void BoyerMooreHorspool(char *A, char *P){
	
    int jump[JUMPIDX];
    int i, j, k;
    int n = strlen(A);
    int m = strlen(P);
    
    for(i = 0 ; i < JUMPIDX ; i++){
    	
        for(j = m-1 ; j >= 0 ; j--){
            if(i == P[j]-'a'){
                jump[i] = m-j-1;
                break;
            } 
			else {
				jump[i] = m;	
			}
        }
        if(jump[i] == 0) {
        	jump[i] = m;	
		}
    }
    
    i = 0;
    
    while(i < n-m+1){
    	
        j = m-1;
		k = i+m-1;
		
        while(j >= 0 && P[j] == A[k]){
            cnt++;
            j--;
			k--;
        }
        if(j < 0) {
        	pattern++;	
		}
        i = i+jump[A[i+m-1]-'a'];
    }
    printf("%d %d", cnt, pattern);
}

int main() {
		
	char A[MAX], P[MAX];
	
	scanf("%s %s", A, P);
	
	BoyerMooreHorspool(A, P);

	return 0;
}
