/*
ID: izhang01
TASK: lightson
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
}

const int maxn = 100;
int n, m;
bool visited[maxn][maxn];
bool on[maxn][maxn];
int c;
vector<pair<int, int> > adj[maxn][maxn];
vector<pair<int, int> > light[maxn][maxn];
set<pair<int, int> > skipped;

void start_dfs(int x, int y) {
    visited[node][dist] = true;
    for (pair<int, int> i : light[node][dist]) {
        if (!on[i.first][i.second]) {
            on[i.first][i.second] = true;
            if (skipped.find(i) != skipped.end()) {
                skipped.erase(i);
                start_dfs(i.first, i.second);
            }
        }
    }
    for (pair<int, int> i : adj[node][dist]) {
        if (!visited[i.first][i.second]) {
            if (on[i.first][i.second]) {
                start_dfs(i.first, i.second);
            } else {
                skipped.insert(i);
            }
        }
    }
}

int main() {
    setIO();
    cin >> n >> m;
    int x, y, a, b;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> a >> b;
        --x, --y, --a, --b;
        light[x][y].emplace_back(a, b);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adj[i][j].emplace_back(max(0, i - 1), j);
            adj[i][j].emplace_back(i, max(0, j - 1));
            adj[i][j].emplace_back(min(n - 1, i + 1), j);
            adj[i][j].emplace_back(i, min(n - 1, j + 1));
        }
    }
    on[0][0] = true;
    start_dfs(0, 0);
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (on[i][j]) {
                ++sol;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
