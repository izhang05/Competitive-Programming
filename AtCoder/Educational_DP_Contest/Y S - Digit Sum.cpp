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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e4 + 5, maxd = 1e2 + 5;

long long dp[maxn][maxd];

int main() {
    setIO("S");
    string k;
    cin >> k;
    int d;
    cin >> d;
    int n = (int) k.size();
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k[i] - '0'; ++j) {
            ++dp[i][(sum + j) % d];
            dp[i][(sum + j) % d] %= mod;
        }
        for (int j = 0; j < d; ++j) {
            long long cur = dp[i][j];
            if (!cur) {
                continue;
            }
            for (int l = 0; l < 10; ++l) {
                dp[i + 1][(j + l) % d] += cur;
                dp[i + 1][(j + l) % d] %= mod;
            }
        }
        sum += k[i] - '0';
        sum %= d;
    }
    ++dp[n - 1][sum];
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    cout << (dp[n - 1][0] - 1 + mod) % mod << "\n";
    return 0;
}
