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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2005;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long dp[maxn][maxn];


int main() {
    setIO("1");

    int n, start, end;
    cin >> n >> start >> end;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            long long &cur = dp[i][j];
            if (i == start || i == end) {
                cur = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            } else {
                cur += j * dp[i - 1][j + 1];
                cur %= mod;
                cur += (j - (i > start) - (i > end)) * dp[i - 1][j - 1];
                cur %= mod;
            }
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}