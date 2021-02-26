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
//#define DEBUG

int main() {
    setIO();
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    double sol = 0;
    unordered_map<int, int> cur_dp; // map<weight, talent>
    for (int i = 0; i < n; ++i) {
        cur_dp[a[i].first] = max(cur_dp[a[i].first], a[i].second);
        for (pair<int, int> j : cur_dp) {
            double cur_score = double(j.second) / j.first;
            if (j.first >= w) {
                sol = max(sol, cur_score);
            }
        }

        unordered_map<int, int> next_dp;
        for (pair<int, int> j : cur_dp) {
            double cur_score = double(j.second) / j.first;
            if (cur_score >= sol) {
                next_dp[j.first] = max(next_dp[j.first], j.second);
                next_dp[j.first + a[i + 1].first] = max(next_dp[j.first + a[i + 1].first], j.second + a[i + 1].second);
            }
        }
        swap(cur_dp, next_dp);
    }
    cout << int(1000 * sol) << "\n";
    return 0;
}
//#include <algorithm>
//#include <cassert>
//#include <cstdio>
//using namespace std;
//
//#define NMAX 250
//#define WMAX 1000
//
//#define infinite 1000000000000000000LL
//
//// The inputs
//int weights[NMAX];
//int talent[NMAX];
//
//int n;
//int w;
//
//// The dp state.
//// For 0 <= i < w, this is the maximum adjusted-talent-score achievable
//// with weight exactly i.
//// For i=w, this is the maximum talent achievable
//// with weight AT LEAST w.
//long long dp[WMAX + 1];
//
//// Check if a ratio of y/1000 is achievable.
//bool doable(int y) {
//    for (int i = 0; i <= w; i++) {
//        dp[i] = -infinite;
//    }
//    dp[0] = 0;
//
//    for (int j = 0; j < n; j++) {
//        long long value = 1000 * (long long) talent[j] - y * (long long) weights[j];
//        int inc = weights[j];
//        for (int k = w; k >= 0; k--) {
//            int k1 = min(w, k + inc);
//            if (dp[k] != -infinite) {
//                if (dp[k1] < dp[k] + value) {
//                    dp[k1] = dp[k] + value;
//                }
//            }
//        }
//    }
//
//    return dp[w] >= 0;
//}
//
//int main() {
//    freopen("talent.in", "r", stdin);
//    freopen("talent.out", "w", stdout);
//    scanf("%d", &n);
//    scanf("%d", &w);
//    assert(1 <= n && n <= NMAX);
//    assert(1 <= w && w <= WMAX);
//
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &weights[i]);
//        scanf("%d", &talent[i]);
//        assert(1 <= weights[i] && weights[i] <= 1000000);
//        assert(1 <= talent[i] && talent[i] <= 1000);
//    }
//
//    // Binary search
//    // Invariant: lo <= answer < hi
//    int lo = 0;
//    int hi = (1000 * 250 * 1000) + 1;
//    while (hi > lo + 1) {
//        int mid = (lo + hi) / 2;
//        if (doable(mid)) {
//            lo = mid;
//        } else {
//            hi = mid;
//        }
//    }
//    printf("%d\n", lo);
//}