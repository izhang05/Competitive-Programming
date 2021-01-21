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

const int maxn = 1e5;
vector<int> adj[maxn];
bool visited[maxn];
int comp[maxn], c;


void dfs(int n) {
    visited[n] = true;
    comp[c] = n + 1;
    for (int i : adj[n]) {
        if (!visited[i]) {
            dfs(i);
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
            ++c;
        }
    }
    cout << c - 1 << "\n";
    for (int i = 0; i < c - 1; ++i) {
        cout << comp[i] << " " << comp[i + 1] << "\n";
    }
    return 0;
}
