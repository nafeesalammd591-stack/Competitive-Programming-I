// Write a C program to perform Prim's algorithm to find the Minimum Spanning Tree (MST) of a weighted graph.
#include <stdio.h>

#define MAX 100
#define INF 99999

int main() {
    int graph[MAX][MAX];
    int visited[MAX];
    int vertices;
    int i, j, edges;
    int min, u, v;
    int totalCost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    /* Initialize visited array */
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    /* Start from vertex 0 */
    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (edges = 0; edges < vertices - 1; edges++) {
        min = INF;
        u = -1;
        v = -1;

        /* Find minimum weight edge */
        for (i = 0; i < vertices; i++) {
            if (visited[i]) {
                for (j = 0; j < vertices; j++) {
                    if (!visited[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min) {

                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        /* If no edge is found, graph is disconnected */
        if (u == -1 || v == -1) {
            printf("MST cannot be formed. Graph is disconnected.\n");
            return 0;
        }

        printf("%d -- %d = %d\n", u, v, min);

        totalCost += min;
        visited[v] = 1;
    }

    printf("\nMinimum Cost of MST = %d\n", totalCost);

    return 0;
}
