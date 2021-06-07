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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;
long long dp[maxn][maxn], choose[maxn][maxn];

int main() {
    setIO("53");
    string s;
    cin >> s;
    choose[0][0] = 1;
    for (int i = 1; i <= maxn / 2; ++i) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % mod;
        }
    }
    int n = (int) s.size();
    for (int i = 0; i < n; ++i) {
        dp[i + 1][i] = 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; j += 2) {
            for (int k = i + 1; k <= j; k += 2) {
                if (s[i] == s[k]) {
                    long long tmp = dp[i + 1][k - 1] * dp[k + 1][j] % mod;
                    tmp = (tmp * choose[(j - i + 1) / 2][(k - i + 1) / 2]) % mod;
                    dp[i][j] = (dp[i][j] + tmp) % mod;
                }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}
