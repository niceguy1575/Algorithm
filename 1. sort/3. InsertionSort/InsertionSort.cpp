#include <stdio.h>
#include <stdlib.h>

int insertionSort(int* arr, int n) {
	
	int cnt = 0;
	int loc, newItem;
	for(int i = 1; i < n; i++) {
		loc = i-1;
		newItem = arr[i];
		// 정렬이 되어있는 상태이다.
		while(loc >= 0 && newItem < arr[loc]){ // 제자리를 찾아가는 과정
			//1.오른쪽으로 이동하는 횟수 
			arr[loc+1] = arr[loc];
			loc--;
			cnt++;
		}
		//2. 적당한 위치에 삽입 
		arr[loc+1] = newItem;
		cnt++;
	}
	return cnt;
}

// main
int main() {
	
	int n;
    scanf("%d", &n);
     
    int *inputArr = (int*)malloc(sizeof (int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&inputArr[i]);
	}
	
	int moveCnt = insertionSort(inputArr, n);
	printf("%d\n",moveCnt);
	
	return 0;
}
