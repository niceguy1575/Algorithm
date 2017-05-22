#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX  9999
#define MAX_EDGE 9999

typedef struct Edge{
    int s, d;
	int w;
}EDGE;

struct vertices {
    int p;
    int rank;
}vt[MAX_VERTEX];

EDGE e[MAX_EDGE];

void make_set(int v){
    vt[v].p     = v;
    vt[v].rank  = 0;
}

int find_set(int v){
    if( vt[v].p != v) {
        vt[v].p = find_set(vt[v].p);
    }
    return vt[v].p;
}

void bubbleSort(int n) {
	
	int sorted;
	EDGE temp;
	
	for(int last = n; last > 1; last--) {
		sorted = 1;
		for(int i = 0; i < last - 1; i++) {
			if(e[i].w > e[i+1].w) {
				    temp = e[i];
	                e[i] = e[i+1];
	                e[i+1] = temp;
				sorted = 0;
			}
		}
	}
}

void merge(int v, int u) {
    v = find_set( v);
    u = find_set( u);

    if( vt[v].rank > vt[u].rank)
    {
        vt[u].p = v;
    }
    else
    {
        vt[v].p = u;

        if( vt[v].rank == vt[u].rank)
        {
            vt[u].rank = vt[u].rank + 1;
        }
    }
}

void kruskal(int n, int m){
    int i;
    int sum = 0;
    for(i = 0 ; i < n ; i ++) {
        make_set(i);
    }
    
    bubbleSort(m);

    for(i = 0; i < m ; i ++)    {
        if( find_set(e[i].s) != find_set(e[i].d))  {
        	printf("%d ", e[i].w);
            merge(e[i].s, e[i].d);
            sum = sum + e[i].w;
        }
    }
    printf("%d", sum);
}

int main() {
	
	int n, m, i, x, y, w;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	for(i = 0 ; i < m ; i ++) {
		scanf("%d %d %d", &x, &y, &w);
		e[i].s  = x - 1;
        e[i].d  = y - 1;
		e[i].w = w;
	}
		
	kruskal(n, m);
	
	return 0;
}
