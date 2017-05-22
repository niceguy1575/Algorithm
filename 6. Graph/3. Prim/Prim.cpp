#include <stdio.h>
#include <stdlib.h>
#define INF 99999999


void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int isIn(int v, int* Q, int n) {
	for(int i = 0 ; i < n ; i ++) {
		if(Q[i] == v+1) {
			return 1;
		}
	}
	return 0;
}

int* exclude(int* arr, int n, int index) {
	
	int i;
	
	int *NArr = (int*) malloc ( sizeof(int) * (n) );
	
	for(i = 0; i < n ; i++) {
		NArr[i] = arr[i];
	}
	
	arr = (int *)realloc(arr, (n-1)*sizeof(int));
	
	for(i = 0 ; i < n - 1; i ++) {
		if(i >= index) {
			arr[i] = arr[i+1];
		}
	}
	
	return arr;
}

int sum(int* arr, int n) {
	int sum = 0;
	for(int i = 0 ; i < n ; i++) {
		sum = sum + arr[i];
	}
	return sum;
}

int extract_min(int* d, int* visited, int n) {
	
	int min = INF;
	int min_index;
	
	 for (int i = 0; i < n; i++) {
	 	if(visited[i] == 0 && d[i] < min) {
	 		min = d[i];
	 		min_index = i;	
		 }
	 }
	
	return min_index;
//	
//	int i, min, index, u;
//		
//	index = 0;
//	min = d[index];
//	
//	for( i = 1 ; i < n ; i ++) {
//		if( min > d[i] ) {
//			min = d[i];
//			index = i;
//		}
// 	}
//	printf("index = %d\n", index);
//	u = Q[index];
////	printf("u = %d\n", u);
//
////	printIntArr(d, n);
//	
//	Q = exclude(Q, n, index);
//
//	return u;
}

void prim(int** matrix, int n, int m){
	
	int i, u, v, size;
	int *d = (int*) malloc ( sizeof(int) * n );
	int *tree = (int*) malloc ( sizeof(int) * n );
	int *Q = (int*) malloc ( sizeof(int) * n );
	int *visited = (int*) malloc ( sizeof(int) * n );
	
	for(i = 0 ; i < n ; i++) {
		Q[i] = i + 1;
		d[i] = INF;
		tree[i] = 0;
		visited[i] = 0;
	}
		
	d[0] = 0; // 1번부터 시작  ( r = 1 )
	
	for(i = 0 ; i < n ; i ++){
			u = extract_min(d, visited, n);
			size = size -1;
			visited[u] = 1;
					
			for(v = 0 ; v < n; v ++) {
				if( matrix[u][v] && visited[v] == 0 && matrix[u][v] < d[v]) {
					d[v] = matrix[u][v];
					tree[v] = u;
				}
			}
			printf("%d ", u+1);
		}
		printf("%d",sum(d,n) );
	}	
}

int main() {
	
	int n, m, i, j, x, y, w;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	int **matrix = (int**) malloc ( sizeof(int*) * n );
	for(i = 0 ; i < n; i++){
	    matrix[i] = (int*) malloc ( sizeof(int) * n );
	}
	
	// matrix 초기화
	
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j ++) {
			matrix[i][j] = 0;
		}
	}
		
	for(i = 0 ; i < m ; i ++) {
		scanf("%d %d %d", &x, &y, &w);
		matrix[x-1][y-1] = w;
		matrix[y-1][x-1] = w;
	}
		
	prim(matrix, n, m);
	
	return 0;
}
