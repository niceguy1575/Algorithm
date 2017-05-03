#include <stdio.h>
#include <stdlib.h>

void change(int* arr, int index1, int index2) {
	
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}

int heapify(int* arr, int k, int size, int sort) {

	int left = 2*k - 1;
	int right = 2*k + 1 - 1;
	int bigger;
	int cnt = 0;
	int static sortCnt = 0;
	
	if(right <= size-1) {
		if( arr[left] > arr[right] ) {
			bigger = left;
		}
		else {
			bigger = right;
		}
	}
	else if(left <= size-1) {
		bigger = left;
	}
	else {
		if (sort == 0) {
			return cnt;
		}
		else{
			return sortCnt;
		}
	}
	
	if( arr[bigger] > arr[k-1] ) {
		change(arr, k-1, bigger);
		if (sort == 0) {
			heapify(arr, bigger + 1, size, 0);	
		}
		else{
			sortCnt++;
			heapify(arr, bigger + 1, size, 1);
		}
	}
}

void buildMaxHeap(int* arr, int size) {
	for(int i = size/2; i > 0; i--){
		heapify(arr, i, size, 0);
	}
}

int heapSort(int* arr, int size) {

	int result = 0;
	buildMaxHeap(arr, size);
	
	for(int i = size - 1; i > 0; i --) {
		change(arr, 0, i);
		result = heapify(arr, 1, i, 1);
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
	
	int compareCnt = heapSort(inputArr, size);
	printf("%d\n",compareCnt);
	return 0;
}
