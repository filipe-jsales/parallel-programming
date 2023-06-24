#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge in the graph
struct Edge
{
    int destination;
    int capacity;
    int cost;
};

// Function to find the minimum cost using the Bellman-Ford algorithm
int minCost(struct Edge **graph, int numVertices, int source, int destination)
{
    int i, j, k;
    int *dist = (int *)malloc(numVertices * sizeof(int));
    int *prev = (int *)malloc(numVertices * sizeof(int));

    for (i = 0; i < numVertices; ++i)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    dist[source] = 0;

    // Relax edges repeatedly
    for (i = 0; i < numVertices - 1; ++i)
    {
        for (j = 0; j < numVertices; ++j)
        {
            for (k = 0; k < numVertices; ++k)
            {
                int v = graph[j][k].destination;
                int capacity = graph[j][k].capacity;
                int cost = graph[j][k].cost;

                if (capacity > 0 && dist[j] != INT_MAX && dist[j] + cost < dist[v])
                {
                    dist[v] = dist[j] + cost;
                    prev[v] = j;
                }
            }
        }
    }

    // Check for negative cycle
    for (j = 0; j < numVertices; ++j)
    {
        for (k = 0; k < numVertices; ++k)
        {
            int v = graph[j][k].destination;
            int capacity = graph[j][k].capacity;
            int cost = graph[j][k].cost;

            if (capacity > 0 && dist[j] != INT_MAX && dist[j] + cost < dist[v])
            {
                free(dist);
                free(prev);
                return -1; // Negative cycle exists
            }
        }
    }

    // Calculate the minimum cost
    int minCost = 0;
    int u = destination;

    while (prev[u] != -1)
    {
        for (k = 0; k < numVertices; ++k)
        {
            if (graph[prev[u]][k].destination == u)
            {
                graph[prev[u]][k].capacity--;
                minCost += graph[prev[u]][k].cost;
                break;
            }
        }

        u = prev[u];
    }

    free(dist);
    free(prev);
    return minCost;
}

int main()
{
    // Example usage
    int numVertices = 5;
    struct Edge **graph = (struct Edge *)malloc(numVertices * sizeof(struct Edge));

    int i;
    for (i = 0; i < numVertices; ++i)
    {
        graph[i] = (struct Edge *)malloc(numVertices * sizeof(struct Edge));
    }

    // Adding edges to the graph
    graph[0][0].destination = 1;
    graph[0][0].capacity = 3;
    graph[0][0].cost = 2;

    graph[0][1].destination = 2;
    graph[0][1].capacity = 2;
    graph[0][1].cost = 4;

    graph[1][0].destination = 2;
    graph[1][0].capacity = 2;
    graph[1][0].cost = 1;

    graph[1][1].destination = 3;
    graph[1][1].capacity = 3;
    graph[1][1].cost = 6;

    graph[2][0].destination = 3;
    graph[2][0].capacity = 1;
    graph[2][0].cost = 3;

    graph[2][1].destination = 4;
    graph[2][1].capacity = 2;
    graph[2][1].cost = 5;

    graph[3][0].destination = 4;
    graph[3][0].capacity = 1;
    graph[3][0].cost = 2;

    int source = 0;
    int destination = 4;

    int minimumCost = minCost(graph, numVertices, source, destination);

    if (minimumCost == -1)
    {
        printf("Negative cycle detected. No feasible solution exists.\n");
    }
    else
    {
        printf("Minimum cost of transportation: %d\n", minimumCost);
    }

    for (i = 0; i < numVertices; ++i)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}