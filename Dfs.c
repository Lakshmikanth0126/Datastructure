#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int n;      
    int A[MAX_VERTICES][MAX_VERTICES];  
} Graph;


void init_graph(Graph *G, int n) {
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}


void add_edge(Graph *G, int x, int y) {
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

void DFS(Graph *G, int start, int visited[]) {
    int i;


    visited[start] = 1;
    printf("%d ", start);

    
    for (i = 1; i <= G->n; i++) {
        if (G->A[start][i] == 1 && visited[i] == 0) {
            DFS(G, i, visited);
        }
    }
}

int main() {
    Graph G;
    int visited[MAX_VERTICES];
    int i;

    init_graph(&G, 4);
    add_edge(&G, 1, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 2, 4);

    for (i = 1; i <= G->n; i++) {
        visited[i] = 0;
    }

    printf("Visited vertices: ");
    DFS(&G, 1, visited);
    printf("\n");
    return 0;
}

