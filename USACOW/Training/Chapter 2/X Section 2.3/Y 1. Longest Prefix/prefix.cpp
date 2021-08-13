/*
ID: izhang01
TASK: prefix
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    freopen("prefix.out", "w", stderr);
}
//#define DEBUG
const int maxn = 2e5 + 5;

bool dp[maxn];

int main() {
    setIO();
    vector<string> p;
    string cur;
    while (true) {
        cin >> cur;
        if (cur == ".") {
            break;
        }
        p.push_back(cur);
    }
    string s = " ";
    while (cin >> cur) {
        s = s + cur;
    }
    int n = (int) s.size();
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        if (!dp[i]) {
            continue;
        }
        for (auto &j : p) {
            if (i + (int) j.size() < n && s.substr(i + 1, j.size()) == j) {
                dp[i + j.size()] = true;
            }
        }
    }
    for (int i = n; i >= 0; --i) {
        if (dp[i]) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
