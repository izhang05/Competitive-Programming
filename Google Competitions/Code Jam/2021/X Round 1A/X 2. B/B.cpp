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
const int maxn = 105;

map<int, unordered_set<int>> dp[maxn];

void solve() {
    int m;
    cin >> m;
    vector<int> a;
    for (int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        for (int j = 0; j < c; ++j) {
            a.push_back(b);
        }
    }
    int n = (int) a.size();
    for (int i = 0; i < n; ++i) {
        dp[i].clear();
    }
    dp[0][a[0]].insert(0);
    dp[0][1].insert(a[0]);
    for (int i = 0; i < n - 1; ++i) {
        for (const auto &j : dp[i]) {
            for (auto k : j.second) {
                if (j.first * a[i + 1] <= 5e4) {
//#ifdef DEBUG
//                    cout << j.first << " " << j.first * a[i + 1] << "\n";
//#endif
                    dp[i + 1][j.first * a[i + 1]].insert(k);
                }
                if (k + a[i + 1] <= 5e4) {
//#ifdef DEBUG
//                    cout << j.first << "\n";
//#endif
                    dp[i + 1][j.first].insert(k + a[i + 1]);
                }
            }
        }
    }
    int sol = 0;
    for (auto i : dp[n - 1]) {
#ifdef DEBUG
        cout << i.first << "\n";
#endif
        if (i.second.find(i.first) != i.second.end()) {
            sol = i.first;
        }
    }
    cout << sol << "\n";
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
