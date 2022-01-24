/* Author: izhang
 * Time: 01-23-2022 23:48:03
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int dp[maxn][maxn], dp2[maxn];

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i][i + 1] = a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = i + 1; k < j; ++k) {
                if (dp[i][k] != -1 && dp[k][j] != -1 && dp[i][k] == dp[k][j]) {
                    dp[i][j] = dp[i][k] + 1;
                }
            }
        }
    }
    memset(dp2, 0x3f, sizeof(dp2));
    dp2[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j][i] != -1) {
                dp2[i] = min(dp2[i], dp2[j] + 1);
            }
        }
    }
    cout << dp2[n] << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
