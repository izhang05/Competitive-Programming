/* Author: izhang
 * Time: 11-13-2023 19:58:45
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e3 + 5, mxd = 25;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[mxn][mxd];



void test_case() {
    int n, d;
    cin >> n >> d;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= d; ++j) {
            int cur = p[i - 1];
            for (int k = i - 1; k >= 0; --k) {
                int cur_val = cur + (cur % 10 < 5 ? -(cur % 10) : 10 - (cur % 10));
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + cur_val);
                if (k > 0) {
                    cur += p[k - 1];
                }
            }
        }
    }
    long long sol = dp[n][d], cur = 0;
    for (int i = n; i >= 0; --i) {
        long long cur_val = cur + (cur % 10 < 5 ? -(cur % 10) : 10 - (cur % 10));
        for (int j = 1; j < d; ++j) {
            sol = min(sol, dp[i][j] + cur_val);
        }
        if (i > 0) {
            cur += p[i - 1];
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
