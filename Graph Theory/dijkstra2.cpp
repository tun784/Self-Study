#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a node and its distance from the source
struct Node {
    int id;
    int distance;
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();

    // Create a vector to store the distances from the source
    vector<int> distances(n, INT_MAX);

    // Create a priority queue to store the nodes and their distances
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Set the distance of the source node to 0 and push it into the priority queue
    distances[source] = 0;
    pq.push({source, 0});

    while (!pq.empty()) {
        // Get the node with the minimum distance from the priority queue
        Node curr = pq.top();
        pq.pop();

        int u = curr.id;
        int dist = curr.distance;

        // If the current distance is greater than the stored distance, skip it
        if (dist > distances[u]) {
            continue;
        }

        // Traverse the neighbors of the current node
        for (int v = 0; v < n; v++) {
            // If there is an edge from u to v and the total distance is smaller, update the distance
            if (graph[u][v] != 0 && dist + graph[u][v] < distances[v]) {
                distances[v] = dist + graph[u][v];
                pq.push({v, distances[v]});
            }
        }
    }

    // Print the distances from the source node
    cout << "Shortest distances from the source node:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }
}

int main() {
    // Create a graph (adjacency matrix)
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    int source = 0; // Source node

    // Run Dijkstra's algorithm
    dijkstra(graph, source);

    return 0;
}