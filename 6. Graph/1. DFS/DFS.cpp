#include <stdio.h>
#include <stdlib.h>

void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i] ); 
	}
}

int* aDFS(int** matrix, int s, int n, int* visited) {
	
	int i, j;
	visited[s] = 1;
	printf("%d ", s + 1);

	for(j = 0 ; j < n ; j ++) {
		// 인접리스트 
		if( matrix[s][j] == 1 &&  visited[ j ]==0 ) {
				visited = aDFS(matrix, j, n, visited);
			}
		}
	
	return visited;
}

int iter(int* mat, int n) {
	
	for(int i = 0 ; i < n ; i++) {
		if(mat[i] == 1) {
			return 1;
		}
	}
	return 0;
}

void DFS(int** matrix, int n, int s) {
	
	int i, j;
	
//	for(i = 0 ; i < n ; i++) {
//		for(j = 0 ; j < n ; j ++) {
//			printf("%d ", matrix[i][j]);
//		}
//		printf("\n");
//	}
	
	int *visited = (int*) malloc ( sizeof(int) * n );
	
	for(i = 0 ; i < n ; i ++) {
		visited[i] = 0;
	}
		
	// NO : 0 , YES : 1
	j = 0;
	s = s - 1;
	while( j < n ) {
		
		if( s == n ) {
			s = 0;
		}
		if( visited[ s ] == 0 && iter(matrix[s], n) ) {
			visited = aDFS(matrix, s, n, visited);
//			printIntArr(visited, n);
//			printf("\n");
		}
		j++;
		s++;
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
	
	// matrix 초기화
	
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
	
	DFS(matrix, n, s);
	
	return 0;
}
