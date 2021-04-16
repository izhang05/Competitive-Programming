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

const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 5e3 + 5;
long long dp[maxn][maxn];

long long solve(long long a, long long b) {
    memset(dp, 0, sizeof(dp));
    dp[0][b] = 1;
    for (long long i = 0; i < a; ++i) {
        for (long long j = b; j >= 0; --j) {
            if (!dp[i][j]) {
                continue;
            }
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= mod;
            if (j > 0) {
                dp[i + 1][j - 1] += dp[i][j] * j;
                dp[i + 1][j - 1] %= mod;
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i <= b; ++i) {
        sol = (sol + dp[a][i]) % mod;
    }
    return sol;
}

int main() {
    setIO("1");
    int a, b, c;
    cin >> a >> b >> c;
    long long sol = 1;
    sol = (sol * solve(a, b)) % mod;
    sol = (sol * solve(c, b)) % mod;
    sol = (sol * solve(a, c)) % mod;
    cout << sol << "\n";
    return 0;
}
