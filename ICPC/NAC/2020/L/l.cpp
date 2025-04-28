#include<bits/stdc++.h>

using namespace std;

const int mxn = 505;

char grid[mxn][mxn];
int n, m;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool garg(char c) {
    return c == 0 || c == 1;
}

bool obs(char c) {
    return c == '#';
}

map<pair<int, int>, int> ind;
pair<int, int> ind_to_garg[mxn * mxn];
set<int> val[mxn * mxn];

pair<pair<int, int>, int> next(int x, int y, int dir) {
    int nx = x + dx[dir], ny = y + dy[dir];
    // mirror reflects
    if (!valid(nx, ny)) {
        return {{x, y}, dir ^ 1};
    }
    char cur = grid[nx][ny];
    if (obs(cur) || garg(cur)) {
        return {{nx, ny}, dir};
    }
    int n_dir;
    if (cur == '/') {
        if (dir == 1) {
            n_dir = 2;
        } else if (dir == 2) {
            n_dir = 1;
        } else if (dir == 0) {
            n_dir = 3;
        } else {
            n_dir = 0;
        }
    }
    if (cur == '\\') {
        if (dir == 2) {
            n_dir = 3;
        } else if (dir == 3) {
            n_dir = 2;
        } else if (dir == 1) {
            n_dir = 0;
        } else {
            n_dir = 1;
        }
    }
    return {{nx, ny}, n_dir};
}

pair<int, int> dfs1(int x, int y, int dir) {
    do {
        pair<pair<int, int>, int> res = next(x, y, dir);
        x = res.first.first, y = res.first.second, dir = res.second;
    } while (!garg(grid[x][y]) && !obs(grid[x][y]));

    if (obs(grid[x][y])) {
        return {-1, -1};
    }
    return {ind[{x, y}], dir};
}

bool vis[mxn * mxn];
int orient[mxn * mxn];
vector<pair<int, int>> adj[mxn * mxn];
vector<int> cur_nodes;
bool pos;

void dfs2(int v) {
    cur_nodes.push_back(v);
    vis[v] = true;
    for (auto &i: adj[v]) {
        if (!vis[i.first]) {
            dfs2(i.first);
        }
    }
}

void dfs3(int v) {
    for (auto &i: adj[v]) {
        if (orient[i.first] == -1) {
            if (i.second == 1) {
                orient[i.first] = orient[v];
            } else {
                orient[i.first] = 1 - orient[v];
            }
            dfs3(i.first);
        } else {
            if (i.second == 1 && orient[i.first] != orient[v]) {
                pos = false;
            }
            if (i.second == 0 && orient[i.first] == orient[v]) {
                pos = false;
            }
        }
    }
}


int main() {
    cin >> n >> m;
    int cur_ind = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = s[j];
            if (grid[i][j] == 'V' || grid[i][j] == 'H') {
                if (grid[i][j] == 'V') {
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = 1;
                }
                ind_to_garg[cur_ind] = {i, j};
                ind[{i, j}] = cur_ind++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c = grid[i][j];
            if (garg(c)) {
                for (int k = 0; k < 4; ++k) {
                    pair<int, int> cur = dfs1(i, j, k);
                    if (cur.first != -1) {
                        val[ind[{i, j}]].insert(k);
                        bool same = (k / 2) == (cur.second / 2);
                        adj[ind[{i, j}]].push_back({cur.first, (int) same});
                    }
                }
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i < cur_ind; ++i) {
        if (!vis[i]) {
            cur_nodes.clear();
            dfs2(i);
            int mn_cost = 1e9;
            for (int j = 0; j < 2; ++j) {
                pos = true;
                for (auto &k: cur_nodes) {
                    orient[k] = -1;
                }
                int cur = cur_nodes[0];
                orient[cur] = j;

                dfs3(cur);
                if (!pos) {
                    break;
                }

                int cur_cost = 0;
                for (auto &k: cur_nodes) {
                    pair<int, int> cur_garg = ind_to_garg[k];
                    if (orient[k] != grid[cur_garg.first][cur_garg.second]) {
                        ++cur_cost;
                    }
                }
                mn_cost = min(mn_cost, cur_cost);
            }
            sol += mn_cost;
        }
    }
    cout << (sol >= 1e9 ? -1 : sol) << "\n";
}