/* Author: izhang05
 * Time: 09-29-2021 14:04:27
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[maxn][maxn];
int n, m, sol[maxn * maxn];
set<int> adj[maxn * maxn];

int ind(pair<int, int> x) {
    return m * x.first + x.second;
}

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int c) {
    for (auto &i : adj[c]) {
        if (sol[i] == -1) {
            sol[i] = 5 - sol[c];
            dfs(i);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sol[ind({i, j})] = -1;
            if (grid[i][j] == '.') {
                continue;
            }
            vector<pair<int, int>> cnt;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (valid(x, y)) {
                    if (grid[x][y] == '.') {
                        cnt.emplace_back(x, y);
                    }
                }
            }
            if (int(cnt.size()) % 2 == 1) {
                cout << "NO\n";
                return;
            }
            for (int k = 0; k < int(cnt.size()); k += 2) {
                adj[ind(cnt[k + 0])].insert(ind(cnt[k + 1]));
                adj[ind(cnt[k + 1])].insert(ind(cnt[k + 0]));
            }
        }
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && sol[ind({i, j})] == -1) {
                sol[ind({i, j})] = 1;
                dfs(ind({i, j}));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'X') {
                int cur = ind({i, j});
                sol[cur] = 0;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (valid(x, y)) {
                        if (grid[x][y] == '.') {
                            sol[cur] += sol[ind({x, y})];
                        }
                    }
                }
            }
            cout << sol[ind({i, j})] << " \n"[j == m - 1];
        }
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
