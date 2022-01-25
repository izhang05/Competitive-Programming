/* Author: izhang
 * Time: 01-24-2022 11:00:19
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
long long dp[maxn][maxn];

void test_case() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    d.push_back(l);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            long long cur = dp[i][j];
            for (int m = i + 1; m <= n; ++m) {
                dp[m][j + m - i - 1] = min(dp[m][j + m - i - 1], cur + (d[m] - d[i]) * a[i]);
            }
        }
    }
    cout << *min_element(dp[n], dp[n] + k + 1) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
