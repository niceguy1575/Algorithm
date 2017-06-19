#include <stdio.h>
#include <stdlib.h>

int valid(int i, int**matrix, int* colorArr) {
	
	printf("(%d, %d)\n", i+1, colorArr[i]);
	int j;
	int result = 1;
	
	while(j<i && result) {
		if( matrix[i][j] && colorArr[j] == colorArr[i] ) {
			result = 0;
		}
		j++;
	}
	return 1;
}

int kColoring(int i, int color, int nation, int** matrix, int* colorArr) {
	
	if( valid(i, matrix, colorArr) ) {
		if(i == nation) {
			return 1;
		}
		else {
			int result = 0;
			for(int c = 1 ; c <= color; c++) {
				colorArr[i+1] = color;
				kColoring(i+1, color, nation, matrix, colorArr);
			}
			return result;
		}
	}
}

void graphColoring(int** matrix, int nation, int color)    {

	// colors tab
	int *colorArr = (int*) malloc ( sizeof(int) * nation );
	
	for(int j = 0 ; j < nation; j++) {
		colorArr[j] = 0;
	}
	
    if ( !kColoring(0, color, nation, matrix, colorArr) ) {
        printf("impossible");
    }
    else {
    	printf("possible");
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
