/*
1. bfs can find the shortst path from starting node to any node with minimum number of edges
2. guarantee only for unweighted graph
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void shortestPath(int source, int destination, const vector<vector<int>> &adj) {
    int n = adj.size();

    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    queue<int> q;

    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[destination] == -1) {
        cout << "No path exists\n";
        return;
    }

    vector<int> path;

    for (int v = destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    cout << "Shortest distance: " << dist[destination] << '\n';

    cout << "Path: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << '\n';
}

int main() {
    int n = 6;

    vector<vector<int>> adj(n);

    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}, {3, 5}, {4, 5}};

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    shortestPath(0, 5, adj);

    return 0;
}
