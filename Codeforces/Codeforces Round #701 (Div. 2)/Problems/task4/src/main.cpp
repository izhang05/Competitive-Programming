#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;
int grid[maxn][maxn], sol[maxn][maxn], n, m, good = 0;

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

set<int> p;

void dfs(int x, int y) {
    ++good;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny) && sol[nx][ny] && p.find(sol[nx][ny] - sol[x][y]) == p.end()) {
            sol[x][y] = 0;
            --good;
            return;
        }
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny) && !sol[nx][ny]) {
            for (int j : p) {
                int cur = j + sol[x][y];
                if (cur > 0 && cur <= 1e6) {
                    if (j >= grid[nx][ny] && j % grid[nx][ny] == 0) {
                        sol[nx][ny] = j;
                        dfs(nx, ny);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < 32; ++i) {
        p.insert(pow(i, 4));
        p.insert(-pow(i, 4));
    }
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    sol[0][0] = grid[0][0];
    for (int i = 1; i < 1e6; ++i) {
        if (i * grid[0][0] > 1e6) {
            break;
        }
        memset(sol, 0, sizeof(sol));
        good = 0;
        sol[0][0] = i * grid[0][0];
        dfs(0, 0);
        if (good == n * m) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
