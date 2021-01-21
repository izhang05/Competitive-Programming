///*
//ID: izhang01
//TASK: pogocow
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("pogocow.in", "r", stdin);
//    freopen("pogocow.out", "w", stdout);
//}
//
//const int maxn = 1e3 + 1;
//long long dp[maxn][maxn]; // dp[cur_target][last_target]
//
//int main() {
//    setIO();
//    int n;
//    cin >> n;
//    vector<pair<long long, long long>> targets(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> targets[i].first >> targets[i].second;
//    }
//    sort(targets.begin(), targets.end());
//    // left to right
//    for (int i = 0; i < n; ++i) {
//        dp[i][i] = targets[i].second;
//    }
//    long long sol = 0;
//    for (int i = 0; i < n; ++i) { // pre_pre_target
//        for (int j = i; j < n; ++j) { // pre_target
//            for (int k = n - 1; k > j && targets[k].first - targets[j].first >=
//                                         targets[j].first - targets[i].first; --k) { // cur_target
//                dp[k][j] = max(dp[k][j], dp[j][i] + targets[k].second);
//                sol = max(sol, dp[k][j]);
//            }
//        }
//    }
//    // right to left
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (i != j) {
//                dp[i][j] = 0;
//            } else {
//                dp[i][j] = targets[i].second;
//            }
//        }
//    }
//    for (int i = n - 1; i >= 0; --i) { // pre_pre_target
//        for (int j = i; j >= 0; --j) { // pre_target
//            for (int k = 0; k < j && targets[j].first - targets[k].first >=
//                                     targets[i].first - targets[j].first; ++k) { // cur_target
//                dp[k][j] = max(dp[k][j], dp[j][i] + targets[k].second);
//                sol = max(sol, dp[k][j]);
//            }
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}

/*
ID: izhang01
TASK: pogocow
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pogocow.in", "r", stdin);
    freopen("pogocow.out", "w", stdout);
}

const int maxn = 1e3 + 1;
long long dp[maxn][maxn]; // dp[cur_target][last_target]

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<long long, long long>> targets(n);
    for (int i = 0; i < n; ++i) {
        cin >> targets[i].first >> targets[i].second;
    }
    sort(targets.begin(), targets.end());
    // left to right
    for (int i = 0; i < n; ++i) {
        dp[i][i] = targets[i].second;
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) { // pre_pre_target
        for (int j = i; j < n; ++j) { // pre_target
            for (int k = n - 1; k > j && targets[k].first - targets[j].first >=
                                         targets[j].first - targets[i].first; --k) { // cur_target
                dp[k][j] = max(dp[k][j], dp[j][i] + targets[k].second);
                sol = max(sol, dp[k][j]);
            }
        }
    }
    // right to left
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = targets[i].second;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) { // pre_pre_target
        for (int j = i; j >= 0; --j) { // pre_target
            for (int k = 0; k < j && targets[j].first - targets[k].first >=
                                     targets[i].first - targets[j].first; ++k) { // cur_target
                dp[k][j] = max(dp[k][j], dp[j][i] + targets[k].second);
                sol = max(sol, dp[k][j]);
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
