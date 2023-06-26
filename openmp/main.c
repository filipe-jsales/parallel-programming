#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>
#pragma GCC optimize("O3")

struct Edge
{
    int destination;
    int capacity;
    int cost;
};

int minCost(struct Edge **graph, int numVertices, int source, int destination)
{
    int i, j, k;
    int *dist = (int *)malloc(numVertices * sizeof(int));
    int *prev = (int *)malloc(numVertices * sizeof(int));

#pragma omp parallel for
    for (i = 0; i < numVertices; ++i)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    dist[source] = 0;

#pragma omp parallel for
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

    int negativeCycleExists = 0;
    #pragma omp parallel for shared(dist, negativeCycleExists) private(j, k) collapse(2)
    for (j = 0; j < numVertices; ++j)
    {
        for (k = 0; k < numVertices; ++k)
        {
            int v = graph[j][k].destination;
            int capacity = graph[j][k].capacity;
            int cost = graph[j][k].cost;

            if (capacity > 0 && dist[j] != INT_MAX && dist[j] + cost < dist[v])
            {
#pragma omp critical
                {
                    negativeCycleExists = 1;
                }
            }
        }
    }

    if (negativeCycleExists)
    {
        free(dist);
        free(prev);
        return -1;
    }

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

#pragma omp parallel
    {
        // int thread_id = omp_get_thread_num();
        printf("Hello from thread %d\n", omp_get_thread_num());
    }
    double startTime, endTime;
    startTime = omp_get_wtime();

    int numVertices = 100;
    struct Edge **graph = (struct Edge **)malloc(numVertices * sizeof(struct Edge *));
    struct Edge *graphData = (struct Edge *)malloc(numVertices * numVertices * sizeof(struct Edge));

    int i;
    for (i = 0; i < numVertices; ++i)
    {
        graph[i] = &graphData[i * numVertices];
    }

    // data goes here
    // Adding edges to the graph

    // data ends here

    int source = 0;
    int destination = 13;

    int minimumCost = minCost(graph, numVertices, source, destination);

    endTime = omp_get_wtime();
    double processingTime = endTime - startTime;

    printf("Processing time: %f seconds\n", processingTime);

    if (minimumCost == -1)
    {
        printf("Negative cycle detected. No feasible solution exists.\n");
    }
    else
    {
        printf("Minimum cost of transportation: %d\n", minimumCost);
    }

#pragma omp parallel for
    for (i = 0; i < numVertices; ++i)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}