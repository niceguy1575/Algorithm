#include <stdio.h>
#include <stdlib.h>

void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i] ); 
	}
}

int isPrime(int number){
    if(number < 2) return 0;
    if(number == 2) return 1;
    if(number % 2 == 0) return 0;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return 0;
    }
    return 1;
}

int findPrime(int n){ 
	int M = n * 2;
	
	while( !isPrime(M) ){
		M = M + 1;
	}
	
	return M;
}

int hashInsert(int* hashTbl, int x, int M){
	int crash = 0;
	int mod = x % M;
	int i=0;
	do {
		if(hashTbl[mod+i]==NULL) {
			hashTbl[mod+i] = x;
			return crash;
		}
		else {
			i++;
			crash++;
		}
	} while(i!=M);
	return crash;
}

int openAddress_HASH(int* arr, int num) {
	int cnt = 0;
	int size;
	int M = findPrime(num);
	int *hashTbl = (int*)malloc(sizeof (int) * M);

	for(int i=0;i<M;i++){
		hashTbl[i]=NULL;
	}	
	for(int i=0;i<num;i++){
		cnt += hashInsert(hashTbl, arr[i], M);
	}
	return cnt;
}
/*
int openAddress_HASH(int* arr, int n) {
	
	int cnt, i = 0;
	int M = findPrime(n);
	int *hashTbl = (int*)malloc(sizeof (int) * M);
	int index;
	
	for(i = 0 ; i < M; i ++) {
		hashTbl[i] = NULL;
	}
	
	for(i = 0 ; i < n ; i++) {
		index = arr[i] % M;
		if(hashTbl[index] == NULL) {
			hashTbl[index] = arr[i];
		}
		else {
//			printf("-----------------%dth\n", i);
//			printf("arrValue = %d\n", arr[i]);
//			printf("hashTblValue = %d\n", hashTbl[index]);
//			printf("index = %d\n",index);
//			printf("index = %d\n", arr[i] % M);
			int j = 0;
			while(j != M) {
				if(hashTbl[index+j] == NULL) {
					hashTbl[index+j] = arr[i];
					break;
				}
				else {
					cnt++;
					j++;
				}
			}
		}
	}
//	printIntArr(hashTbl, M);
//	printf("\n");
	return cnt;
}
*/
int main() {
	
	int n;
    scanf("%d", &n);
     
    int *inputArr = (int*)malloc(sizeof (int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&inputArr[i]);
    }
    
	int result = openAddress_HASH(inputArr, n);
	printf("%d", result);
	
	return 0;
}
