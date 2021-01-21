/*
ID: izhang01
TASK: mootube
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
}

const int maxn = 5000;
vector<vector<pair<int, int> > > adj; // first = connected node, second = relevance
int n, q, k, v, sol;
bool visited[maxn];

void dfs(int node) {
    ++sol;
    if (node != v && adj[node].size() < 2) {
        return;
    }
    visited[node] = true;
    for (pair<int, int> i : adj[node]) {
        if (!visited[i.first] && i.second >= k) {
            dfs(i.first);
        }
    }
}


int main() {
    setIO();
    cin >> n >> q;
    int a, b, r;
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b >> r;
        --a, --b;
        adj[a].emplace_back(b, r);
        adj[b].emplace_back(a, r);
    }
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[j] = false;
        }
        cin >> k >> v;
        --v;
        sol = 0;
        dfs(v);
        cout << sol - 1 << endl;
    }
    return 0;
}
