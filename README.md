# parallel-programming


In this example, we have a graph representing a transportation network. Each vertex in the graph represents a location, and each edge represents a route between two locations. The edge structure contains information about the destination, capacity (the maximum number of items that can be transported on that route), and cost (the cost of transporting one item on that route).

The minCost function implements the Bellman-Ford algorithm to find the minimum cost of transporting items from a source location to a destination location. It iterates through the graph multiple times, relaxing the edges to update the distance and previous vertex arrays. After finding the shortest path, it checks for negative cycles and calculates the minimum cost based on the path.

In the main function, we create a sample transportation network with four locations and add edges to represent routes. We specify the source and destination locations and call the minCost function to obtain the minimum cost of transportation. Finally, we print the result.
