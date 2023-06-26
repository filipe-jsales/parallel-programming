#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <mpi.h>

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

    for (i = 0; i < numVertices; ++i)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    dist[source] = 0;

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
    for (j = 0; j < numVertices; ++j)
    {
        for (k = 0; k < numVertices; ++k)
        {
            int v = graph[j][k].destination;
            int capacity = graph[j][k].capacity;
            int cost = graph[j][k].cost;

            if (capacity > 0 && dist[j] != INT_MAX && dist[j] + cost < dist[v])
            {
                negativeCycleExists = 1;
                break;
            }
        }
        if (negativeCycleExists)
            break;
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

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int rank, numProcesses;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);

    if (rank == 0)
    {
        printf("Hello from process %d\n", rank);
    }

    double startTime, endTime;
    startTime = MPI_Wtime();

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

    int localMinimumCost = minCost(graph, numVertices, source, destination);

    int globalMinimumCost;
    MPI_Reduce(&localMinimumCost, &globalMinimumCost, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    endTime = MPI_Wtime();
    double processingTime;
    MPI_Reduce(&endTime, &processingTime, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Processing time: %f seconds\n", processingTime);

        if (globalMinimumCost == -1)
        {
            printf("Negative cycle detected. No feasible solution exists.\n");
        }
        else
        {
            printf("Minimum cost of transportation: %d\n", globalMinimumCost);
        }
    }

    for (i = 0; i < numVertices; ++i)
    {
        free(graph[i]);
    }
    free(graph);

    MPI_Finalize();

    return 0;
}
