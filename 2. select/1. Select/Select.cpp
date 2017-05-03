#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

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

int partition(int* arr, int p, int r) {
	int x = arr[r];
	int i = p-1;
	for( int j = p ; j < r ; j++){
		if(arr[j] <= x) {
			change(arr, ++i, j);
			cnt++;
		}
	}
	change(arr, i+1, r);
	cnt++;
	
	return i+1;
}

int select(int* arr, int p, int r, int i){

   if (p == r) {
		return arr[p];
   }
   
   int q = partition(arr, p, r);
   
   int k = q - p + 1;
   
   if(i < k) {
   		return select(arr, p, q - 1, i);
   }
   else if(i > k){
    	return select(arr, q + 1, r, i - k);
   }
   else return arr[q];
}

// main
int main() {
	
	int size, index;
    scanf("%d", &size);
    scanf("%d", &index);
    
    int *inputArr = (int*)malloc(sizeof (int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d",&inputArr[i]);
	}
	
	int compare = select(inputArr, 0, size-1, index);
	printf("%d\n",cnt);
	//printf("%d\n",compare);
	return 0;
}
