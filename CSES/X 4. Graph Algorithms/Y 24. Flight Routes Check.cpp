#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;
vector<int> adj[maxn][2];
bool visited[maxn];

void dfs(int n, int dir) {
    // dir = 0 -> original graph, dir = 1 -> reversed graph
    visited[n] = true;
    for (int i : adj[n][dir]) {
        if (!visited[i]) {
            dfs(i, dir);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a); // adjacency list with reversed edges
    }
    dfs(0, 0); // first criteria
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << 1 << " " << i + 1 << "\n"; // node 1 cannot reach node i + 1
            return 0;
        }
    }
//    for (int i = 0; i < n; ++i) {
//        visited[i] = false;
//    }
    memset(visited, false, sizeof(visited)); // set every element in visited to false (same thing as above)
    dfs(0, 1);                               // second criteria
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << i + 1 << " " << 1 << "\n"; // node i + 1 cannot reach node 1
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
