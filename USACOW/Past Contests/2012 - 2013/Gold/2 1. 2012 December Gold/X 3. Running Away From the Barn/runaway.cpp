/*
ID: izhang01
TASK: runaway
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("runaway.in", "r", stdin);
    freopen("runaway.out", "w", stdout);
    freopen("runaway.out", "w", stderr);
}
//#define DEBUG
const int maxn = 2e5 + 5;

vector<pair<int, int>> adj[maxn];
long long dist[maxn], sol[maxn], n, l;
priority_queue<long long> cur[maxn];

void dfs1(int c, int p, long long d) {
    dist[c] = d;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs1(i.first, c, d + i.second);
        }
    }
}

void dfs2(int c, int p) {
    cur[c].push(dist[c]);
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs2(i.first, c);
            if (cur[i.first].size() > cur[c].size()) {
                swap(cur[c], cur[i.first]);
            }
            while (!cur[i.first].empty()) {
                cur[c].push(cur[i.first].top());
                cur[i.first].pop();
            }
            while (!cur[c].empty() && cur[c].top() - dist[c] > l) {
                cur[c].pop();
            }
        }
    }
    sol[c] = cur[c].size();
}


int main() {
    setIO();
    cin >> n >> l;
    for (int i = 1; i < n; ++i) {
        int a, w;
        cin >> a >> w;
        --a;
        adj[a].emplace_back(i, w);
        adj[i].emplace_back(a, w);
    }
    dfs1(0, -1, 0);
    dfs2(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
