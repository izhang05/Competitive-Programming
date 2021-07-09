/*
ID: izhang01
TASK: brute_yinyang
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("yinyang.in", "r", stdin);
    freopen("brute_yinyang.out", "w", stdout);
    freopen("brute_yinyang.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e5 + 5;
vector<pair<int, int>> adj[maxn];
set<pair<int, int>> sol;
vector<int> occ;

void dfs(int c, int p, bool add, int w) {
    if (w == 0) {
        if (add) {
            for (auto &i : occ) {
                sol.insert({min(c, i), max(c, i)});
            }
        } else {
            occ.push_back(c);
        }
    }
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c, add, w + i.second);
        }
    }
}

void solve(int c, int p) {
    occ.clear();
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c, true, i.second);
            dfs(i.first, c, false, i.second);
        }
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        if (c == 0) {
            c = -1;
        }
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    for (int i = 0; i < n; ++i) {
        solve(i, -1);
    }
    cout << sol.size() << "\n";
    return 0;
}
