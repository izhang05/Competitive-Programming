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

const long long inf = 1e18;


int main() {
    setIO();

    int n, m, q;
    cin >> n >> m >> q;
    long long dist[n][n];
    vector<pair<int, int> > adj[n];
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = inf;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (pair<int, int> j : adj[i]) {
            dist[i][j.first] = min(dist[i][j.first], (long long) j.second);
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        --a, --b;
        cout << (dist[a][b] != inf ? dist[a][b] : -1) << "\n";
    }
    return 0;
}
