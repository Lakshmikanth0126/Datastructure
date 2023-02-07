#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;      // Number of vertices
int adj[MAX][MAX];  // Adjacency matrix
int state[MAX];     // State of each vertex
int dist[MAX];      // Distance from the source vertex
int parent[MAX];    // Parent of each vertex in the MST

// Function to find the vertex with the minimum distance
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

// Prim's Algorithm
void prim(int source) {
    int i, u;
    // Initialize the state and distance arrays
    for (i = 0; i < n; i++) {
        state[i] = waiting;
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[source] = 0;

    // Find the MST
    for (i = 0; i < n - 1; i++) {
        u = min_distance(dist, state);
        state[u] = visited;
        for (int v = 0; v < n; v++) {
            if (state[v] == waiting && adj[u][v] && dist[u] != INT_MAX && adj[u][v] < dist[v]) {
                dist[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
}

int main() {
    int i, j, source, dest, weight;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Input the source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    // Call Prim's Algorithm
    prim(source);

    // Print the MST
    printf("Minimum Spanning Tree:\n");
    printf("Edge\t\tWeight\n");
    for (i = 1; i < n; i++) {
        printf("%d - %d\t\t%d\n", parent[i], i, dist[i]);
    }
    return 0;
}

