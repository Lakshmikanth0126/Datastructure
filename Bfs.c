#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int n;      
    int A[MAX_VERTICES][MAX_VERTICES];  
} Graph;


void enqueue(int queue[], int *rear, int x) {
    queue[(*rear)++] = x;
}

int dequeue(int queue[], int *front) {
    return queue[(*front)++];
}

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

void BFS(Graph *G, int start) {
    int queue[MAX_VERTICES], rear = 0, front = 0;
    int visited[MAX_VERTICES];
    int i, u, v;


    for (i = 1; i <= G->n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    enqueue(queue, &rear, start);

    while (rear != front) {
        u = dequeue(queue, &front);
        for (v = 1; v <= G->n; v++) {
            if (G->A[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                enqueue(queue, &rear, v);
            }
        }
    }

    
    printf("Visited vertices: ");
    for (i = 1; i <= G->n; i++) {
        if (visited[i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    Graph G;
    init_graph(&G, 4);
    add_edge(&G, 1, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 2, 4);
    BFS(&G, 1);
    return 0;
}

