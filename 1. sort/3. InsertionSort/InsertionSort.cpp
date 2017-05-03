#include <stdio.h>
#include <stdlib.h>

int insertionSort(int* arr, int n) {
	
	int cnt = 0;
	int loc, newItem;
	for(int i = 1; i < n; i++) {
		loc = i-1;
		newItem = arr[i];
		// ������ �Ǿ��ִ� �����̴�.
		while(loc >= 0 && newItem < arr[loc]){ // ���ڸ��� ã�ư��� ����
			//1.���������� �̵��ϴ� Ƚ�� 
			arr[loc+1] = arr[loc];
			loc--;
			cnt++;
		}
		//2. ������ ��ġ�� ���� 
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
