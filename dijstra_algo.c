// Write a C program to perform Dijkstra's algorithm for finding the Single Source Shortest Path (SSSP) in a weighted graph.
#include <stdio.h>

#define MAX 100
#define INF 99999

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int distance[MAX];
    int visited[MAX];
    int i, j, min, u;

    /* Initialize */
    for (i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[source] = 0;

    /* Dijkstra's Algorithm */
    for (i = 0; i < n - 1; i++) {

        min = INF;
        u = -1;

        /* Find the unvisited vertex with minimum distance */
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        /* Update distances of adjacent vertices */
        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                graph[u][j] != 0 &&
                distance[u] != INF &&
                distance[u] + graph[u][j] < distance[j]) {

                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    /* Display shortest distances */
    printf("\nShortest distances from source vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("Vertex %d -> Not Reachable\n", i);
        else
            printf("Vertex %d -> %d\n", i, distance[i]);
    }
}

int main() {
    int graph[MAX][MAX];
    int n, source;
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex.\n");
        return 0;
    }

    dijkstra(graph, n, source);

    return 0;
}