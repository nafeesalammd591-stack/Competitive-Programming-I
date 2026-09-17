// Write a C program to implement Bellman-Ford algorithm for finding the Single Source Shortest Path (SSSP).

#include <stdio.h>

#define MAX 100
#define INF 99999

struct Edge {
    int source;
    int destination;
    int weight;
};

void bellmanFord(struct Edge edges[], int vertices, int edgesCount, int source) {
    int distance[MAX];
    int i, j;

    /* Initialize distances */
    for (i = 0; i < vertices; i++) {
        distance[i] = INF;
    }

    distance[source] = 0;

    /* Relax all edges V-1 times */
    for (i = 1; i <= vertices - 1; i++) {
        for (j = 0; j < edgesCount; j++) {

            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;

            if (distance[u] != INF &&
                distance[u] + w < distance[v]) {

                distance[v] = distance[u] + w;
            }
        }
    }

    /* Check for negative weight cycle */
    for (j = 0; j < edgesCount; j++) {

        int u = edges[j].source;
        int v = edges[j].destination;
        int w = edges[j].weight;

        if (distance[u] != INF &&
            distance[u] + w < distance[v]) {

            printf("\nGraph contains a negative weight cycle.\n");
            return;
        }
    }

    /* Display shortest distances */
    printf("\nShortest distances from source vertex %d:\n", source);

    for (i = 0; i < vertices; i++) {
        if (distance[i] == INF)
            printf("Vertex %d -> Not Reachable\n", i);
        else
            printf("Vertex %d -> %d\n", i, distance[i]);
    }
}

int main() {
    struct Edge edges[MAX];
    int vertices, edgesCount;
    int i, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edgesCount);

    printf("\nEnter source, destination and weight for each edge:\n");

    for (i = 0; i < edgesCount; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d",
              &edges[i].source,
              &edges[i].destination,
              &edges[i].weight);
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= vertices) {
        printf("Invalid source vertex.\n");
        return 0;
    }

    bellmanFord(edges, vertices, edgesCount, source);

    return 0;
}