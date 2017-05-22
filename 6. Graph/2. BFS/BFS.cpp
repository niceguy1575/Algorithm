#include <stdio.h>
#include <stdlib.h>
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

void BFS(int** matrix, int n, int s) {
	
	int u, i;
	s = s-1;
	int *visited = (int*) malloc ( sizeof(int) * n );
	
	for(i = 0 ; i < n ; i ++) {
		visited[i] = 0;
	}
	visited[s] = 1;
	printf("%d ", s+1);
	QueueType* Queue = createQueue();
	enQueue(Queue, s);
	
	while( !isEmpty(Queue) ) {
		u = deQueue(Queue);
		
		for(i = 0 ; i < n ; i ++) {
			// u�� ��������Ʈ 
			if( matrix[u][i] &&  visited[ i ] == 0 ) {
				visited[i] = 1;
//				printIntArr(visited, n);
//				printf("\n");
				printf("%d ", i + 1);
				enQueue(Queue, i);
			}
		}
	}
	
}

int main() {
	
	int n, m, i, j, x, y, s;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	int **matrix = (int**) malloc ( sizeof(int*) * n );
	for(i = 0 ; i < n; i++){
	    matrix[i] = (int*) malloc ( sizeof(int) * n );
	}
	
	// matrix �ʱ�ȭ
	
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j ++) {
			matrix[i][j] = 0;
		}
	}

	for(i = 0 ; i < m ; i ++) {
		scanf("%d %d", &x, &y);
		matrix[x-1][y-1] = 1;
		matrix[y-1][x-1] = 1;
	}
	
	scanf("%d", &s);
	
	BFS(matrix, n, s);
	
	return 0;
}
