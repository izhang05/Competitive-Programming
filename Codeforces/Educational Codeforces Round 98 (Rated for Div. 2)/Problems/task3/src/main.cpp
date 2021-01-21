#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sol = 0, n = s.size(), a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++a;
            } else if (s[i] == '[') {
                ++b;
            } else if (s[i] == ')') {
                if (a > 0) {
                    ++sol;
                    --a;
                } else {
                    a = 0;
                }
            } else {
                if (b > 0) {
                    ++sol;
                    --b;
                } else {
                    b = 0;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
