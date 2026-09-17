// Write a C program to perform Breadth First Search (BFS) traversal of a graph.
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int vertices;
int front = 0, rear = 0;

void BFS(int start) {
    int i;
    
    /* Insert starting vertex into queue */
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int vertex = queue[front++];

        printf("%d ", vertex);

        /* Visit all adjacent vertices */
        for (i = 0; i < vertices; i++) {
            if (graph[vertex][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
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

    printf("\nBFS Traversal: ");
    BFS(start);

    printf("\n");

    return 0;
}