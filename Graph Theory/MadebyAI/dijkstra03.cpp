#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Node {
    int id;
    std::vector<std::pair<int, int>> neighbors;

    Node(int id) : id(id) {}
};

class Graph {
public:
    Graph(int numNodes) : nodes(numNodes) {
        for (int i = 0; i < numNodes; ++i) {
            nodes[i] = new Node(i);
        }
    }

    void addEdge(int src, int dest, int weight) {
        nodes[src]->neighbors.push_back({dest, weight});
    }

    void dijkstra(int src) {
        std::vector<int> dist(nodes.size(), INT_MAX);
        dist[src] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : nodes[u]->neighbors) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < dist.size(); ++i) {
            std::cout << "Distance from node " << src << " to node " << i << ": " << dist[i] << std::endl;
        }
    }

private:
    std::vector<Node*> nodes;
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    g.dijkstra(0);

    return 0;
}