#include <stdio.h>
#include <stdlib.h>

// 배열에 두 인덱스를 받으면 서로의 위치를 바꿔주는 함수 
void change(int* arr, int index1, int index2) {
	
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}

int bubbleSort(int* arr, int n) {
	
	int sorted;
	int count = 0;
	for(int last = n; last > 1; last--) {
		sorted = 1;
		for(int i = 0; i < last - 1; i++) {
			if(arr[i] > arr[i+1]) {
				change(arr, i, i+1);
				sorted = 0;
				count++;
				//printf("%d\n",count);
			}
		}
	}
	return count;
}


// main
int main() {
	
	int n;
    scanf("%d", &n);
     
    int *inputArr = (int*)malloc(sizeof (int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&inputArr[i]);
	}
	
	int compareCnt = bubbleSort(inputArr, n);
	printf("%d",compareCnt);
	
	return 0;
}
