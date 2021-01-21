/*
ID: izhang01
TASK: castle
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
}

const int maxn = 50;
vector<pair<int, int> > adj[maxn][maxn];
int grid[maxn][maxn], n, m, num_comp = 0, comp[maxn][maxn];
vector<int> size_comp(maxn * maxn);
bool visited[maxn][maxn];
pair<int, int> parent[maxn][maxn];

pair<int, int> get(int x, int y) {
    return parent[x][y] == pair<int, int>{x, y} ? parent[x][y] : parent[x][y] = get(x, y);
}

void dfs(int x, int y) {
    visited[x][y] = true;
    comp[x][y] = num_comp;
    ++size_comp[num_comp];
    for (pair<int, int> i : adj[x][y]) {
        if (!visited[i.first][i.second]) {
            dfs(i.first, i.second);
        }
    }
}


int main() {
    setIO();
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            // don't have to check for out of bounds because there will be a wall at edges
            if (!(grid[i][j] & 8)) { // south
                adj[i][j].emplace_back(i + 1, j);
                adj[i + 1][j].emplace_back(i, j);
            }
            if (!(grid[i][j] & 4)) { // east
                adj[i][j].emplace_back(i, j + 1);
                adj[i][j + 1].emplace_back(i, j);
            }
            if (!(grid[i][j] & 2)) { // north
                adj[i][j].emplace_back(i - 1, j);
                adj[i - 1][j].emplace_back(i, j);
            }
            if (!(grid[i][j] & 1)) { // west
                adj[i][j].emplace_back(i, j - 1);
                adj[i][j - 1].emplace_back(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                dfs(i, j);
                ++num_comp;
            }
        }
    }
    cout << num_comp << endl;
    cout << *max_element(size_comp.begin(), size_comp.end()) << endl;
    pair<int, vector<int> > sol = make_pair(0, vector<int>{});
    for (int j = 0; j < m; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            if (i > 0 && comp[i][j] != comp[i - 1][j] &&
                size_comp[comp[i][j]] + size_comp[comp[i - 1][j]] > sol.first) {
                int cur = size_comp[comp[i][j]] + size_comp[comp[i - 1][j]];
                sol = make_pair(cur, vector<int>{i + 1, j + 1, 0});
            }
            if (j < m - 1 && comp[i][j] != comp[i][j + 1] &&
                size_comp[comp[i][j]] + size_comp[comp[i][j + 1]] > sol.first) {
                int cur = size_comp[comp[i][j]] + size_comp[comp[i][j + 1]];
                sol = make_pair(cur, vector<int>{i + 1, j + 1, 1});
            }
        }
    }
    cout << sol.first << "\n";
    cout << sol.second[0] << " " << sol.second[1] << " " << (sol.second[2] == 0 ? "N" : "E") << "\n";
    return 0;
}
