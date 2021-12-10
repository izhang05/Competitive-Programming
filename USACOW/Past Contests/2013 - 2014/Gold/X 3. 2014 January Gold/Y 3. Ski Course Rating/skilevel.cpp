/*
ID: izhang01
TASK: skilevel
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("skilevel.in", "r", stdin);
#ifndef LOCAL
    freopen("skilevel.out", "w", stdout);
#endif
}
const int maxn = 505, inf = 0x3f3f3f3f;
int grid[maxn][maxn], cost[maxn][maxn], sz[maxn][maxn];
pair<int, int> parent[maxn][maxn];
int num_start[maxn][maxn];

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


pair<int, int> get(pair<int, int> x) {
    return parent[x.first][x.second] == x ? x : parent[x.first][x.second] = get(parent[x.first][x.second]);
}

int dist(pair<int, int> x, pair<int, int> y) {
    return abs(grid[x.first][x.second] - grid[y.first][y.second]);
}

bool merge(pair<int, int> x, pair<int, int> y) {
    pair<int, int> xroot = get(x), yroot = get(y);
    if (sz[xroot.first][xroot.second] > sz[yroot.first][yroot.second]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        parent[xroot.first][xroot.second] = yroot;
        sz[yroot.first][yroot.second] += sz[xroot.first][xroot.second];
        num_start[yroot.first][yroot.second] += num_start[xroot.first][xroot.second];
        return true;
    }
    return false;
}

bool same(pair<int, int> x, pair<int, int> y) {
    return get(x) == get(y);
}
int n, m, t;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    setIO();
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> num_start[i][j];
            parent[i][j] = {i, j};
            sz[i][j] = 1;
        }
    }
    set<pair<int, pair<pair<int, int>, pair<int, int>>>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 2; ++k) {
                int next_i = i + dx[k], next_j = j + dy[k];
                if (valid(next_i, next_j)) {
                    pair<int, int> next = {next_i, next_j};
                    edges.insert({dist({i, j}, {next}), {{i, j}, next}});
                }
            }
        }
    }
    long long sol = 0;
    for (pair<int, pair<pair<int, int>, pair<int, int>>> i : edges) {
        int c = i.first;
        pair<int, int> x = i.second.first, y = i.second.second;
        if (merge(x, y)) {
            pair<int, int> xroot = get(x);
            if (sz[xroot.first][xroot.second] >= t) {
                sol += c * (long long) num_start[xroot.first][xroot.second];
                num_start[xroot.first][xroot.second] = 0;
            }
        }
    }

    cout << sol << "\n";
    return 0;
}
