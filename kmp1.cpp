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

void kmp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int i = 0;
    int j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (i == m) { // pattern printing
            cout << i - j;
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = LPS(text)[j - 1];
            } else {
                i++;
            }
        }
    }
}
int main() {
    string text = "angad kumar maurya";
    string pattern = "urya";

    kmp(text, pattern);
    return 0;
}
