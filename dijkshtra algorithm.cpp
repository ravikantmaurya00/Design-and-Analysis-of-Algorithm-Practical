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

// Function to find the shortest path from the source node to all other nodes using Dijkstra's algorithm
vector<int> dijkstra(const vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max()); // Initialize distances to all nodes as infinity
    dist[source] = 0; // Distance from source to itself is 0

    // Priority queue to store vertices that are being processed
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // Insert source node with distance 0

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Iterate through all adjacent vertices of u
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // If there is a shorter path to v through u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
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
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    // Find the shortest paths from the source node
    vector<int> shortestPaths = dijkstra(graph, source);

    cout << "Shortest distances from node " << source << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (shortestPaths[i] == numeric_limits<int>::max()) {
            cout << "Node " << i << ": No path" << endl;
        } else {
            cout << "Node " << i << ": " << shortestPaths[i] << endl;
        }
    }

    return 0;
}
