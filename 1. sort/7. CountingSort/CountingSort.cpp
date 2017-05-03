#include <stdio.h>
#include <stdlib.h>

void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i]);
	}
}

void copyArr(int* A, int* B, int size){
	for(int i = 0 ; i < size ; i++) {
		B[i] = A[i];
	}
}

int findMax(int* arr, int size) {
	
	int largest = 0;
	for(int i = 1 ; i < size ; i ++) {
		if(arr[i] > arr[largest]) {
			largest = i;
		}
	}
    return arr[largest];
}

int findMin(int* arr, int size) {
	
	int smallest = 0;
	for(int i = 1 ; i < size ; i ++) {
		if(arr[i] < arr[smallest]) {
			smallest = i;
		}
	}
    return arr[smallest];
}

int** countingSort(int* arrA, int* arrB, int size) {
	
	int max = findMax(arrA, size);
	int min = findMin(arrA, size);
	int k = max - min + 1;
	
	// C 배열 선언 및 초기화 
	int* arrC = (int*) malloc( sizeof(int) * k);
	int* arrD = (int*) malloc( sizeof(int) * k);

	for(int i = 0 ; i < k ; i ++) {
		arrC[i] = 0;
	}
	
	// A배열 각 원소의 카운팅 
	for(int j = 0 ; j < size ; j ++) {
		arrC[arrA[j] - min]++;
	}
	
	// 배열 C의 누적합 
	for(int i = 1; i < k ; i ++){
		arrC[i] = arrC[i] + arrC[i-1];
	}
	copyArr(arrC, arrD, k); // D에 복사 

	// 배열 B에 기록
	for(int j = size -1 ; j > -1 ; j--)  {
    	arrB[arrC[arrA[j]-min] - 1] = arrA[j];
    	arrC[arrA[j] - min]--;
	}
	
    int **result = (int**)malloc(sizeof (int) * 2);
	result[0] = arrD;
	result[1] = &k;
	return result;
}

// main
int main() {
	
	int size;
    scanf("%d", &size);
     
    int *inputArr = (int*)malloc(sizeof (int) * size);
    int *resultArr = (int*)malloc(sizeof (int) * size);
    
    for (int i = 0; i < size; i++) {
        scanf("%d",&inputArr[i]); 
	}

	int** cumulativeArr = countingSort(inputArr, resultArr, size);
	printIntArr(cumulativeArr[0],*cumulativeArr[1]);
	
	return 0;
}
