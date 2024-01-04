/* Author: izhang
 * Time: 01-04-2024 15:14:04
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int dp[mxn][mxn * mxn], dp1[mxn][mxn * mxn];

void test_case() {
    string s;
    cin >> s;
    int n = int(s.size());
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = s[0] == '0';
    dp[1][0] = s[0] == '1';
    for (int i = 0; i < n - 1; ++i) {
        memset(dp1, 0x3f, sizeof(dp1));
        for (int j = 0; j <= i + 1; ++j) {
            for (int k = 0; k < mxn * mxn; ++k) {
                // add zero
                dp1[j + 1][k] = min(dp1[j + 1][k], dp[j][k] + (s[i + 1] == '1'));
                // add one
                if (k + j < mxn * mxn) {
                    dp1[j][k + j] = min(dp1[j][k + j], dp[j][k] + (s[i + 1] == '0'));
                }
            }
        }
        swap(dp, dp1);
    }
    int z = 0;
    for (int i = 0; i < n; ++i) {
        z += s[i] == '0';
    }
    cout << dp[z][(z) * (n - z) / 2] / 2 << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
