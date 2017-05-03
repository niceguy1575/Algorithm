#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Q_SIZE 5000

typedef struct{
 	int queue[Q_SIZE];   // 1���� �迭 ť ����
 	int front, rear;
} QueueType;

QueueType* createQueue()      //���� ť�� �����ϴ� ����
{
 	QueueType *Q;
 	Q = (QueueType *)malloc(sizeof(QueueType) * Q_SIZE);
 	Q->front=-1;               //front �ʱ갪 ����
 	Q->rear=-1;                //rear �ʱ갪 ����
 	return Q;
}

int isEmpty(QueueType *Q)      //ť�� �������� Ȯ���ϴ� ����
{
 	if (Q->front == Q->rear) { // empty
 	   return 1;
   	}
 	else return 0;
}

int isFull(QueueType *Q)       //ť�� ��ȭ�������� Ȯ���ϴ� ����
{
 	if (Q->rear == Q_SIZE-1) {
 	   return 1;
 	}
 	else return 0;
}

void enQueue(QueueType *Q, int item)   //ť�� rear�� ���Ҹ� �����ϴ� ����
{
   	if(isFull(Q)) exit(1);
 	else {
 	   Q->rear++;
 	   Q->queue[Q->rear] = item;
 	}
}

int deQueue(QueueType *Q)    //ť�� front���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
{
 	if (isEmpty(Q)) exit(0);
 	else {
 	   Q->front++;
 	   return Q->queue[Q->front];
 	}
}

void printQ(QueueType *Q)    //ť�� ������ ����ϴ� ����
{
  	int i;
 	for(i=Q->front+1; i<=Q->rear; i++)
 	   printf("%d ",Q->queue[i]);
}

void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i]);
	}
}

int getDigit(int num, int id) {
	
	int result = 0;
	int temp = num;
	for(int i = 0 ; i < id ; i++) {
		result = temp % 10 ;
		temp = temp / 10;
	}
	return result;
}

int* RadixSort(int* arr, int size, int k) {

	int order = 10;
	QueueType** QArr = (QueueType**)malloc(sizeof(QueueType) * order);
	
	for(int i = 0 ; i < order ; i++){
		QArr[i] = createQueue();
	}
	
	int p, d, i , j, s;
	
	for(i = 1; i <= k; i++) {
		for(j = 0 ; j < size ; j++) {
			d = getDigit(arr[j], i);
			enQueue( QArr[d], arr[j] );
		}
		p = 0;
		for(s = 0 ; s < order; s++) {
			while( !isEmpty(QArr[s]) ) {
				arr[p++] = deQueue(QArr[s]);
			}
		}
	}
	printIntArr(arr, size);
	return arr;
}

// main
int main() {
	
	int size, t;
    scanf("%d", &size);
    scanf("%d", &t);
     
    int *inputArr = (int*)malloc(sizeof (int) * size);
    
    for (int i = 0; i < size; i++) {
        scanf("%d",&inputArr[i]);
	}
	
	int* debugArr = RadixSort(inputArr, size, t);

	return 0;
}
