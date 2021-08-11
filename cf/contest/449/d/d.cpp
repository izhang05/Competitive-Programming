/* Author: izhang05
 * Time: 08-11-2021 14:16:00
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[1 << maxs];
long long binpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++dp[a ^ ((1 << maxs) - 1)];
    }
    for (int i = 0; i < maxs; ++i) {
        for (int mask = 0; mask < (1 << maxs); ++mask) {
            if (mask & (1 << i)) {
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i < (1 << maxs); ++i) {
        long long add = binpow(2, dp[i], mod);
        if (__builtin_popcount(i) % 2 == 1) {
            add *= -1;
        }
        sol += add;
        sol %= mod;
    }
    cout << (sol + mod) % mod << "\n";
}

int main() {
    setIO("2");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
