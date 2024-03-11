#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int id;
    int weight;
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<Node>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // Initialize distances to infinity
    vector<bool> visited(n, false); // Initialize visited array

    // Priority queue to store nodes with their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance of source node is 0
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Mark the current node as visited
        visited[u] = true;

        // Traverse all adjacent nodes of u
        for (const auto& node : graph[u]) {
            int v = node.id;
            int weight = node.weight;

            // If v is not visited and the distance to v through u is smaller than the current distance to v
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source node
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<Node>> graph(n);

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}
