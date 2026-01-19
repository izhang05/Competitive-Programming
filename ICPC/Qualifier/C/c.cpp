/* Author: izhang
 * Time: 10-19-2025 11:58:33
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long dp[mxn];

int cur_case = 0;

void test_case() {
    ++cur_case;
    int n;
    cin >> n;
    cout << cur_case << " " << dp[n] << "\n";
}

int main() {
    setIO("1");

    dp[0] = dp[1] = 1;
    for (int i = 2; i < mxn; ++i) {
        if (i % 2 == 0) {
            dp[i] = dp[i / 2];
            for (int j = 2; j <= i; j += 2) {
                dp[i] += dp[(i - j) / 2];
            }
        } else {
            for (int j = 1; j <= i; j += 2) {
                dp[i] += dp[(i - j) / 2];
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
