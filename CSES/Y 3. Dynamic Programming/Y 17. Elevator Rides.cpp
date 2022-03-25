#include <bits/stdc++.h>

using namespace std;

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 20;

pair<int, int> dp[1 << maxn];

int main() {
    setIO("17");
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        dp[i] = {inf, inf};
    }
    dp[0] = {1, 0};
    for (int i = 0; i < (1 << n); ++i) {
#ifdef DEBUG
        cout << i << " " << dp[i].first << " " << dp[i].second << "\n";
#endif
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) {
                pair<int, int> ne;
                if (dp[i].second + a[j] > x) {
                    ne = {dp[i].first + 1, a[j]};
                } else {
                    ne = {dp[i].first, dp[i].second + a[j]};
                }
                dp[i ^ (1 << j)] = min(dp[i ^ (1 << j)], ne);
            }
        }
    }
    cout << dp[(1 << n) - 1].first << "\n";
    return 0;
}
