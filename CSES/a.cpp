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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;

int dp[maxn];

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        int n;
        cin >> n;
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++cnt[a];
        }
        int sol = inf;
        for (auto &i : cnt) {
            for (int j = 1; j * j <= i.first; ++j) {
                if (i.first % j == 0) {
                    dp[i.first] = max({dp[i.first], dp[j], dp[i.first / j]});
                }
            }
            dp[i.first] += i.second;
            sol = min(sol, n - dp[i.first]);
#ifdef DEBUG
            cout << i.first << " " << dp[i.first] << "\n";
#endif
        }
        cout << sol << "\n";
    }
    return 0;
}
