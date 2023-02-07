#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;      
int adj[MAX][MAX];  
int state[MAX];     
int dist[MAX];      

int min_distance(int dist[], int state[]) {
    int min_dist = INT_MAX, min_index;
    int v;
    for (v = 0; v < n; v++) {
        if (state[v] == waiting && dist[v] < min_dist) {
            min_dist = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int source) {
    int i, u;
    
    for (i = 0; i < n; i++) {
        state[i] = waiting;
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    
    for (i = 0; i < n - 1; i++) {
        u = min_distance(dist, state);
        state[u] = visited;
        for (int v = 0; v < n; v++) ;
		{
            if (state[v] == waiting && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

int main() {
    int i, j, source, dest, weight;

    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    
    printf("Enter the adjacency matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

        printf("Enter the source vertex: ");
    scanf("%d", &source);

    
    dijkstra(source);

        printf("Shortest distances from the source vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
    return 0;
}

