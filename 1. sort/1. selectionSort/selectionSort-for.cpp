#include <stdio.h>
#include <stdlib.h>
 
void change(int* arr, int index1, int index2) {

    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}
 
int* theLargest(int* arr, int last) {
    int largest = 0;
    int cnt = 0;
    for(int i = 1; i < last; i++) {
        if( arr[i] > arr[largest]) {
            largest = i;
            cnt++;
        }
    }
    int* result = (int*)malloc(sizeof (int) * 2);
	result[0] = largest;
	result[1] = cnt;

    return result;
}
 
int selectionSort(int* arr, int n) {
    int cnt = 0;
    int *k;

    for(int last = n; last > 1; last--) { 
        k = theLargest(arr, last);
        change(arr, *k, last-1);        
        cnt += *(k+1);
    }
    return cnt;
}
 
int main() {
    int n;
    scanf("%d",&n);
    
    int* inputArr = (int*)malloc(sizeof (int) * n);
    
	for (int i = 0; i < n; i++) {
        scanf("%d",&inputArr[i]);
    }

    int compareCnt = selectionSort(inputArr, n); 
    printf("%d",compareCnt);

	return 0;
}
