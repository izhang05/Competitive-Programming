/*
ID: izhang01
TASK: pcb
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("pcb.in", "r", stdin);
    freopen("pcb.out", "w", stdout);
#endif
}
//#define DEBUG

const int inf = 1e9;

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        a[i].first = i;
    }
    sort(a.begin(), a.end(), [](pair<int, int> left, pair<int, int> right) {
        return left.second == right.second ? left.first < right.first : left.second < right.second;
    });
    reverse(a.begin(), a.end());
    vector<int> dp(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        dp[i] = inf;
    }
    dp[0] = -inf;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i].first);
        if (it != dp.end()) {
            dp[it - dp.begin()] = a[i].first;
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
    cout << "Execution time: "
         << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds"
         << endl;
#endif
    return 0;
}