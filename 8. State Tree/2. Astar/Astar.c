#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 99999;
  
int matrix[150][150];
double f[150][150];
double g[150][150];
double h[150][150];
int Q[150][150];
int C[150][150];
int count = 0;
int n, m, sx, sy, fx, fy;
  
typedef struct point {
 int x;
 int y;
} Point;
 
  
Point prev[150][150];
Point to;
  
double eucliean_dist(const Point a, const Point b) {
    int x = abs(a.x - b.x);
    int y = abs(a.y - b.y);
    x = x < 0.0 ? -x : x;
    y = y < 0.0 ? -y : y;
     
    return sqrt(x*x + y*y); 
} 
  
int isEmpty(int n, int m) {
 
    int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {

			if (Q[i][j] != 0)
			return 0;
		}

	}
 return 1;
}
  
Point delMin(int n, int m) {
    Point p;
    p.x = -1;
    p.y = -1;
      
    double min = INF;
    int i, j;
 
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (Q[i][j] == 1 && f[i][j] < min) {
                p.x = i;
				p.y = j;
				min = g[i][j] + h[i][j];
            }
              
            else if (Q[i][j] == 1 && f[i][j] == min && C[i][j] < C[p.x][p.y]) {
                p.x = i;
				p.y = j;
				min = g[i][j] + h[i][j];
            }
        }
    }
    Q[p.x][p.y] = 0;
      
    return p;
}
  
void Print(int tx, int ty) {
    if (tx == sx && ty == sy) {
        printf("(%d, %d) -> ",tx, ty);
    }
    else {
        Print(prev[tx][ty].x, prev[tx][ty].y);
        printf("(%d, %d)", tx, ty);
        if (!(tx == fx && ty == fy)) {
            printf(" -> ");
        }
    }
}
  
void Astar(int sx, int sy, int n, int m, Point to) {
    Point temp, u;
    int i, j, l;
 
    int rx[8] = {-1,-1,-1,0,0,1,1,1};
    int ry[8] = {-1,0,1,-1,1,-1,0,1};
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            Q[i][j] = 1;
            
            // 전부 INF 로 초기화 
            g[i][j] = INF;
			f[i][j] = INF;
			
			// temp
            temp.x = i;
			temp.y = j;
			
			// euclidan 거리를 h에 저장 
			h[i][j] = eucliean_dist(temp, to);
        }
    }
      
    g[sx][sy] = 0; // 시작점 
    f[sx][sy] = h[sx][sy]; // 시작점의 거리 
      
    while (!isEmpty(n, m)) {
          
        u = delMin(n, m);
          
        if (u.x == -1 || u.y == -1) {
            printf("\n-1");
            break;
        }
 
        if (u.x == fx && u.y == fy) {
            Print(fx, fy);
            printf("\n%0.2f", f[fx][fy]);
            break;
        }
          
        for (l = 0; l < 8; l++) {
		  double u_wv= (rx[l] != 0 && ry[l] != 0) ? sqrt(2) : 1; // plus value

            if ((Q[u.x + rx[l]][u.y + ry[l]] == 1) && 
            ((u.x + rx[l] >= 1) && (u.x + rx[l] <= n)) &&
             ((u.y + ry[l] >= 1) && (u.y + ry[l] <= m)) &&
			 (matrix[u.x + rx[l]][u.y + ry[l]] != 1) && // 연결정점 확인 
			 (g[u.x][u.y] + u_wv < g[u.x + rx[l]][u.y + ry[l]]) 
			 ) 
			 {   
                    g[u.x + rx[l]][u.y + ry[l]] = g[u.x][u.y] + u_wv;
                    prev[u.x + rx[l]][u.y + ry[l]] = u;
                    f[u.x + rx[l]][u.y + ry[l]] = g[u.x + rx[l]][u.y + ry[l]] + h[u.x + rx[l]][u.y + ry[l]];
                    C[u.x + rx[l]][u.y + ry[l]] = ++count;
               
            }
        }
    }
}
  
int main() {
    scanf("%d %d", &n, &m);
     int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
      
    scanf("%d %d", &sx, &sy);
    scanf("%d %d", &fx, &fy);
      
  //  start.x = sx;
    //start.y = sy;
    to.x = fx; to.y = fy;
      
    Astar(sx, sy, n, m, to);
      
    return 0;
}
