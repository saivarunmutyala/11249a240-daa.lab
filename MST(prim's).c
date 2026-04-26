AIM:To implement Prim's Algorithm for finding the Minimum Spanning Tree (MST) of a connected weighted graph, growing the tree from an initial vertex by repeatedly adding the smallest edge that connects a vertex in the tree to a vertex outside it.

PROGRAM:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5  // Number of vertices
#define E 6  // Number of edges

// Function to find vertex with minimum key value
// Not yet included in MST
int minKey(int key[], int visited[])
{
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++)
    {
        // Select unvisited vertex with smallest key
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the MST
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0;

    // Print edges and calculate total cost
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total Cost = %d\n", total);
}

// Prim's Algorithm implementation
void primMST(int graph[V][V])
{
    int parent[V];   // Array to store MST
    int key[V];      // Minimum weight to connect each vertex
    int visited[V];  // Track vertices included in MST

    // Initialize all keys as INFINITY and visited as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from vertex 0
    key[0] = 0;      // First vertex has key 0
    parent[0] = -1;  // Root has no parent

    // MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick minimum key vertex not yet in MST
        int u = minKey(key, visited);

        visited[u] = 1;  // Add to MST

        // Update keys of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // If edge exists, v not visited, and weight is smaller
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printPrimMST(parent, graph);
}

int main()
{
    // Adjacency matrix representation of graph
    // 0 means no edge, other numbers represent weights
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    primMST(graph);

    return 0;
}

OUTPUT:
Prim's MST:
Edge 	Weight
0 - 1 	2
0 - 2 	3
1 - 3 	3
3 - 4 	2
Total Cost = 10
