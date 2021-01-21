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

int main() {
    setIO();
    int n;
    cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    int pre[n + 1][n + 1];
    for (int i = 0; i < n; ++i) {
        pre[i][0] = 0;
        pre[i][1] = grid[i][0];
        for (int j = 1; j < n; ++j) {
            pre[i][j + 1] = pre[i][j] + grid[i][j];
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = i; k < n; ++k) {
                int cur = pre[j][k + 1] - pre[j][i];
                sol = max(sol, cur);
//                cout << cur << "\n";
                for (int l = j + 1; l < n; ++l) {
                    cur += pre[l][k + 1] - pre[l][i];
                    sol = max(sol, cur);
//                    cout << cur << "\n";
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}

