#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int to;
    int weight;
};

// Function to find the minimum spanning tree using Prim's algorithm
vector<Edge> primMST(const vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<bool> visited(n, false); // Mark all vertices as not visited
    vector<Edge> minSpanningTree;   // Store the edges of the minimum spanning tree
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Insert the source node into the priority queue
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Mark u as visited
        visited[u] = true;

        // Add the minimum weight edge to the minimum spanning tree
        if (!minSpanningTree.empty() || visited[u]) {
            minSpanningTree.push_back({u, pq.top().first});
        }

        // Iterate through all adjacent vertices of u
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // If v is not visited and the weight of the edge (u, v) is less than the current minimum distance to v
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    return minSpanningTree;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Create a graph represented as an adjacency list
    vector<vector<Edge>> graph(n);

    cout << "Enter the edges and their weights (from, to, weight):" << endl;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight}); // Undirected graph
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    // Find the minimum spanning tree
    vector<Edge> minSpanningTree = primMST(graph, source);

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge& edge : minSpanningTree) {
        cout << edge.to << " - " << edge.weight << endl;
    }

    return 0;
}
