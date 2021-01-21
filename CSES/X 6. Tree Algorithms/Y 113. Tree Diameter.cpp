#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 2e5;
vector<int> adj[maxn];
int to_leaf[maxn], sol;
bool visited[maxn];

void dfs(int n) {
    int cur_leaf = 0;
    for (int i : adj[n]) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i);
            sol = max(sol, to_leaf[i] + 1 + cur_leaf);
            cur_leaf = max(cur_leaf, to_leaf[i] + 1);
        }
    }
    to_leaf[n] = cur_leaf;
}

int main() {
    setIO();

    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[0] = true;
    dfs(0);
    cout << sol << "\n";
    return 0;
}
