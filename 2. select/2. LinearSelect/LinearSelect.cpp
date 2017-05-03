#include <stdio.h>
#include <stdlib.h>
 
 
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
    int x = arr[r-1];
    int i = p-1;
    for( int j = p ; j < r ; j++){
        if(arr[j-1] <= x) {
            i++;
            change(arr, i-1, j-1);
        }
    }
    change(arr, i, r-1);
     
    return i+1;
}
 
int partitionByMedian(int* arr, int p, int r, int M){
     
   int size = r - p + 1;
   int i = 0;
   while(i < size){
        if(arr[p + i - 1] == M ) break;
        i++;
   }
   change(arr, r-1, p + i - 1);
  
   return partition(arr, p, r);
}
 
int select(int* arr, int p, int r, int i){
     
   if (p == r) {
        return arr[p-1];
   }
    
   int q = partition(arr, p, r);
    
   int k = q - p + 1;
    
   if(i < k) {
        return select(arr, p, q - 1, i);
   }
   else if(i > k){
        return select(arr, q + 1, r, i - k);
   }
   else return arr[q-1];
}
 
int ceil(int a, int b){
    if(a % b== 0) return a/b;
    else return a/b + 1;
}
 
int linearSelect(int* arr, int p , int r, int index){
 
    int size = r - p + 1;
    if( size <= 5 ) {
        return select(arr, p, r, index);
    }
    int groupSize = ceil(size, 5);
    int ** groupPtr = (int**) malloc(sizeof(int) * groupSize);
    int * medArr = (int*)malloc(sizeof(int) * groupSize);
    
	int i, j, length, param, median;
    int* lastPtr;
     
    int s = 0;
    int cnt = 0;
    for(i = p ; i <= r; i+=5) {
        groupPtr[s++] = &arr[i];
    }
 
    for(j = 0 ; j < groupSize; j++) {
        if(j==0){
            lastPtr = groupPtr[groupSize-1]; 
        }
        length = size - j * 5;
 
        if( j == groupSize-1 && length < 5) {
            param = ((length >= 3) ? 2 : 1);
            medArr[j] = select(lastPtr, 0, length - 1, param);
        }
        else {
            medArr[j] = select(groupPtr[j], 0, 4, 3);   
        }
    }
         
    median = linearSelect(medArr, 1, groupSize , ceil(groupSize,2));
    printf("%d \n", median);
     
    int q = partitionByMedian(arr, p, r, median);
    int k = q - p + 1;
     
    if(k==index) return arr[q-1];
    else if(k>index) return linearSelect(arr, p , q - 1 , index);
    else return linearSelect(arr, q + 1 , r, index - k);
}
 
// main
int main() {
    int size, index;
    scanf("%d %d", &size, &index);
     
    int *inputArr = (int*)malloc(sizeof (int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d",&inputArr[i]);
    }
    int result = linearSelect(inputArr, 1, size, index);
    //printf("result = %d", result);
    return 0;
}
