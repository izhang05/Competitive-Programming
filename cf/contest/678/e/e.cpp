/* Author: izhang05
 * Time: 12-26-2021 15:22:31
**/
#include <bits/stdc++.h>

using namespace std;

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 19;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n;
long double m[maxn][maxn], dp[maxn][1 << maxn];

void test_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }
    dp[0][1] = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) <= 1) {
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                int n_mask = mask ^ (1 << i);
                for (int j = 0; j < n; ++j) {
                    if (n_mask & (1 << j)) {
                        dp[i][mask] = max(dp[i][mask], m[j][i] * dp[j][n_mask] + m[i][j] * dp[i][mask ^ (1 << j)]);
                    }
                }
            }
        }
    }
    long double sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, dp[i][(1 << n) - 1]);
    }
    cout << fixed << setprecision(15) << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
