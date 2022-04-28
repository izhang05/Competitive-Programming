#include <bits/stdc++.h>

using namespace std;

#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 1e3 + 5;

int dp[maxn][maxn], sol[maxn];

void solve() {
    int n;
    cin >> n;
    cout << sol[n] << "\n";
}

int main() {
    setIO("1");
    for (int i = 3; i < maxn; ++i) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            int cur = dp[i][j];
            if (cur) {
                for (long long ne = j + j; ne + i < maxn; ne += j) {
                    dp[i + ne][ne] = max(dp[i + ne][ne], cur + 1);
                }
            }
            sol[i] = max(sol[i], cur);
        }
    }

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
