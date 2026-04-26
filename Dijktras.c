AIM:To implement Dijkstra’s Algorithm in C to find the shortest path from a source vertex to all other vertices in a graph.

PROGRAM:
#include <stdio.h>

#define V 5        // Number of vertices in the graph
#define INF 999999 // A large value representing infinity

// Function to find the vertex with minimum distance
int extractMin(int dist[], int visited[]) 
{ 
    int min = INF, min_index = -1;

    // Loop through all vertices
    for (int v = 0; v < V; v++) 
    { 
        // Select the unvisited vertex with smallest distance
        if (!visited[v] && dist[v] <= min) 
        {
            min = dist[v]; 
            min_index = v; 
        } 
    } 
    return min_index; 
} 

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V]) 
{ 
    int dist[V];     // Stores shortest distance from source
    int visited[V];  // Tracks visited vertices

    // Initialize distances as INF and visited as false
    for (int i = 0; i < V; i++) 
    { 
        dist[i] = INF; 
        visited[i] = 0;
    } 

    dist[0] = 0; // Distance from source (vertex 0) to itself is 0

    // Loop through all vertices
    for (int count = 0; count < V; count++) 
    { 
        int u = extractMin(dist, visited); // Get nearest unvisited vertex

        if (u == -1) 
            break; // Stop if no reachable vertex left

        visited[u] = 1; // Mark current vertex as visited

        // Update distances of adjacent vertices
        for (int j = 0; j < V; j++) 
        { 
            // Check if edge exists and vertex is unvisited
            if (graph[u][j] > 0 && !visited[j]) 
            { 
                // Update distance if shorter path is found
                if (dist[j] > dist[u] + graph[u][j]) 
                {
                    dist[j] = dist[u] + graph[u][j]; 
                } 
            }
        } 
    } 

    // Print shortest distances from source vertex
    printf("\nVertex \t Distance from Source (0)\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d --> %d\n", i, dist[i]); 
} 

int main() 
{ 
    // Adjacency matrix representation of graph
    int graph[V][V] = { 
        {0, 10, 0, 30, 100}, 
        {10, 0, 50, 0, 0}, 
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60}, 
        {100, 0, 10, 60, 0}
    }; 

    // Call Dijkstra function
    dijkstra(graph); 

    return 0; 
}

OUTPUT:
Vertex 	 Distance from Source (0)
0 --> 0
1 --> 10
2 --> 50
3 --> 30
4 --> 60
