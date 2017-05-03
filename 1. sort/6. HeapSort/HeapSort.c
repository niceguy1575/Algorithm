#include <stdio.h>
#include <stdlib.h>

void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i]);
	}
}

void change(int* arr, int index1, int index2) {
	
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}

int heapify(int* arr, int k, int size) {
	int left = 2*k;
	int right = 2*k+1;
	int bigger;
	int cnt = 0;
	
	if(right <= size) {
		if( arr[left] > arr[right] ) {
			bigger = left;
		}
		else {
			bigger = right;
		}
	}
	else if(left <= size) {
		bigger = left;
	}
	else {
		return cnt;	
	}
	
	if( arr[bigger] > arr[k] ) {
		change(arr, k, bigger);
		heapify(arr, bigger, size);
	}
}

int buildMaxHeap(int* arr, int size) {
	int static result = 0;
	
	for(int i = size/2; i > 0; i--){
		result += heapify(arr, i, size);
	}
	
	return result;
}

// main
int main() {
	
	int size;
    scanf("%d", &size);
     
    int *inputArr = (int*)malloc(sizeof (int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d",&inputArr[i]); 
	}
	
	int compareCnt = buildMaxHeap(inputArr, size);
	printf("%d\n",compareCnt);
	printIntArr(inputArr,size);
	return 0;
}