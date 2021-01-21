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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 102, inf = 0x3f3f3f3f;
int grid[maxn][maxn], n;
bool visited[maxn][maxn];

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

void dfs(int x, int y, int lim) {
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] <= lim) {
            dfs(nx, ny, lim);
        }
    }
}

int main() {
    setIO();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    int l = 0, h = 1e9, m, sol = -1;
    while (l <= h) {
        m = (l + h) / 2;
        memset(visited, 0, sizeof(visited));
        dfs(0, 0, m);
        if (visited[n - 1][n - 1]) {
            sol = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}
