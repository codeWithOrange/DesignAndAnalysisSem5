#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5},
    };
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "BFS traversal: ";
    bfs(5, adj);
    cout << endl;

    return 0;
}

/*
time: O(v+e)
space: O(v)

*/
