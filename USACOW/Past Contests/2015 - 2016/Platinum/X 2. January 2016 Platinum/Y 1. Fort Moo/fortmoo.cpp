/*
ID: izhang01
TASK: fortmoo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("fortmoo.in", "r", stdin);
    freopen("fortmoo.out", "w", stdout);
    freopen("fortmoo.out", "w", stderr);
}
//#define DEBUG
const int maxn = 205, inf = 1e9;
char grid[maxn][maxn];
int pre[maxn][maxn];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            pre[i][j + 1] = pre[i][j];
            if (grid[i][j] == 'X') {
                ++pre[i][j + 1];
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            int mn = inf, mx = 0;
            for (int k = 0; k < n; ++k) {
                if (pre[k][j + 1] == pre[k][i]) {
                    mn = min(mn, k);
                    mx = k;
                }
                if ((grid[k][i] == 'X' || grid[k][j] == 'X') && mn != inf) {
                    sol = max(sol, (j - i + 1) * (mx - mn + 1));
#ifdef DEBUG
                    cout << i << " " << j << " " << mn << " " << mx << " " << (j - i + 1) * (mx - mn + 1) << "\n";
#endif
                    mn = inf, mx = 0;
                }
            }
            if (mn != inf) {
#ifdef DEBUG
                cout << i << " " << j << " " << mn << " " << mx << " " << (j - i + 1) * (mx - mn + 1) << "\n";
#endif
                sol = max(sol, (j - i + 1) * (mx - mn + 1));
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
