#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}
const int maxn = 1000;
bool blocked[maxn][maxn], visited[maxn][maxn];

int n, m, num_comp;

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return;
    }
    if (blocked[x][y] || visited[x][y]) {
        return;
    }
    visited[x][y] = true;
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x, y + 1);
}

int main() {
    setIO();

    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '#') {
                blocked[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!blocked[i][j] && !visited[i][j]) {
                dfs(i, j);
                ++num_comp;
            }
        }
    }
    cout << num_comp << "\n";
    return 0;
}
