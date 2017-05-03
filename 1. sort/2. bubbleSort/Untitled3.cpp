#include <stdio.h>
#include <stdlib.h>
#define Max 10000
 
int main(){
    int array[Max];
    int number, i, j, temp, count;
    count=0;
     
    scanf("%d",&number);
    for(i=0; i<number; i++){
        scanf("%d",&array[i]);      
    }
     
    for(i=number-1; i>0; i--){
        for(j=0; j<i; j++){
            if(array[j]>array[j+1]){
                temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
                count++;
            }
        }
    }
     
    printf("%d\n",count);
/* 사용할 수 없는 시스템 콜(system)을 호출했습니다. */
    return 0;
}
