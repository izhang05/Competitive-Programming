
/*
ID: izhang01
TASK: island
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("island.in", "r", stdin);
    freopen("island.out", "w", stdout);
    freopen("island.out", "w", stderr);
}
//#define DEBUG
const int maxn = 55, maxi = 16;
char grid[maxn][maxn];

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, inf = 0x3f3f3f3f;

int parent[maxn * maxn], visited[maxn][maxn], dist[maxn][maxn], comp[maxn][maxn], di[maxi][maxi];
int dp[1 << maxi][maxi];

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        parent[xroot] = yroot;
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

int r, c;
bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < r && y < c;
}

int main() {
    setIO();
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < r * c + c; ++i) {
        parent[i] = i;
    }
    memset(comp, -1, sizeof(comp));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'X') {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (valid(ni, nj) && grid[ni][nj] == 'X') {
                        merge(i * c + j, ni * c + nj);
                    }
                }
            }
        }
    }
    int n = 0;
    map<int, int> ind;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'X') {
                int cur = get(i * c + j);
                if (ind.find(cur) == ind.end()) {
                    ind[cur] = n++;
                }
                comp[i][j] = ind[cur];
            }
        }
    }
#ifdef DEBUG
    cout << "n:\n";
    cout << n << "\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << comp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'X' && !visited[i][j]) {
                memset(dist, 0x3f, sizeof(dist));
                dist[i][j] = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                for (int k = 0; k < r; ++k) {
                    for (int l = 0; l < c; ++l) {
                        if (same(k * c + l, i * c + j)) {
                            visited[k][l] = true;
                            dist[k][l] = 0;
                            q.push({k, l});
                        }
                    }
                }
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nx = cur.first + dx[k], ny = cur.second + dy[k];
                        if (valid(nx, ny) && grid[nx][ny] != '.') {
                            int nex_dist = dist[cur.first][cur.second];
                            if (grid[nx][ny] == 'S') {
                                ++nex_dist;
                            }
                            if (dist[nx][ny] > nex_dist) {
                                dist[nx][ny] = nex_dist;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                vector<int> d(n, inf);
                for (int k = 0; k < r; ++k) {
                    for (int l = 0; l < c; ++l) {
                        if (grid[k][l] == 'X' && !same(k * c + l, i * c + j)) {
                            d[comp[k][l]] = min(d[comp[k][l]], dist[k][l]);
                        }
                    }
                }
                for (int k = 0; k < n; ++k) {
                    if (k != comp[i][j]) {
                        di[comp[i][j]][k] = d[k];
                    }
                }
            }
        }
    }
#ifdef DEBUG
    cout << "di:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << di[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        dp[(1 << i)][i] = 0;
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (dp[mask][i] == inf || !(mask & (1 << i))) {
                continue;
            }
#ifdef DEBUG
            cout << mask << " " << i << " " << dp[mask][i] << "\n";
#endif
            for (int j = 0; j < n; ++j) {
                if (!(mask & (1 << j))) {
                    dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + di[i][j]);
                }
            }
        }
    }
    int sol = inf;
    for (int i = 0; i < n; ++i) {
        sol = min(sol, dp[(1 << n) - 1][i]);
    }
    cout << sol << "\n";
    return 0;
}
