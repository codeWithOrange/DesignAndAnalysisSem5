#include <iostream>
#include <vector>
using namespace std;
vector<int> LPS(string s) {
    int n = s.size();
    vector<int> lps(n, 0);
    for (int i = 0; i < n; i++) {
        for (int len = i; len >= 1; len--) {
            bool match = true;
            for (int j = 0; j < len; j++) {
                if (s[j] != s[i - len + 1 + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                lps[i] = len;
                break;
            }
        }
    }

    return lps;
}
int main() {
    string text = "angad kumar maurya";
    string pattern = "urya";
    vector<int> lps_array = LPS(text);
    for (int value : lps_array)
        cout << value << " ";
    return 0;
}
