#include <stdio.h>
#include <stdlib.h>

// 배열에 두 인덱스를 받으면 서로의 위치를 바꿔주는 함수 
void change(int *index1, int *index2) {
	
    int temp;
    temp=*index1;
    *index1=*index2;
    *index2=temp;
}

void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i]);
	}
}

int bubbleSort(int* arr, int n) {
	
	int sorted;
	int cnt = 0;
	for(int last = n; last > 0; last--) {
		sorted = 1;
		for(int i  = 0 ; i < last-1; i++) {
			if(arr[i] > arr[i+1]) {
				change(&arr[i], &arr[i+1]);
				sorted = 0;
				cnt++;
			}
		}
	}
	if(sorted == 1) {
		return cnt;
	}
}


// main
int main() {
	
	int n;
    scanf("%d", &n);
     
    int *inputArr = (int*)malloc(sizeof (int) * n);
    for (int i = 0; i < n; i++) {
		inputArr[i] = (rand() % n);
	}
	
	//printIntArr(inputArr,n);
	int compareCnt = bubbleSort(inputArr, n);
	printf("%d\n",compareCnt);
	//printIntArr(inputArr,n);
	
	return 0;
}