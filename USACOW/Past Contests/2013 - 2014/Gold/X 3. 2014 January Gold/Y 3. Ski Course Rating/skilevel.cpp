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
int grid[maxn][maxn], cost[maxn][maxn], size[maxn][maxn];
pair<int, int> parent[maxn][maxn];
vector<pair<int, int>> children[maxn][maxn];
bool starting[maxn][maxn];

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


pair<int, int> get(pair<int, int> x) {
    return parent[x.first][x.second] == x ? x : parent[x.first][x.second] = get(parent[x.first][x.second]);
}

int dist(pair<int, int> x, pair<int, int> y) {
    return abs(grid[x.first][x.second] - grid[y.first][y.second]);
}

bool merge(pair<int, int> x, pair<int, int> y) {
    pair<int, int> xroot = get(x), yroot = get(y);
    if (size[xroot.first][xroot.second] > size[yroot.first][yroot.second]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        parent[xroot.first][xroot.second] = yroot;
        size[yroot.first][yroot.second] += size[xroot.first][xroot.second];
        children[yroot.first][yroot.second].insert(children[yroot.first][yroot.second].end(), children[xroot.first][xroot.second].begin(), children[xroot.first][xroot.second].end());
//        cost[yroot.first][yroot.second] = dist(x, y);
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
            cin >> starting[i][j];
            parent[i][j] = {i, j};
            size[i][j] = 1;
            if (starting[i][j]) {
                children[i][j].emplace_back(i, j);
            }
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
            if (size[xroot.first][xroot.second] >= t) {
//                cout << c << " " << x.first << " " << x.second << "\n";
                sol += c * (long long) children[xroot.first][xroot.second].size();
                children[xroot.first][xroot.second].clear();
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
