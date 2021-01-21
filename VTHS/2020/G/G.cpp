#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[5] = {1, 0, -1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}
const int maxn = 32, inf = 0x3f3f3f3f;
int dp[maxn][maxn][maxn][maxn], n, m, r;
bool visited[maxn][maxn][maxn][maxn];
char grid[maxn][maxn];
pair<int, int> e;

bool valid(pair<int, int> x) {
    return x.first >= 0 && x.second >= 0 && x.first < n && x.second < m && grid[x.first][x.second] != 'X';
}

int sol(pair<int, int> p, pair<int, int> c) {
    if (visited[p.first][p.second][c.first][c.second]) {
        return dp[p.first][p.second][c.first][c.second];
    }
    if (abs(p.first - c.first) <= r && abs(p.second - c.second) <= r) {
        return inf;
    }
    if (p == e) {
        return dp[p.first][p.second][c.first][c.second] = 0;
    }
    if (p.first == 2 && p.second == 0) {
        cout << "hi"
             << "\n";
    }
    visited[p.first][p.second][c.first][c.second] = true;

    int &res = dp[p.first][p.second][c.first][c.second];
    for (int i = 0; i < 5; ++i) {
        pair<int, int> next_p = make_pair(p.first + dx[i], p.second + dy[i]);
        if (valid(next_p)) {
            pair<int, int> next_c = c;
            int dist_y = abs(c.first - p.first), dist_x = abs(c.second - p.second);
            if (dist_y >= dist_x) {
                if (valid(make_pair(c.first + (c.first > p.first ? -1 : 1), c.second))) {
                    next_c = make_pair(c.first + (c.first > p.first ? -1 : 1), c.second);
                } else if (valid(make_pair(c.first, c.second + (c.second > p.second ? -1 : 1)))) {
                    next_c = make_pair(c.first, c.second + (c.second > p.second ? -1 : 1));
                }
            } else {
                if (valid(make_pair(c.first, c.second + (c.second > p.second ? -1 : 1)))) {
                    next_c = make_pair(c.first, c.second + (c.second > p.second ? -1 : 1));

                } else if (valid(make_pair(c.first + (c.first > p.first ? -1 : 1), c.second))) {
                    next_c = make_pair(c.first + (c.first > p.first ? -1 : 1), c.second);
                }
            }
            res = min(res, sol(next_p, next_c) + 1);
        }
    }
    visited[p.first][p.second][c.first][c.second] = false;

    return res;
}

int main() {
    setIO();
    pair<int, int> p, c;
    cin >> n >> m >> r;
    memset(dp, 0x3f, sizeof(dp));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'E') {
                e = make_pair(i, j);
            } else if (grid[i][j] == 'P') {
                p = make_pair(i, j);
            } else if (grid[i][j] == 'C') {
                c = make_pair(i, j);
            }
        }
    }
    int res = sol(p, c);
    //    vector<vector<int>> path(res + 1, vector<int>(4));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < m; ++l) {
                    if (dp[i][j][k][l] != inf) {
                        //                        path[dp[i][j][k][l]] = vector<int>{i, j, k, l};
                        cout << i << " " << j << " " << k << " " << l << " " << dp[i][j][k][l] << "\n";
                    }
                }
            }
        }
    }
    //    for (int i = res; i >= 0; --i) {
    //        cout << i << ": ";
    //        print(path[i]);
    //    }
    //    cout << e.first << " " << e.second << "\n";
    if (res == inf) {
        cout << "you're toast"
             << "\n";
    } else {
        cout << res << "\n";
    }
    return 0;
}
