/* Author: izhang
 * Time: 05-21-2022 17:15:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn][maxn];

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = -INFL;
        }
    }
    dp[0][0] = a[0] + b[0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dbg() << i << " " << j << " " << dp[i][j];
            for (int l = i + 1; abs(l - j) <= k && l < n; ++l) {
                dp[l][j] = max(dp[l][j], dp[i][j] + a[l]);
            }
            for (int l = j + 1; abs(l - i) <= k && l < n; ++l) {
                dp[i][l] = max(dp[i][l], dp[i][j] + b[l]);
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
