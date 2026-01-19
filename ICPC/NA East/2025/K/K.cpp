#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 55;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

__int128 dp[mxn][mxn][mxn][4]; // [weeks(implicit)][a][b][c][a/c/one b/two b]


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);

    int n, d;
    cin >> n >> d;
    dp[1][0][0][0] = dp[0][1][0][2] = dp[0][0][1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int a = 0; a <= i; ++a) {
            for (int b = 0; a + b <= i; ++b) {
                int c = i - a - b;
                // take a
                if (a > 0) {
                    dp[a][b][c][0] += dp[a - 1][b][c][1] + dp[a - 1][b][c][2] + dp[a - 1][b][c][3];
                }
                // take c
                if (c > 0) {
                    dp[a][b][c][1] += dp[a][b][c - 1][0] + dp[a][b][c - 1][2] + dp[a][b][c - 1][3];
                }
                // take b
                if (b > 0) {
                    dp[a][b][c][2] += dp[a][b - 1][c][0] + dp[a][b - 1][c][1];
                    dp[a][b][c][3] = dp[a][b - 1][c][2];
                }
            }
        }
    }
    __int128 sol = 0;
    for (int a = 0; a <= n; ++a) {
        for (int b = 0; a + b <= n; ++b) {
            int c = n - a - b;
            if (abs(a - b) > d || abs(a - c) > d || abs(b - c) > d) {
                continue;
            }
            for (int i = 0; i < 4; ++i) {
//                cout << a << " " << b << " " << c << " " << i << " " << (long long) dp[a][b][c][i] << "\n";
                sol += dp[a][b][c][i];
            }
        }
    }
    if (n % 2 == 0) {
        for (int a = 0; a <= n / 2; ++a) {
            for (int b = 0; a + b <= n / 2; ++b) {
                int c = n / 2 - a - b;
                if (2 * abs(a - b) > d || 2 * abs(a - c) > d || 2 * abs(b - c) > d) {
                    continue;
                }
                sol -= dp[a][b][c][2]; // must have exactly one b
            }
        }
    } else {
        for (int a = 0; a <= n / 2; ++a) {
            for (int b = 0; a + b <= n / 2; ++b) {
                int c = n / 2 - a - b;
//                cout << a << " " << b << " " << c << "\n";
//                cout << (long long) sol << "\n";
                // middle a
                if (abs(2 * a + 1 - 2 * b) <= d && abs(2 * a + 1 - 2 * c) <= d && abs(2 * b - 2 * c) <= d) {
                    for (int i = 1; i < 4; ++i) {
                        sol -= dp[a][b][c][i];
                    }
                }
                // middle b
                if (abs(2 * a - (2 * b + 1)) <= d && abs(2 * a - 2 * c) <= d && abs(2 * b + 1 - c) <= d) {
                    sol -= dp[a][b][c][0] + dp[a][b][c][1];
                }
                // middle c
                if (abs(2 * a - 2 * b) <= d && abs(2 * a - (2 * c + 1)) <= d && abs(2 * b - (2 * c + 1)) <= d) {
                    sol -= dp[a][b][c][0] + dp[a][b][c][2] + dp[a][b][c][3];
                }
//                cout << (long long) sol << "\n";
            }
        }
    }
    cout << (long long) sol << "\n";
}
