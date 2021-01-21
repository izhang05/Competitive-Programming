#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    bool office[n][m];
    bool dp[n][m][n][m]; // dp[left_column][top_row][right_column][bottom_row]
    string inp;
    for (int i = 0; i < n; ++i) {
        cin >> inp;
        for (int j = 0; j < m; ++j) {
            office[i][j] = inp[j] - '0';
            dp[i][j][i][j] = office[i][j];
        }
    }

    int sol = 4;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
//            cout << i << " " << j << "\n";
//            cout << dp[i][j][i][j] << "\n";
            for (int k = i + 1; k < n; ++k) {
                dp[i][j][k][j] = dp[i][j][k - 1][j] + office[k][j];
                if (!dp[i][j][k][j]) {
                    sol = max(sol, 2 * (k - i + 2));
                }
            }
            for (int k = j + 1; k < m; ++k) {
                dp[i][j][i][k] = dp[i][j][i][k - 1] + office[i][k];
                if (!dp[i][j][i][k]) {
                    sol = max(sol, 2 * (k - j + 2));
                }
            }

            for (int k = i + 1; k < n; ++k) {
                dp[i][j][i][j] = office[i][j];
                for (int l = j + 1; l < m; ++l) {
                    dp[i][j][k][l] = dp[i][j][k - 1][l] + dp[i][j][k][l - 1] + office[k][l];
                    if (!dp[i][j][k][l]) {
                        sol = max(sol, 2 * (k - i + 1 + l - j + 1));
//                        cout << i << " " << j << " " << k << " " << l << " " << sol << "\n";
//                        cout << 2 * (k - i + 1 + l - j + 1) << "\n";
                    }
                }
            }
        }
    }
    cout << sol << "\n";

    return 0;
}
