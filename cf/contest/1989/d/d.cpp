/* Author: izhang
 * Time: 07-25-2024 16:37:24
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxa = 1e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    vector<int> best(mxa, inf);
    for (int i = 0; i < n; ++i) {
        best[a[i]] = min(best[a[i]], a[i] - b[i]);
    }
    for (int i = 1; i < mxa; ++i) {
        best[i] = min(best[i], best[i - 1]);
    }
    vector<int> dp(mxa);
    for (int i = 1; i < mxa; ++i) {
        if (best[i] != inf) {
            dp[i] = 2 + dp[i - best[i]];
        }
    }
    long long sol = 0;
    for (int i = 0; i < m; ++i) {
        if (c[i] < mxa) {
            sol += dp[c[i]];
        } else {
            long long cnt = (c[i] - (mxa - 1) + best[mxa - 1] - 1) / best[mxa - 1];
            sol += 2 * cnt + dp[c[i] - cnt * best[mxa - 1]];
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
