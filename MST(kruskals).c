AIM: To find the Minimum Spanning Tree (MST) of a graph using Kruskal's Algorithm, which connects all vertices with minimum total edge weight without forming cycles.

PROGRAM:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5 // Number of vertices
#define E 6 // Number of edges

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

int parentUF[V]; // Array for Union-Find (Disjoint Set)

// Function to find root of a set (Find operation)
int find(int i)
{
    if (parentUF[i] == i)
        return i;

    return find(parentUF[i]); // Recursively find root
}

// Function to perform union of two sets
void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);

    parentUF[rootU] = rootV; // Attach one tree to another
}

// Function to compare edges based on weight (for sorting)
int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to implement Kruskal's MST Algorithm
void kruskalMST(struct Edge edges[])
{
    printf("\nKruskal's MST:\n");
    printf("Edge \tWeight\n");

    // Sort edges in increasing order of weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; i++)
        parentUF[i] = i;

    int count = 0; // Number of edges in MST
    int total = 0; // Total cost of MST

    // Pick edges one by one
    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        // Check if adding this edge creates a cycle
        if (find(u) != find(v))
        {
            // Include edge in MST
            printf("%d - %d \t%d\n", u, v, edges[i].weight);

            total += edges[i].weight;

            unionSet(u, v); // Merge sets

            count++;
        }
    }

    // Print total cost of MST
    printf("Total Cost = %d\n", total);
}

int main()
{
    // List of edges (graph representation)
    struct Edge edges[E] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 5},
        {1, 3, 3},
        {2, 4, 4},
        {3, 4, 2}
    };

    // Call Kruskal's function
    kruskalMST(edges);

    return 0;
}

OUTPUT:
Kruskal's MST:
Edge 	Weight
0 - 1 	2
3 - 4 	2
0 - 2 	3
1 - 3 	3
Total Cost = 10
