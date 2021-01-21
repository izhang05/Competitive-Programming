#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 101, maxw = 1e5 + 1;
const long long inf = 1e18;
long long dp[maxn][maxw];

int main() {
    setIO();

    int n, w;
    cin >> n >> w;
    vector<pair<int, int> > item(n); // first = weight, second = value
    for (int i = 0; i < n; ++i) {
        cin >> item[i].first >> item[i].second;
        for (int j = 0; j < w + 1; ++j) {
            dp[i][j] = -inf;
        }
        dp[i][item[i].first] = item[i].second;
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= w; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + item[i + 1].first <= w) {
                dp[i + 1][j + item[i + 1].first] = max(
                        {dp[i + 1][j + item[i + 1].first], dp[i][j] + item[i + 1].second});
            }
            if (i == n - 1) {
                sol = max(sol, dp[i][j]);
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
