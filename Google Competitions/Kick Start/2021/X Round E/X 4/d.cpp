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
// C++ program to implement above approach
#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;
long double dp[maxn][3];

int s_recursive(int n, int k) {
    if (dp[n][k] != -1) {
        return dp[n][k];
    }
    if (n == 0 && k == 0) {
        return dp[n][k] = 1;
    }
    if (n == 0 || k == 0) {
        return dp[n][k] = 0;
    }
    return dp[n][k] = s_recursive(n - 1, k - 1) + (n - 1) * s_recursive(n - 1, k);
}

void solve() {
    for (auto &i : dp) {
        for (auto &j : i) {
            j = -1;
        }
    }
    int n;
    cin >> n;
    long double sol = s_recursive(n + 1, 2);
    for (int i = 1; i <= n; ++i) {
        sol /= i;
    }
    cout << fixed << setprecision(10) << sol << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
