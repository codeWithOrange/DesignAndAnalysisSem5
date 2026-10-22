#include <iostream>
using namespace std;
int main() {
    int n = 5;
    int matrix[5][5] = {};
    // A = 0 , B = 1, C = 2 , D = 3 , E = 4
    int edges[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
