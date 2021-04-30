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

const int mod = 1e9 + 7, maxn = 1e5 + 5;
const long long inf = 1e18;

long long dp[maxn][2];

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<string>> s(n, vector<string>(2));
    for (int i = 0; i < n; ++i) {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for (int i = 1; i < n; ++i) {
        if (s[i][0] >= s[i - 1][0]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (s[i][0] >= s[i - 1][1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (s[i][1] >= s[i - 1][0]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        }
        if (s[i][1] >= s[i - 1][1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
        }
    }
    long long sol = min(dp[n - 1][0], dp[n - 1][1]);
    cout << (sol == inf ? -1 : sol) << "\n";
    return 0;
}

