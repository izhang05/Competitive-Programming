#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("3.in", "r", stdin);
#endif
}


vector<vector<int> > adj;
vector<bool> visited;
vector<int> c;
int curr_min;

void dfs(int current) {
    visited[current] = true;
    curr_min = min(curr_min, c[current]);
    for (int i : adj[current]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    c.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> c[i + 1];
    }
    adj.resize(n + 1);
    visited.resize(n + 1);
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long sol = 0;
    for (int i = 1; i < n + 1; ++i) {
        if (!visited[i]) {
            curr_min = c[i];
            dfs(i);
            sol += curr_min;
        }
    }
    cout << sol << "\n";
    return 0;
}
