#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    for (int u = 0; u < n; u++) {
        cout << char('A' + u) << ": ";
        for (int v : adj[u]) {
            cout << char('A' + v) << " ";
        }
        cout << endl;
    }

    return 0;
}
