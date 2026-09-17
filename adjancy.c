// Write a C program to represent a graph using an adjacency list.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adjList[MAX];

/* Add an edge */
void addEdge(int u, int v) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

int main() {
    int vertices, edges;
    int u, v;
    int i;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    /* Initialize adjacency list */
    for (i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }

    printf("Enter the edges (source destination):\n");

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        /* For an undirected graph */
        addEdge(u, v);
        addEdge(v, u);
    }

    /* Display adjacency list */
    printf("\nAdjacency List:\n");

    for (i = 0; i < vertices; i++) {
        struct Node *temp = adjList[i];

        printf("%d -> ", i);

        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }

    return 0;
}