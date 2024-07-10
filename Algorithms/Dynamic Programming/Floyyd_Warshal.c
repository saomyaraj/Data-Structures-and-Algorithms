#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to find the shortest paths between every pair of vertices
void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize the distance matrix with the same values as the input graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Calculate shortest paths
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, update the shortest path
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest paths
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    // Find and print shortest paths
    floydWarshall(graph);

    return 0;
}


// The function floydWarshall takes the weighted graph as input and calculates the shortest paths between every pair of vertices using the Floyd-Warshall algorithm.
// It initializes a 2D array dist to store the shortest distances between every pair of vertices. Initially, it is initialized with the same values as the input graph.
// The algorithm then iterates over all vertices and checks if including vertex k as an intermediate vertex on the path from i to j leads to a shorter path. If so, it updates the shortest distance accordingly.
// After the completion of the algorithm, the function prints the shortest distances between every pair of vertices.
// In the main function, an example graph is defined as an adjacency matrix, and the floydWarshall function is called to find and print the shortest paths.