/* Author: izhang
 * Time: 09-18-2023 19:52:36
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxs = 805;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[45][mxs][mxs];

int valid(int x) {
    return x >= 0 && x < mxs;
}

void test_case() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    dp[0][402][402] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < mxs; ++j) {
            for (int k = 0; k < mxs; ++k) {
                dp[i + 1][j][k] += dp[i][j][k];
                if (valid(j + a[i].first) && valid(k + a[i].second)) {
                    dp[i + 1][j + a[i].first][k + a[i].second] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[n][402][402] - 1 << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
