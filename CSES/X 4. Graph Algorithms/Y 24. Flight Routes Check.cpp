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
vector<int> adj[maxn][2];
bool visited[maxn];

void dfs(int n, int dir) {
    visited[n] = true;
    for (int i : adj[n][dir]) {
        if (!visited[i]) {
            dfs(i, dir);
        }
    }
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    dfs(0, 0);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << 1 << " " << i + 1 << "\n";
            return 0;
        }
    }
    memset(visited, false, sizeof(visited));
    dfs(0, 1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << i + 1 << " " << 1 << "\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
