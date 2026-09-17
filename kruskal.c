// Write a C program to implement Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a weighted graph.
#include <stdio.h>

#define MAX 100

struct Edge {
    int source;
    int destination;
    int weight;
};

int parent[MAX];

/* Find the parent of a vertex */
int find(int vertex) {
    if (parent[vertex] == vertex)
        return vertex;

    return find(parent[vertex]);
}

/* Join two sets */
void unionSet(int u, int v) {
    int parentU = find(u);
    int parentV = find(v);

    parent[parentV] = parentU;
}

/* Sort edges by weight */
void sortEdges(struct Edge edges[], int edgeCount) {
    int i, j;
    struct Edge temp;

    for (i = 0; i < edgeCount - 1; i++) {
        for (j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Edge edges[MAX];
    int vertices, edgeCount;
    int i;
    int selectedEdges = 0;
    int totalCost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edgeCount);

    printf("Enter source, destination and weight of each edge:\n");

    for (i = 0; i < edgeCount; i++) {
        scanf("%d %d %d",
              &edges[i].source,
              &edges[i].destination,
              &edges[i].weight);
    }

    /* Initialize parent array */
    for (i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    /* Sort edges according to weight */
    sortEdges(edges, edgeCount);

    printf("\nEdges in Minimum Spanning Tree:\n");

    /* Select edges */
    for (i = 0; i < edgeCount && selectedEdges < vertices - 1; i++) {

        int u = edges[i].source;
        int v = edges[i].destination;

        /* Check whether adding edge creates a cycle */
        if (find(u) != find(v)) {

            printf("%d -- %d = %d\n",
                   u, v, edges[i].weight);

            totalCost += edges[i].weight;

            unionSet(u, v);

            selectedEdges++;
        }
    }

    if (selectedEdges != vertices - 1) {
        printf("\nMST cannot be formed. Graph is disconnected.\n");
    } else {
        printf("\nMinimum Cost of MST = %d\n", totalCost);
    }

    return 0;
}
