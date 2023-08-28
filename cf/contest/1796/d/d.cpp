/* Author: izhang
 * Time: 08-28-2023 02:44:29
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5, mxk = 22;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp1[mxn][mxk], dp2[mxn][mxk];

void test_case() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp1[i][j] = dp2[i][j] = -INFL;
        }
    }
    dp1[0][0] = dp2[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= min(i, k); ++j) {
            dp2[i][j] = 0;
        }
        for (int j = 0; j <= k; ++j) {
            dp1[i][j] = dp1[i - 1][j];
            dp2[i][j] = max(dp2[i][j], dp2[i - 1][j] + a[i - 1] - x);
            if (j > 0) {
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - 1] + a[i - 1] + x);
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - 1]);
            }
            dp1[i][j] = max(dp1[i][j], dp2[i][j]);
        }
    }
    cout << dp1[n][k] << "\n";
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
