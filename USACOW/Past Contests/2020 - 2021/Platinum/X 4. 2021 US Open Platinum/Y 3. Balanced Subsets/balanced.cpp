#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    freopen("2.out", "w", stderr);
#endif
}
//#define DEBUG
const int maxn = 155, mod = 1e9 + 7;
int grid[maxn][maxn];
long long dp[maxn][maxn][maxn][2][2], pre1[maxn][maxn], pre2[maxn][maxn][2][2];

long long get_pre(int x1, int y1, int x2, int y2, int a, int b) {
    if (x1 > x2 || y1 > y2 || x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
        return 0;
    }
    long long res = pre2[x2][y2][a][b];
    if (x1) {
        res -= pre2[x1 - 1][y2][a][b];
        res %= mod;
    }
    if (y1) {
        res -= pre2[x2][y1 - 1][a][b];
        res %= mod;
        if (x1) {
            res += pre2[x1 - 1][y1 - 1][a][b];
            res %= mod;
        }
    }
    return res % mod;
}

int main() {
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'G') {
                grid[i][j] = 1;
            }
            pre1[i][j] = pre1[i][max(0, j - 1)] + grid[i][j];
        }
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = j; k < n; ++k) {
                long long p = pre1[i][k];
                if (j) {
                    p -= pre1[i][j - 1];
                }
                if (p != k - j + 1) { // range is not all 1
                    continue;
                }
                dp[i][j][k][1][1] = 1 + get_pre(j, j, k, k, 1, 1);
                dp[i][j][k][1][1] %= mod;
                if (i) {
                    dp[i][j][k][0][1] = get_pre(0, j, j, k, 0, 1) + get_pre(0, j, j - 1, k, 1, 1);
                    dp[i][j][k][0][1] %= mod;

                    dp[i][j][k][1][0] = get_pre(j, k, k, n - 1, 1, 0) + get_pre(j, k + 1, k, n - 1, 1, 1);
                    dp[i][j][k][1][0] %= mod;

                    dp[i][j][k][0][0] = get_pre(0, k, j, n - 1, 0, 0) + get_pre(0, k, j - 1, n - 1, 1, 0) + get_pre(0, k + 1, j, n - 1, 0, 1) + get_pre(0, k + 1, j - 1, n - 1, 1, 1);
                    dp[i][j][k][0][0] %= mod;
                }
                for (int l = 0; l < 2; ++l) {
                    for (int m = 0; m < 2; ++m) {
                        sol += dp[i][j][k][l][m];
                        sol %= mod;
                    }
                }
            }
        }
        memset(pre2, 0, sizeof(pre2));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < 2; ++l) {
                    for (int m = 0; m < 2; ++m) {
                        long long &cur = pre2[j][k][l][m];
                        cur = dp[i][j][k][l][m];
                        if (j) {
                            cur += pre2[j - 1][k][l][m];
                            cur %= mod;
                        }
                        if (k) {
                            cur += pre2[j][k - 1][l][m];
                            cur %= mod;
                            if (j) {
                                cur -= pre2[j - 1][k - 1][l][m];
                                cur %= mod;
                            }
                        }
                        cur %= mod;
                    }
                }
            }
        }
    }
    cout << (sol + mod) % mod << "\n";
    return 0;
}
