#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;

long long dp[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n), pre(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i] = pre[max(0, i - 1)] + a[i];
    }
    long long sol = 0;
    multiset<long long, greater<>> mx;
    mx.insert(0);
    for (int i = 0; i < n; ++i) {
        dp[i] = max(0ll, *mx.begin() - k + pre[i]);
        dp[i] = max(dp[i], a[i] - k);
//        for (int j = max(0, i - m); j <= i; ++j) {
//            dp[i] = max(dp[i], dp[j] - k + pre[i] - pre[j]);
//        }
        mx.insert(dp[i] - pre[i]);
        if (i - m >= 0) {
            mx.erase(mx.find(dp[i - m] - pre[i - m]));
        }
        if (i == m - 1) {
            mx.erase(mx.find(0));
        }
        sol = max(sol, dp[i]);
    }
    cout << sol << "\n";
    return 0;
}