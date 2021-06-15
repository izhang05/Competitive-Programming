#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
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
long long dp[maxn][maxn], n;

int main() {
    setIO("b");
    string s;
    cin >> s;
    n = int(s.size());
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        if (i + 1 < n && s[i] == s[i + 1]) {
            dp[i][i + 1] = 2;
        }
    }
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (dp[i + 1][j - 1]) {
                    dp[i][j] = min(dp[i][i + len / 2 - 1], dp[j - len / 2 + 1][j]) + 1;
                }
            }
        }
    }
    vector<long long> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ++pre[0], --pre[dp[i][j]];
#ifdef DEBUG
            cout << i << " " << j << " " << dp[i][j] << "\n";
#endif
        }
    }
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += pre[i];
        cout << cur << " ";
    }
    cout << "\n";
    return 0;
}
