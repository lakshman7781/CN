#include <stdio.h>

#include <limits.h>

#include <stdbool.h>

 

#define V 5 // Number of vertices in the graph

 

// Function to find the vertex with the minimum distance value
 
int minDistance(int dist[], bool sptSet[]) {

   int min = INT_MAX, min_index;

 

   for (int v = 0; v < V; v++) {

       if (!sptSet[v] && dist[v] <= min) {

           min = dist[v];

           min_index = v;

       }

   }

   return min_index;

}

 

// Function to print the shortest distance from source

void printSolution(int dist[]) {

   printf("Vertex \t Distance from Source\n");

   for (int i = 0; i < V; i++) {

       printf("%d \t\t %d\n", i, dist[i]);

   }

}

 

// Dijkstra's Algorithm implementation

void dijkstra(int graph[V][V], int src) {

   int dist[V];  // The output array: dist[i] holds the shortest distance from src to i

   bool sptSet[V]; // sptSet[i] is true if vertex i is included in the shortest path tree

 

   // Initialize all distances as INFINITE and sptSet[] as false

   for (int i = 0; i < V; i++) {

       dist[i] = INT_MAX;

       sptSet[i] = false;

   }

 

   // Distance of source vertex from itself is always 0

   dist[src] = 0;

 

   // Find shortest path for all vertices

   for (int count = 0; count < V - 1; count++) {

       // Pick the minimum distance vertex from the set of vertices not yet processed

       int u = minDistance(dist, sptSet);

 

       // Mark the picked vertex as processed

       sptSet[u] = true;
       // Update dist value of the adjacent vertices of the picked vertex
       for (int v = 0; v < V; v++) {
           if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
               dist[v] = dist[u] + graph[u][v];
           }
       }
   }
   printSolution(dist);
}

 

int main() {
   // Example graph as adjacency matrix
   int graph[V][V] = {

       {0, 10, 0, 0, 5},

       {0, 0, 1, 0, 2},

       {0, 0, 0, 4, 0},

       {7, 0, 6, 0, 0},

       {0, 3, 9, 2, 0}

   };
   int source = 0;
   printf("Source Vertex: %d\n", source);
   dijkstra(graph, source);
   return 0;

}
