/*
ID: izhang01
TASK: cowjog
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
}
//#define DEBUG
const long long inf = 1e18;

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif
    long long n, t;
    cin >> n >> t;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; ++i) {
        long long speed;
        cin >> a[i].first >> speed;
        a[i].second = a[i].first + speed * t;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<long long> dp(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        dp[i] = inf;
    }
    dp[0] = -inf;
    for (int i = 0; i < n; ++i) {
#ifdef DEBUG
        cout << a[i].first << " " << a[i].second << "\n";
#endif
        auto it = upper_bound(dp.begin(), dp.end(), a[i].second);
        if (it != dp.end()) {
            dp[it - dp.begin()] = a[i].second;
        }
    }
    int sol = 0;
    for (int i = 0; i < n + 1; ++i) {
        if (dp[i] != inf) {
            sol = i;
        }
    }
    cout << sol << "\n";
#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
