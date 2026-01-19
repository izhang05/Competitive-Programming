/* Author: izhang
 * Time: 06-29-2025 16:10:39
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 5e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int dp[mxn];

void test_case() {
    int m;
    cin >> m;
    if (m % 2 == 0) {
        cout << -1 << "\n";
        return;
    }
    cout << dp[m] << "\n";
}

int main() {
    setIO("1");
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[1] = 1;
    for (int i = 3; i < mxn; i += 2) {
        dp[i] = dp[i - 2] + 1;
        for (int j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                dp[i] = min(dp[i], min(dp[j - 2] + dp[i / j], dp[j] + dp[i / j - 2]));
            }
        }
    }

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
