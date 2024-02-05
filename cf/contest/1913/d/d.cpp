/* Author: izhang
 * Time: 02-03-2024 16:42:07
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
const int inf = 0x3f3f3f3f, mod = 998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> dp(n + 1), pre(n + 1), dp2(n + 1);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        long long &cur = dp[i + 1], &cur2 = dp2[i + 1];
        while (!st.empty() && st.top().first > a[i]) {
            st.pop();
        }
        if (st.empty()) {
            cur = (pre[i] + 1) % mod;
            cur2 = cur;
        } else {
            int j = st.top().second;
            cur = (pre[i] - pre[j + 1]) % mod;
            cur = (cur + dp2[j + 1]) % mod;
            cur2 = (dp2[j + 1] + cur) % mod;
        }
        pre[i + 1] = (pre[i] + cur) % mod;
        st.emplace(a[i], i);
    }
    dbg() << dp;
    dbg() << dp2;
    long long sol = 0;
    int mn = inf;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < mn) {
            sol = (sol + dp[i + 1]) % mod;
            mn = a[i];
        }
    }
    cout << (sol + mod) % mod << "\n";
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
