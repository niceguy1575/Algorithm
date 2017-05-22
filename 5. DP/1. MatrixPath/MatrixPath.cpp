#include <stdio.h>
#include <stdlib.h>

int min(int A, int B){
	if( A < B) {
		return A;
	}
	else {
		return B;
	}
}

int main() {
	
	int n, m, i, j, time;
	
	scanf("%d %d", &n, &m);
	
	int **matrix = (int**) malloc ( sizeof(int*) * n );
	int **c = (int**) malloc ( sizeof(int*) * n );

	
	for(i = 0 ; i < n ; i ++) {
   		matrix[i] = (int*) malloc ( sizeof(int) * m );
   		c[i] = (int*) malloc ( sizeof(int) * m );
   		for(j = 0; j < m ; j++) {
   			scanf("%d", &time);
   			*(matrix[i] + j) = time;
		}
	}
	
	c[0][0] = *(matrix[0] + 0);
	
	for(i = 1; i < n; i++) {
		c[i][0] = *(matrix[i] + 0) + c[i-1][0];
	}

	for(j = 1; j < m; j++) {
		c[0][j] = *(matrix[0] + j) + c[0][j-1];
	}
	
	for(i = 1; i < n ; i ++) {
		for(j = 1; j < m ; j++) {
			c[i][j] = *(matrix[i] + j) + min(c[i-1][j], c[i][j-1] );
		}
	}
	
	printf("%d", c[n-1][m-1]);
	
		
	return 0;
}
