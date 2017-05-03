#include <stdio.h>
#include <stdlib.h>

void change(int* arr, int index1, int index2) {
	
 	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
	return;
}

void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i]);
	}
}

int* theLargest(int* arr, int last) {
	int largest = 0;
	int cnt = 0;
	for(int i = 1; i <= last; i++) {
		if( arr[i] > arr[largest]) {
			largest = i;
			cnt++;
		}
	}
    int *result = (int*)malloc(sizeof (int) * 2);
	result[0] = largest;
	result[1] = cnt;
	
	return result;
}

int selectionSort(int* arr, int n) {
	
	int* k;
	int static sum = 0;
	
	if(n == 1) {
		return sum;
	}
	// Àç±Í°¡ È£ÃâµÇ´Â È½¼ö : n-1
    
	k = theLargest(arr, n - 1);

	change(arr, k[0], n - 1);
	sum += k[1];
	return selectionSort(arr, n-1);
}

// main
int main() {
	int n;
	scanf("%d", &n);
	
    int *inputArr = (int*)malloc(sizeof (int) * n);
    
   for (int i = 0; i < n; i++) {
        inputArr[i] = (rand() % n)+1 ;
    }
    printIntArr(inputArr,n);
	int compareCnt = selectionSort(inputArr, n);
	printf("%d\n",compareCnt);
    printIntArr(inputArr,n);

	return 0;
}
