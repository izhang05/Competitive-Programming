/* Author: izhang05
 * Time: 08-11-2021 00:52:05
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5, maxs = 22;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int dp[1 << maxs];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[a[i]] = a[i];
    }
    for (int i = 0; i < maxs; ++i)
        for (int mask = 0; mask < (1 << maxs); ++mask) {
            if (mask & (1 << i)) {
                dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
            }
        }
    for (int i = 0; i < n; ++i) {
        int comp = a[i] ^ ((1 << maxs) - 1);
        cout << (dp[comp] ? dp[comp] : -1) << " \n"[i == n - 1];
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
