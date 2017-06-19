#include <stdio.h>
#include <stdlib.h>

int valid(int i, int c, int** matrix, int* color, int n) {
		
	for(int j = 0 ; j < i-1; j++) {
//				printf("\t %d", matrix[i-1][j]);
//				printf("\t %d", c);
//				printf("\t %d\n", color[j]);
		if( matrix[i-1][j] == 1 && color[j] == c ) {
//			printf("i = %d, c= %d\n", i, c);
			return 0;
		}
	}
	
	return 1;
}

int kColoring(int i, int c, int** matrix, int* color, int k, int n) {
	
	printf("(%d, %d)\n", i, c);

	int result, d;
	
		 if( valid(i, c, matrix, color, n) ) {
			
			color[i-1] = c;
			
			if(i == n) {
				return 1;
			}
			
			else {
				result = 0;
				d = 1;
			
				while( result == 0 && d <= k && color[i] == 0) {
//					printf("i+1 : %d    , d : %d \t", i+1, d);
					result = kColoring(i+1, d, matrix, color, k, n);
					d++;
				}
//		return result;
			}
			return result;
		}
		else {
			return 0;
		}
	
}

int main() {
	
	int nation, neighbor, color, i, j, x, y, k;
	
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
	k = color;
	
	// colors tab
	int *colorArr = (int*) malloc ( sizeof(int) * (nation) );
	
	for(int j = 0 ; j < nation; j++) {
		colorArr[j] = 0;
	}
		
	if( kColoring(1, 1, matrix, colorArr, k, nation) == 0 ) {
        printf("impossible");
    }
    else {
    	printf("possible");
	}
	
	return 0;
}
