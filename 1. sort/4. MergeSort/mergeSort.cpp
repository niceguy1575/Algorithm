#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int merge(int* arr, int p, int q, int r, int size){
	int i = p;
	int j = q+1;
	int t = 0;
	int cnt = 0;
    int* temp = (int*)malloc(sizeof (int) * size);
    
    printf("r=%d\t",r);
	// 각각 i와 j로 놓고 비교
	while(i <= q && j <= r) {
		printf("\n1=%d, 2=%d\n",arr[i],arr[j]);
		if( arr[i] < arr[j] ) {
			temp[t++] = arr[i++];
		}
		else {
			temp[t++] = arr[j++];
		}
		cnt++;
	}

	// 왼쪽만 남았을때
	while(i<=q)  {
		temp[t++] = arr[i++];
	}	
	// 오른쪽만 남았을때
	while(j<=r)  {
		temp[t++] = arr[j++];
	}

	i = p;
	t = 0;
	while(i<=r) {
		arr[i++] = temp[t++];
	}
	free(temp);
	return cnt;
}

int mergeSort(int* arr, int p, int r, int n) {
	int static result = 0;
	int q;
	if(p<r) {
		q = (p+r)/2;
		mergeSort(arr, p, q,n);
		mergeSort(arr, q+1, r,n);
		result += merge(arr, p, q, r,n);
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
	
	int compareCnt = mergeSort(inputArr, 0, size-1,size);
	printf("%d\n",compareCnt);
	
	return 0;
}
