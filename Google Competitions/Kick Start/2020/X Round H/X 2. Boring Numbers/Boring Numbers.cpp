#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
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
const int maxn = 20;
long long dp[maxn][10];

long long solvedp(long long x) {
    if (x == 0) {
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    vector<int> num;
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    int n = num.size();
    for (int i = 1; i < num[0]; i += 2) {
        dp[0][i] = 1;
    }
    bool end = num[0] % 2 == 1;
    for (int i = 0; i < n - 1; ++i) {
        long long sum = 0;
        for (int j = 0; j < 10; ++j) {
            sum += dp[i][j];
        }
        for (int j = i % 2; j < 10; j += 2) {
            dp[i + 1][j] += sum;
        }

        for (int j = 1; j < 10; j += 2) {
            ++dp[i + 1][j];
        }

        if (end) {
            for (int j = i % 2; j < num[i + 1]; ++j) {
                ++dp[i + 1][j];
            }
        }
        if (num[i + 1] % 2 != i % 2) {
            end = false;
        }
    }
    long long sol = end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < 10; ++i) {
        sol += dp[n - 1][i];
    }
    return sol;
}

void solve() {
    solvedp(15);
    return;
    long long l, r;
    cin >> l >> r;
#ifdef DEBUG
    cout << solvedp(l - 1) << " " << solvedp(r) << "\n";
#endif
    cout << solvedp(r) - solvedp(l - 1) << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        //        cout << "Case #" << i << ": ";
        solve();
    }
}
