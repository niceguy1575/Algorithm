#include <stdio.h>
#include <stdlib.h>

typedef struct setNode{
	struct setNode* head_link;
 	int data;
 	struct setNode* tail_link;
} setNode;

typedef struct{   //리스트의 헤드 노드의 구조 정의
	setNode* head;
} set_h;


void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i] ); 
	}
}

void printSetArr(set_h** arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", *(arr+i) ); 
	}
}

set_h* createSet_h(void){  //공백 연결리스트 생성 연산
	set_h* S;
	S = (set_h*)malloc(sizeof(set_h)); //헤드 노드 할당
	S -> head = NULL; //공백 리스트이므로 NULL 설정
	return S;
}

set_h* make_set(int x){
	
	set_h* S;
    S = createSet_h(); 
    
 	setNode* newNode;
 	newNode = (setNode*)malloc(sizeof(setNode));
 	newNode->data = x;
	newNode->head_link = NULL;
	newNode->tail_link = NULL;
 	S -> head = newNode;
 	
 	return S;
}

int find_set_toHead(setNode* xt, int x) {
	
    while (xt->head_link != NULL) {
    	xt = xt->head_link;
    	if (xt->data == x) return 1;
    }
	return 0;

}

setNode* Union(set_h* X, set_h* Y) {
	
   setNode* xt = X->head;
   setNode* yt = Y->head;
   setNode* nodeTrack = Y->head;
   int len1, len2 = 0;
   
   while (xt->tail_link != NULL) {
   	 xt = xt->tail_link;
   	 len1++;
   }
   while (nodeTrack->head_link != NULL) {
   	 nodeTrack = nodeTrack->head_link;
   	 len2++;
   }
   if( find_set_toHead(xt, X->head->data) * find_set_toHead(xt, Y->head->data) ) {
   	
	    if(len1 > len2) {
       		return xt;
	   	}
	   else {
	   		return nodeTrack;
	   }
   }
   xt->tail_link = nodeTrack;
   nodeTrack->head_link = xt;   	
   
   // last pointer
   while (yt->tail_link != NULL) {
   		yt = yt->tail_link;
   }
   
   return yt;
}

int UnionLen(setNode* unionPtr, int size) {
	
	int cnt = 1;
    setNode* p = unionPtr;
    while (p->head_link != NULL) {
	   	p = p -> head_link; 
	   	cnt++;
    }
   return cnt;
}

int checkUnique(int* arr, int size, int number) {
	for(int i = 0 ; i < size+1 ; i++){
		if(arr[i] == number) {
			return 0;
		}
	}
	return 1;
}

int max(int* arr, int size){
	int max = arr[0];
	for(int i = 1 ; i < size ; i++) {
		if(max <= arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int main() {
	
	int people, pair, x, y, i, j;
    scanf("%d %d", &people, &pair);
	
	int* peopleArr = (int*)malloc(sizeof(int) * people);
	
	for(i = 0 ; i < people ; i++) {
		peopleArr[i] = -1;
	}
	
	int* pairArr = (int*)malloc(sizeof(int) * 2 * pair);
	set_h** ptrArr = (set_h**)malloc(sizeof(set_h) * 2 * pair);
	
	j = 0;
	for(i = 0 ; i < 2 * pair ; i++) {
		scanf("%d", &x);
		
		if( checkUnique(peopleArr, j, x) ) {
			*(peopleArr+j) = x;
			ptrArr[i] = make_set(x);
			j++;
			if( j > people ) {
				return 0;
			}
		} else {
			for(int k = 0 ; k < i; k++) {
				if(pairArr[k] == x) {
					ptrArr[i] = ptrArr[k];
				}
			}
		}
		
		pairArr[i] = x;
	}
	setNode** unionPtr = (setNode**)malloc(sizeof(setNode) * pair);
	int* unionArr = (int*)malloc(sizeof(int) * pair);
	j = 0;
	for(i = 0; i < 2 * pair ; i+=2) {
		unionPtr[j] = Union(ptrArr[i], ptrArr[i+1]);
		unionArr[j] = UnionLen(unionPtr[j], pair);
		j++;
	}
	printf("%d", max(unionArr, pair));
	
	return 0;
}
