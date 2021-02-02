#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    // alternating in col
    pair<int, int> sol;
    for (int row = 0; row < n; ++row) {
        int local_sol = 0, cur = 0;
        for (int col = 0; col < n; col += 2) {
            cur += a[row][col];
        }
        local_sol = cur;
        cur = 0;
        for (int col = 1; col < n; col += 2) {
            cur += a[row][col];
        }
        sol.first += max(local_sol, cur);
    }
    for (int col = 0; col < n; ++col) {
        int local_sol = 0, cur = 0;
        for (int row = 0; row < n; row += 2) {
            cur += a[row][col];
        }
        local_sol = cur;
        cur = 0;
        for (int row = 1; row < n; row += 2) {
            cur += a[row][col];
        }
        sol.second += max(local_sol, cur);
    }
    cout << max(sol.first, sol.second) << "\n";
    return 0;
}
