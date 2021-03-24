#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;

int dp[maxn][maxn];

int main() {
    setIO("1");
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            int cur = dp[i][j];
#ifdef DEBUG
            cout << i << " " << j << " " << cur << "\n";
#endif
            dp[i + 1][j] = max(dp[i + 1][j], cur);
            if (j == k) {
                continue;
            }
            int lo = i + 1, hi = n - 1, mid, res = i;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (a[mid] <= a[i] + 5) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            //#ifdef DEBUG
            //            cout << i << " " << res << "\n";
            //#endif
            dp[res + 1][j + 1] = max(dp[res + 1][j + 1], cur + res - i + 1);
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}
