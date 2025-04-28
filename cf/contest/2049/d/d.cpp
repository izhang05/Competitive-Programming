/* Author: izhang
 * Time: 12-27-2024 17:55:24
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 205;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long dp[mxn][mxn], grid[mxn][2 * mxn], cost[mxn][mxn][2 * mxn];

void test_case() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 2 * m; ++j) {
            dp[i][j] = INFL;
        }
        for (int l = 0; l < m; ++l) {
            for (int j = 0; j <= 2 * m; ++j) {
                cost[i][l][j] = INFL;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            grid[i][j + m] = grid[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int l = 0; l < m; ++l) {
            cost[i][l][0] = 0;
            for (int j = 0; j <= l; ++j) {
                cost[i][l][0] += grid[i][j];
            }
            for (int j = 1; j < 2 * m && l + j < 2 * m; ++j) {
                cost[i][l][j] = cost[i][l][j - 1] - grid[i][j - 1] + grid[i][l + j] + k;
            }
            for (int j = 2 * m - 2; j >= 0; --j) {
                cost[i][l][j] = min(cost[i][l][j], cost[i][l][j + 1]);
            }
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l <= j; ++l) {
                dp[i][j] = min(dp[i][j], dp[i - 1][l] + cost[i][j - l][l] - l * k);
            }
        }
    }
    cout << dp[n][m - 1] << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
