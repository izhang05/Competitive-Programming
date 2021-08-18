/* Author: izhang05
 * Time: 08-18-2021 15:32:08
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<int> cnt(60);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 60; ++j) {
            if ((1ll << j) & a[i]) {
                ++cnt[j];
            }
        }
        sum += a[i];
        sum %= mod;
    }
    long long sol = 0;
    for (int j = 0; j < n; ++j) {
        long long c = (n * (a[j] % mod) + sum) % mod, x = 0;
        for (int i = 0; i < 60; ++i) {
            if ((1ll << i) & a[j]) {
                x += ((1ll << i) % mod) * cnt[i];
                x %= mod;
            }
        }
        sol += x * (c - x);
        sol %= mod;
    }
    cout << (sol + mod) % mod << "\n";
}

signed main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
