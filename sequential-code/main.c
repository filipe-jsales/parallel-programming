#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
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
    clock_t startTime, endTime;
    double executionTime;

    startTime = clock();
    int numVertices = 100;
    struct Edge **graph = (struct Edge *)malloc(numVertices * sizeof(struct Edge));

    int i;
    for (i = 0; i < numVertices; ++i)
    {
        graph[i] = (struct Edge *)malloc(numVertices * sizeof(struct Edge));
    }
    // data goes here
    // Adding edges to the graph

    graph[0][3].destination = 1;
    graph[0][3].capacity = 2;
    graph[0][3].cost = 5;

    graph[1][3].destination = 2;
    graph[1][3].capacity = 1;
    graph[1][3].cost = 3;

    graph[1][4].destination = 3;
    graph[1][4].capacity = 2;
    graph[1][4].cost = 7;

    graph[2][2].destination = 4;
    graph[2][2].capacity = 1;
    graph[2][2].cost = 2;

    graph[2][3].destination = 5;
    graph[2][3].capacity = 3;
    graph[2][3].cost = 4;

    graph[2][4].destination = 6;
    graph[2][4].capacity = 2;
    graph[2][4].cost = 3;

    graph[3][0].destination = 7;
    graph[3][0].capacity = 1;
    graph[3][0].cost = 5;

    graph[3][1].destination = 8;
    graph[3][1].capacity = 2;
    graph[3][1].cost = 3;

    graph[3][2].destination = 9;
    graph[3][2].capacity = 3;
    graph[3][2].cost = 6;

    graph[4][0].destination = 10;
    graph[4][0].capacity = 2;
    graph[4][0].cost = 4;

    graph[4][1].destination = 11;
    graph[4][1].capacity = 1;
    graph[4][1].cost = 2;

    graph[4][2].destination = 12;
    graph[4][2].capacity = 3;
    graph[4][2].cost = 5;

    graph[5][0].destination = 13;
    graph[5][0].capacity = 2;
    graph[5][0].cost = 4;

    graph[5][1].destination = 14;
    graph[5][1].capacity = 3;
    graph[5][1].cost = 2;

    graph[5][2].destination = 15;
    graph[5][2].capacity = 1;
    graph[5][2].cost = 3;

    graph[5][3].destination = 16;
    graph[5][3].capacity = 2;
    graph[5][3].cost = 6;

    graph[5][4].destination = 17;
    graph[5][4].capacity = 3;
    graph[5][4].cost = 4;

    graph[6][0].destination = 18;
    graph[6][0].capacity = 2;
    graph[6][0].cost = 1;

    graph[6][1].destination = 19;
    graph[6][1].capacity = 1;
    graph[6][1].cost = 3;

    graph[6][2].destination = 20;
    graph[6][2].capacity = 3;
    graph[6][2].cost = 5;

    graph[6][3].destination = 21;
    graph[6][3].capacity = 2;
    graph[6][3].cost = 4;

    graph[7][0].destination = 22;
    graph[7][0].capacity = 1;
    graph[7][0].cost = 2;

    graph[7][1].destination = 23;
    graph[7][1].capacity = 2;
    graph[7][1].cost = 3;

    graph[7][2].destination = 24;
    graph[7][2].capacity = 1;
    graph[7][2].cost = 4;

    graph[8][0].destination = 25;
    graph[8][0].capacity = 3;
    graph[8][0].cost = 1;

    graph[8][1].destination = 26;
    graph[8][1].capacity = 2;
    graph[8][1].cost = 5;

    graph[8][2].destination = 27;
    graph[8][2].capacity = 1;
    graph[8][2].cost = 2;

    graph[8][3].destination = 28;
    graph[8][3].capacity = 3;
    graph[8][3].cost = 6;

    graph[9][0].destination = 29;
    graph[9][0].capacity = 2;
    graph[9][0].cost = 3;

    graph[9][1].destination = 30;
    graph[9][1].capacity = 1;
    graph[9][1].cost = 2;

    graph[9][2].destination = 31;
    graph[9][2].capacity = 3;
    graph[9][2].cost = 4;

    graph[10][0].destination = 32;
    graph[10][0].capacity = 1;
    graph[10][0].cost = 5;

    graph[10][1].destination = 33;
    graph[10][1].capacity = 2;
    graph[10][1].cost = 3;

    graph[10][2].destination = 34;
    graph[10][2].capacity = 3;
    graph[10][2].cost = 2;

    // data ends here

    int source = 0;
    int destination = 4;

    int minimumCost = minCost(graph, numVertices, source, destination);
    endTime = clock();
    executionTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", executionTime);

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