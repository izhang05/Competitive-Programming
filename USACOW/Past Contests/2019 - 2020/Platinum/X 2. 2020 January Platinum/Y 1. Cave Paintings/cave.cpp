/*
ID: izhang01
TASK: cave
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("cave.in", "r", stdin);
    freopen("cave.out", "w", stdout);
    freopen("cave.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e3 + 5, mod = 1e9 + 7;
char grid[maxn][maxn];
int ind[maxn][maxn];
set<int> adj[maxn * maxn];
int par[maxn * maxn], depth[maxn * maxn];
bool top[maxn * maxn];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        par[xroot] = yroot;
        depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}
int n, m;

int get_ind(int x, int y) {
    return x * m + y;
}

const int dx[]{-1, 0}, dy[]{0, -1};

long long dp[maxn * maxn];

void dfs(int c, int p) {
    dp[c] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            dp[c] *= dp[i];
            dp[c] %= mod;
        }
    }
    ++dp[c];
    dp[c] %= mod;
}


int main() {
    setIO();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[n - i - 1][j] = s[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            par[get_ind(i, j)] = get_ind(i, j);
            depth[get_ind(i, j)] = 1;
        }
    }
    memset(ind, -1, sizeof(ind));
    memset(top, true, sizeof(top));
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                continue;
            }
            for (int k = 0; k < 2; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (grid[nx][ny] == '.') {
                    merge(get_ind(i, j), get_ind(nx, ny));
                }
            }
        }
        map<int, int> comp_ind;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                continue;
            }
            int cur_comp = get(get_ind(i, j));
            if (comp_ind.find(cur_comp) == comp_ind.end()) {
                comp_ind[cur_comp] = cur++;
            }
            ind[i][j] = comp_ind[cur_comp];
            for (int k = 0; k < 1; ++k) {
                int nx = i + dx[k], ny = j + dy[k]0;
                if (grid[nx][ny] == '.') {
                    adj[comp_ind[cur_comp]].insert(ind[nx][ny]);
                    top[ind[nx][ny]] = false;
                }
            }
        }
    }
    for (int i = 0; i < cur; ++i) {
        if (top[i]) {
            adj[cur].insert(i);
        }
    }
    dfs(cur, -1);
    cout << dp[cur] - 1 << "\n";
    return 0;
}
