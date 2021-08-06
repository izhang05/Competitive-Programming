/* Author: izhang05
 * Time: 08-04-2021 18:46:24
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 1e5 + 5, maxk = 1e2 + 5;
const long long inf = 2e18;
long long dp[maxn][maxk]; // dp[ind][num removed]

int main() {
    setIO("lifeguards");
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> orig(n);
    for (int i = 0; i < n; ++i) {
        cin >> orig[i].first >> orig[i].second;
    }
    sort(orig.begin(), orig.end());
    vector<pair<int, int>> a;
    int cur_mx = orig[0].second;
    a.push_back(orig[0]);
    for (int i = 1; i < n; ++i) {
        if (orig[i].second > cur_mx) {
            a.push_back(orig[i]);
            cur_mx = orig[i].second;
        }
    }
    k -= (n - int(a.size()));
    n = (int) a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = -inf;
        }
    }
    dp[0][0] = a[0].second - a[0].first, dp[0][1] = 0;
    int pre = -1;
#ifdef DEBUG
    for (int i = 0; i <= k; ++i) {
        cout << 0 << " " << i << " " << dp[0][i] << "\n";
    }
#endif
    long long sol = dp[0][k];
    for (int i = 1; i < n; ++i) {
        if (i <= k) {
            dp[i][i] = a[i].second - a[i].first;
        }
        if (i + 1 <= k) {
            dp[i][i + 1] = 0;
        }
        for (int j = 0; j <= k; ++j) {
            // don't take ith range
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
            // take ith range
            while (pre + 1 < n && a[pre + 1].second < a[i].first) {
                ++pre;
            }
            if (pre >= 0) {
                dp[i][j] = max(dp[i][j], dp[pre][max(0, j - (i - pre - 1))] + a[i].second - a[i].first);
            }
            if (pre + 1 != i) {
                dp[i][j] = max(dp[i][j], dp[pre + 1][max(0, j - (i - (pre + 1) - 1))] + a[i].second - a[pre + 1].second);
            }
#ifdef DEBUG
            cout << i << " " << j << " " << dp[i][j] << " " << max(0, j - (pre + 1) - 1) << " " << dp[pre + 1][max(0, j - (pre + 1) - 1)] << " " << dp[pre + 1][max(0, j - (pre + 1) - 1)] + a[i].second - a[pre + 1].second << " " << a[i].second - a[pre + 1].second << "\n";
#endif
        }
        sol = max(sol, dp[i][k]);
    }
    cout << sol << "\n";
    return 0;
}
