#include <bits/stdc++.h>

using namespace std;

int n, m;
const int mxn = 1e5 + 5;
vector<int> adj[mxn];

int color[mxn];


void dfs(int v, int col) {
    color[v] = col;
    for (auto &i: adj[v]) {
        if (color[i] == -1) {
            dfs(i, col ^ 1);
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            dfs(i, 0);
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (auto &j: adj[i]) {
            if (color[i] == color[j]) {
                --sol;
            }
        }
    }
    sol /= 2;
    cout << sol + m + 1 << "\n";
}
