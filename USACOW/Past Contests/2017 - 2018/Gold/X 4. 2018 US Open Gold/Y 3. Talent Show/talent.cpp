/*
ID: izhang01
TASK: talent
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
}

unordered_map<int, int> cur_dp;

int main() {
    setIO();
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    double sol = 0;
    for (int i = 0; i < n; ++i) {
        cur_dp[a[i].first] = max(cur_dp[a[i].first], a[i].second);
        unordered_map<int, int> next_dp;
        for (pair<int, int> j : cur_dp) {
            double cur_score = double(j.second) / j.first;
            if (j.first >= w) {
                sol = max(sol, cur_score);
            }
            if (cur_score < sol) {
                continue;
            }
            next_dp[j.first] = max(next_dp[j.first], j.second);
            next_dp[j.first + a[i + 1].first] = max(next_dp[j.first + a[i + 1].first], j.second + a[i + 1].second);
        }
        swap(cur_dp, next_dp);
    }
    cout << int(1000 * sol) << "\n";
    return 0;
}