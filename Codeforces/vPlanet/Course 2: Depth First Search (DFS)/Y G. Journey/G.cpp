#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("2.in", "r", stdin);
#endif
}

vector<int> adj[100001];
bool visited[100001];
double sol;

void dfs(int node, int depth, double prob) {
    visited[node] = true;
    bool end = true;
    for (int i : adj[node]) {
        if (!visited[i]) {
            end = false;
            dfs(i, depth + 1, prob / ((double) adj[node].size() - 1));
        }
    }
    if (end) {
//        cout << node << " " << depth << " " << splits << "\n";
        sol += depth * prob;
    }
}


int main() {
    setIO();

    int n;
    cin >> n;
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited[1] = true;
    for (int i : adj[1]) {
        dfs(i, 1, 1.0 / ((int) adj[1].size()));
    }
    cout << setprecision(7) << sol << "\n";
    return 0;
}
