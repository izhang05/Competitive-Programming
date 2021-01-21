/*
ID: izhang01
TASK: typo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("typo.in", "r", stdin);
    freopen("typo.out", "w", stdout);
    string s;
    cin >> s;
    if (s.size() % 2 == 1) {
        cout << 0 << "\n";
    } else {
        int depth = 0;
        int open = 0, close = 0, sol;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++depth;
                ++open;
            } else {
                --depth;
                ++close;
            }
            if (depth <= 1) {
                open = 0;
            }
            if (depth == -1) {
                sol = close;
            }
        }
        if (depth > 0) {
            sol = open;
        }
        cout << sol << "\n";
    }
    return 0;
}
