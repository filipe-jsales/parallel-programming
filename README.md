# parallel-programming


In this example, we have a graph representing a transportation network. Each vertex in the graph represents a location, and each edge represents a route between two locations. The edge structure contains information about the destination, capacity (the maximum number of items that can be transported on that route), and cost (the cost of transporting one item on that route).

The minCost function implements the Bellman-Ford algorithm to find the minimum cost of transporting items from a source location to a destination location. It iterates through the graph multiple times, relaxing the edges to update the distance and previous vertex arrays. After finding the shortest path, it checks for negative cycles and calculates the minimum cost based on the path.

In the main function, we create a sample transportation network with four locations and add edges to represent routes. We specify the source and destination locations and call the minCost function to obtain the minimum cost of transportation. Finally, we print the result.


## Usage Example:

Output:
```
Vertex 0: (4, 1, 5) 
Vertex 1: 
Vertex 2: (4, 4, 5) (4, 9, 1) 
Vertex 3: (3, 10, 4) (4, 1, 10) 
Vertex 4: (3, 5, 1) 
Minimum cost of transportation: 5
```

This line indicates the outgoing edges from Vertex 0. In this case, Vertex 0 has an edge pointing to Vertex 4 with a capacity of 1 and a cost of 5:
```
Vertex 0: (4, 1, 5)
```

This line indicates that Vertex 1 does not have any outgoing edges:
```
Vertex 1:
```

This line indicates the outgoing edges from Vertex 2. Vertex 2 has two edges. One edge points to Vertex 4 with a capacity of 4 and a cost of 5. The other edge also points to Vertex 4 but with a capacity of 9 and a cost of 1:
```
Vertex 2: (4, 4, 5) (4, 9, 1)
```

This line indicates the outgoing edges from Vertex 3. Vertex 3 has two edges. One edge points to Vertex 3 (a self-loop) with a capacity of 10 and a cost of 4. The other edge points to Vertex 4 with a capacity of 1 and a cost of 10:
```
Vertex 3: (3, 10, 4) (4, 1, 10)
```

This line indicates the outgoing edge from Vertex 4. Vertex 4 has an edge pointing to Vertex 3 with a capacity of 5 and a cost of 1:
```
Vertex 4: (3, 5, 1)
```

Output:
```
Minimum cost of transportation: 5
```

This line indicates the minimum cost of transportation from the source (Vertex 0) to the destination (Vertex 4) in the given graph. In this case, the minimum cost is 5.
