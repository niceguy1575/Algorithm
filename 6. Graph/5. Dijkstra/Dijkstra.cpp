#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

void printIntArr(int* arr, int n){
	for(int i = 0 ; i < n ; i ++) {
		printf("%d ", arr[i]);
	}
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
}

void dijkstra(int** matrix, int n, int m, int r, int t){
	int i, u, v;
	int *d = (int*) malloc ( sizeof(int) * n );
	int *prev = (int*) malloc ( sizeof(int) * n );
	int *visited = (int*) malloc ( sizeof(int) * n );
	
	for(i = 0 ; i < n ; i++) {
		d[i] = INF;
		prev[i] = 0;
		visited[i] = 0;
	}
	
	d[r-1] = 0;
	
	for(i = 0 ; i < n ; i ++){
		u = extract_min(d, visited, n);
		visited[u] = 1;
		
			for(v = 0 ; v < n; v ++) {
				if(matrix[u][v] && visited[v] == 0 && d[u] + matrix[u][v] < d[v]) {
					d[v] = d[u] + matrix[u][v];
					prev[v] = u + 1;
				}
			}
		}
	printIntArr(prev, n);
	
	if(d[t-1] != INF) {
		printf("%d", d[t-1] );
	}
	else {
		printf("Impossible");
	}
}

int main() {
	
	int n, m, i, j, x, y, w, r, t;

	scanf("%d", &n);
	scanf("%d", &m);
	
	int **matrix = (int**) malloc ( sizeof(int*) * n );
	for(i = 0 ; i < n; i++){
	    matrix[i] = (int*) malloc ( sizeof(int) * n );
	}
	
	// matrix ÃÊ±âÈ­
	
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j ++) {
			matrix[i][j] = 0;
		}
	}
		
	for(i = 0 ; i < m ; i ++) {
		scanf("%d %d %d", &x, &y, &w);
		matrix[x-1][y-1] = w;
	}

	scanf("%d %d", &r, &t);

	dijkstra(matrix, n, m, r, t);
	
	return 0;
}
