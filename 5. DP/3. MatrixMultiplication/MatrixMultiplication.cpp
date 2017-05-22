#include <stdio.h>
#include <stdlib.h>
#define MIN 99999999

int main() {
	
	int n, col, row, i, j, r, k;
	
	scanf("%d",  &n);
	
	int **matrix = (int**) malloc ( sizeof(int*) * n );
	int *p = (int*) malloc ( sizeof(int*) * n * 2);
	
	for(i = 0 ; i < n; i++) {
		scanf("%d %d", &col, &row);
		if(i==n-1){
			p[i] = col;
			p[i+1] = row;
		}
		else {
			p[i] = col;
		}
	}
		
	for(i = 1 ; i <= n ; i ++) {
   		matrix[i] = (int*) malloc ( sizeof(int) * n );
   		matrix[i][i] = 0;
	}
	
	for(r = 1; r <= n-1; r++) {
		for(i = 1; i <= n-r; i++) {
			j = i + r;
			matrix[i][j] = MIN;
			for(k = i ; k < j; k++) {
				if(matrix[i][j] > matrix[i][k] + matrix[k+1][j] + p[(i-1)]*p[k]*p[j] ){
					matrix[i][j] = matrix[i][k] + matrix[k+1][j] + p[(i-1)]*p[k]*p[j];
				} 
            }
		}
	}
			
	printf("%d", matrix[1][n]);
	return 0;
}
