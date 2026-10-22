#include <iostream>
using namespace std;
int bruteForce(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m)
            return i;
    }

    return -1;
}

int main() {
    string text = "angad kumar maurya";
    int ans = bruteForce(text, "rya");
    cout << ans << endl;
    return 0;
}
