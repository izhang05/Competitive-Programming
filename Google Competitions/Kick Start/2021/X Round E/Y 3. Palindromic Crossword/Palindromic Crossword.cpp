#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 1005;
char grid[maxn][maxn];

int par[maxn * maxn], depth[maxn * maxn];
char val[maxn * maxn];

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

int ind(int x, int y) {
    return x * m + y;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n * m; ++i) {
        par[i] = i;
        depth[i] = 0;
        val[i] = '0';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int pre = -1;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                for (int l = pre + 1, r = j - 1; l < r; ++l, --r) {
                    merge(ind(i, l), ind(i, r));
                }
                pre = j;
            }
        }
        for (int l = pre + 1, r = m - 1; l < r; ++l, --r) {
            merge(ind(i, l), ind(i, r));
        }
    }
    for (int j = 0; j < m; ++j) {
        int pre = -1;
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] == '#') {
                for (int l = pre + 1, r = i - 1; l < r; ++l, --r) {
                    merge(ind(l, j), ind(r, j));
                }
                pre = i;
            }
        }
        for (int l = pre + 1, r = n - 1; l < r; ++l, --r) {
            merge(ind(l, j), ind(r, j));
        }
    }
    int fill = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                val[get(ind(i, j))] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (val[get(ind(i, j))] != '0') {
                if (grid[i][j] == '.') {
                    ++fill;
                    grid[i][j] = val[get(ind(i, j))];
                }
            }
        }
    }

    cout << fill << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
