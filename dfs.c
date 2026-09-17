// Write a C program to perform Depth First Search (DFS) traversal of a graph.

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int vertices;

/* DFS function */
void DFS(int vertex) {
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    for (i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    /* Initialize visited array */
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= vertices) {
        printf("Invalid starting vertex.\n");
        return 0;
    }

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}