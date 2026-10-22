#include <bits/stdc++.h>
using namespace std;

#define fastio()                                                                                   \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL)
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    // Write your solution here
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 0; u < n; u++) {
        cout << u << " -> ";

        for (int v : adj[u]) {
            cout << v << " ";
        }

        cout << '\n';
    }
}

int main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
