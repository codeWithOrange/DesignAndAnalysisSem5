#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string text, string pattern) {

    int n = text.length();
    int m = pattern.length();

    // Pattern text se bada hai
    if (m > n) {
        return;
    }

    const int d = 256;   // number/base of characters
    const int q = 101;   // prime modulus

    int patternHash = 0;
    int textHash = 0;

    int h = 1;

    // h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate initial pattern and text window hash
    for (int i = 0; i < m; i++) {

        patternHash =
            (d * patternHash + pattern[i]) % q;

        textHash =
            (d * textHash + text[i]) % q;
    }

    // Slide pattern over text
    for (int i = 0; i <= n - m; i++) {

        // Hashes are same
        if (patternHash == textHash) {

            bool match = true;

            // Verify actual characters
            for (int j = 0; j < m; j++) {

                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                cout << "Pattern found at index "
                     << i << endl;
            }
        }

        // Calculate hash of next window
        if (i < n - m) {

            textHash =
                (d * (textHash - text[i] * h)
                 + text[i + m]) % q;

            // Make hash positive
            if (textHash < 0) {
                textHash += q;
            }
        }
    }
}

int main() {

    string text = "angad kumar maurya";
    string pattern = "rya";

    rabinKarp(text, pattern);

    return 0;
}
