#include <stdio.h>
#include <stdlib.h>

int valid(int i, int color, int**matrix, int* colors) {
	
//	printf("valid - (%d, %d)\n", i, color);

	for(int j = 0 ; j < i-1; j++) {
		
		if( matrix[i][j] == 1 && colors[j] == color) {
				return 0;
		}
	}
	
	return 1;
}

int kColoring(int i, int color, int nation, int** matrix, int* colors) {
			
	printf("(%d, %d)\n", i, color);
	if( valid(i, color, matrix, colors) ) {
		
		colors[i-1] = color;
		
		if( i == nation ) {
			return 1;
		}
		
		else {
			int result = 0;
			int d = 1;
			
			while( result == 0 && d <= color ) {
				result = kColoring(i+1, d, nation, matrix, colors);
				d++;
			}
		
			return result;
		}
	}
	else {
		return 0;
	}
}

void graphColoring(int** matrix, int nation, int color) {

		// colors tab
		int *colors = (int*) malloc ( sizeof(int*) * nation );
		
		for(int j = 0 ; j < nation; j++) {
			colors[j] = 0;
		}
		
		int res;
		
		for(int k = 1; k <= color ; k++) {
			res = kColoring(k, k, nation, matrix, colors);
		}
		
		if(res == 1) {
			printf("possible");
		}
		else {
			printf("impossible");
		}
}


int main() {
	
	int nation, neighbor, color, i, j, x, y;
	
	scanf("%d %d %d", &nation, &neighbor, &color);

	int **matrix = (int**) malloc ( sizeof(int*) * nation );
	for(i = 0 ; i < nation; i++){
	    matrix[i] = (int*) malloc ( sizeof(int) * nation );
	}
	
	// matrix ÃÊ±âÈ­
	for(i = 0 ; i < nation ; i++) {
		for(j = 0 ; j < nation ; j ++) {
			matrix[i][j] = 0;
		}
	}

	for(i = 0 ; i < neighbor ; i ++) {
		scanf("%d %d", &x, &y);
		matrix[x-1][y-1] = 1;
		matrix[y-1][x-1] = 1;
	}
		
	graphColoring(matrix, nation, color);
	
	return 0;
}
