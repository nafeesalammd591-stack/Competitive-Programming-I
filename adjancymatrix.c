// Write a C program to represent a graph using an adjacency matrix.
#include <stdio.h>

#define MAX 100

int main() {
    int graph[MAX][MAX];
    int vertices, edges;
    int u, v;
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    /* Initialize matrix with 0 */
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (source destination):\n");

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        /* Undirected graph */
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    /* Display adjacency matrix */
    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
