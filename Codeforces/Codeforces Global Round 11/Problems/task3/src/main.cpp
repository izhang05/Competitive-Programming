#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 1, inf = 1e9;

int dp[maxn]; // dp[ind]

int dist(pair<int, int> i, pair<int, int> j) {
    return abs(i.first - j.first) + abs(i.second - j.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, n;
    cin >> r >> n;
    vector<pair<int, pair<int, int> > > a(n + 1);
    a[0].first = 0;
    a[0].second = pair<int, int>{1, 1};
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i].first;
        cin >> a[i].second.first;
        cin >> a[i].second.second;
        dp[i] = -1e9;
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dp[j][0] = max(dp[j][0], max(dp[i][0], dp[i][1]));
            if (dp[j][1] != -inf && dist(a[i].second, a[j].second) <= a[j].first - a[i].first) {
                dp[j][1] = max(dp[j][1], max(dp[i][0], dp[i][1] + 1));
            }
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            cout << i << " " << j << " " << dp[i][j] << "\n";
//        }
//    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    return 0;
}
