#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int capacity;
    int cost;
};

// Function to find the minimum cost using the Bellman-Ford algorithm
int minCost(vector<vector<Edge>>& graph, int source, int destination) {
    int numVertices = graph.size();
    vector<int> dist(numVertices, INT_MAX);
    vector<int> prev(numVertices, -1);
    
    dist[source] = 0;
    
    // Relax edges repeatedly
    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (const auto& edge : graph[u]) {
                int v = edge.destination;
                int capacity = edge.capacity;
                int cost = edge.cost;
                
                if (capacity > 0 && dist[u] != INT_MAX && dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    prev[v] = u;
                }
            }
        }
    }
    
    // Check for negative cycle
    for (int u = 0; u < numVertices; ++u) {
        for (const auto& edge : graph[u]) {
            int v = edge.destination;
            int capacity = edge.capacity;
            int cost = edge.cost;
            
            if (capacity > 0 && dist[u] != INT_MAX && dist[u] + cost < dist[v]) {
                return -1;  // Negative cycle exists
            }
        }
    }
    
    // Calculate the minimum cost
    int minCost = 0;
    int u = destination;
    
    while (prev[u] != -1) {
        for (auto& edge : graph[prev[u]]) {
            if (edge.destination == u) {
                edge.capacity--;
                minCost += edge.cost;
                break;
            }
        }
        
        u = prev[u];
    }
    
    return minCost;
}

int main() {
    // Example usage
    int numVertices = 5;
    vector<vector<Edge>> graph(numVertices);
    
    // Adding edges to the graph
    graph[0].push_back({1, 3, 2});
    graph[0].push_back({2, 2, 4});
    graph[1].push_back({2, 2, 1});
    graph[1].push_back({3, 3, 6});
    graph[2].push_back({3, 1, 3});
    graph[2].push_back({4, 2, 5});
    graph[3].push_back({4, 1, 2});
    
    int source = 0;
    int destination = 4;
    
    int minimumCost = minCost(graph, source, destination);
    
    if (minimumCost == -1) {
        cout << "Negative cycle detected. No feasible solution exists." << endl;
    } else {
        cout << "Minimum cost of transportation: " << minimumCost << endl;
    }
    
    return 0;
}
