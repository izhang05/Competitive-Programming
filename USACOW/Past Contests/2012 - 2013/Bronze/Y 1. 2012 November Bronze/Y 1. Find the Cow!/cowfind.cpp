/*
ID: izhang01
TASK: cowfind
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cowfind.in", "r", stdin);
    freopen("cowfind.out", "w", stdout);
    string s;
    cin >> s;
    int sol = 0, right = 0;
    char cur = s[s.size() - 1];
    for (int i = (int) s.size() - 2; i >= 0; --i) {
        if (cur == ')') {
            if (s[i] == ')') {
                ++right;
            } else {
                cur = '(';
            }
        } else {
            if (s[i] == '(') {
                sol += right;
            } else {
                cur = ')';
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
