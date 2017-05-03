#include <stdio.h>
#include <stdlib.h>

void change(int* arr, int index1, int index2) {
	
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}

int* partition(int* arr, int p, int r) {
	int x = arr[r]; // pivot element - last
	int i = p-1;
	int cnt = 0;
	for( int j = p ; j < r ; j++){
		if(arr[j] <= x) {
			change(arr, ++i, j);
			cnt++;
		}
	}
	change(arr, i+1, r);
	
	int* result = (int*)malloc(sizeof (int) * 2);
	result[0] = i+1;
	result[1] = cnt+1;
	return result;
}

int quickSort(int* arr, int p, int r) {
	int static result = 0;
	int *k;
	int q;
	if(p < r) {
		k = partition(arr, p, r);
		q = k[0];
		result += k[1];
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
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
	
	int compareCnt = quickSort(inputArr, 0, size-1);
	printf("%d\n",compareCnt);
	return 0;
}
