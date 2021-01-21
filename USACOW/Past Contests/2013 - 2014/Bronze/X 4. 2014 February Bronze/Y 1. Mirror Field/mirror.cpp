/*
ID: izhang01
TASK: mirror
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mirror.in", "r", stdin);
    freopen("mirror.out", "w", stdout);
}

const int maxn = 1000;
char grid[maxn][maxn];
bool visited[maxn][maxn];
int sol;
int n, m;

void dfs(int x, int y, int len, char dir) {
    visited[x][y] = true;
    if (dir == 'D') {
        if (grid[x][y] == '/') {
            if (y == 0) {
                sol = max(sol, len);
//                cout << x << " " << y << " " << sol << "\n";
                return;
            }
            dfs(x, y - 1, len + 1, 'L');
        } else {
            if (y == m - 1) {
                sol = max(sol, len);
//                cout << x << " " << y << " " << sol << "\n";
                return;
            }
            dfs(x, y + 1, len + 1, 'R');
        }
    } else if (dir == 'R') {
        if (grid[x][y] == '/') {
            if (x == 0) {
                sol = max(sol, len);
//                cout << x << " " << y << " " << sol << "\n";
                return;
            }
            dfs(x - 1, y, len + 1, 'U');
        } else {
            if (x == n - 1) {
                sol = max(sol, len);
//                cout << x << " " << y << " " << sol << "\n";
                return;
            }
            dfs(x + 1, y, len + 1, 'D');
        }
    } else if (dir == 'U') {
        if (grid[x][y] == '/') {
            if (y == m - 1) {
                sol = max(sol, len);
//                cout << x << " " << y << " " << sol << "\n";
                return;
            }
            dfs(x, y + 1, len + 1, 'R');
        } else {
            if (y == 0) {
                sol = max(sol, len);
//                cout << x << " " << y << " " << sol << "\n";
                return;
            }
            dfs(x, y - 1, len + 1, 'L');
        }
    } else {
        if (grid[x][y] == '/') {
            if (x == n - 1) {
                sol = max(sol, len);
//                cout << x << " " << y << " " << sol << "\n";
                return;
            }
            dfs(x + 1, y, len + 1, 'D');
        } else {
            if (x == 0) {
                sol = max(sol, len);
//                cout << x << " " << y << " " << sol << "\n";
                return;
            }
            dfs(x - 1, y, len + 1, 'U');
        }
    }
}

int main() {
    setIO();
    cin >> n >> m;
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                for (int k = 0; k < n; ++k) {
                    for (int l = 0; l < m; ++l) {
                        visited[k][l] = false;
                    }
                }
                if (i == 0) {
//                    cout << i << " " << j << "\n";
                    dfs(i, j, 1, 'D');
                }
                if (j == 0) {
//                    cout << i << " " << j << "\n";
                    dfs(i, j, 1, 'R');
                }
                if (i == n - 1) {
//                    cout << i << " " << j << "\n";
                    dfs(i, j, 1, 'U');
                }
                if (j == m - 1) {
//                    cout << i << " " << j << "\n";
                    dfs(i, j, 1, 'L');
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}

