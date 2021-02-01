//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//#ifdef DEBUG
//    freopen("1.in", "r", stdin);
//#endif
//}
//const int maxn = 5e4 + 5, maxk = 50;
//const long long inf = 1e18;
//long long dp[maxn];
//bool grid[maxk][maxk];
//set<int> loc[maxk];
//
//int main() {
//    setIO();
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        --a[i];
//        loc[a[i]].insert(i);
//        dp[i] = inf;
//    }
//    for (int i = 0; i < k; ++i) {
//        string s;
//        cin >> s;
//        for (int j = 0; j < k; ++j) {
//            if (s[j] == '1') {
//                grid[i][j] = true;
//            }
//        }
//    }
//    dp[0] = 0;
//    queue<pair<long long, long long>> cur;
//    cur.push({0, 0});
//    while (!cur.empty()) {
//        int i = cur.front().first;
//        if (dp[i] != cur.front().second) {
//            cur.pop();
//            continue;
//        }
//        cur.pop();
//        int cow = a[i];
//        for (int j = 0; j < k; ++j) {
//            if (grid[cow][j]) {
//                auto it = loc[j].lower_bound(i);
//                if (it != loc[j].begin()) {
//                    int pre = *prev(it);
//                    assert(i > pre);
//                    if (dp[i] + i - pre < dp[pre]) {
//                        cur.push({pre, dp[pre] = dp[i] + i - pre});
//                    }
//                }
//                if (it != loc[j].end()) {
//                    if (*it == i) {
//                        ++it;
//                        if (it == loc[j].end()) {
//                            continue;
//                        }
//                    }
//                    int next = *it;
//                    if (dp[i] + next - i < dp[next]) {
//                        cur.push({next, dp[next] = dp[i] + next - i});
//                    }
//                }
//            }
//        }
//    }
//    //    cout << "\n";
//    //    for (int i = 0; i < n; ++i) {
//    //        cout << dp[i] << "\n";
//    //    }
//    if (dp[n - 1] == inf) {
//        cout << -1 << "\n";
//    } else {
//        cout << dp[n - 1] << "\n";
//    }
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("1.in", "r", stdin);
#endif
}
const int maxn = 5e4 + 5, maxk = 50;
const long long inf = 1e18;
long long dp[maxn];
bool grid[maxk][maxk];
set<int> loc[maxk];

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        loc[a[i]].insert(i);
        dp[i] = inf;
    }
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < k; ++j) {
            if (s[j] == '1') {
                grid[i][j] = true;
            }
        }
    }
    dp[0] = 0;
    queue<pair<long long, long long>> cur;
    cur.push({0, 0});
    while (!cur.empty()) {
        int i = cur.front().first;
        if (dp[i] != cur.front().second) {
            cur.pop();
            continue;
        }
        cur.pop();
        int cow = a[i];
        for (int j = 0; j < k; ++j) {
            if (grid[cow][j]) {
                if (!grid[j][j]) {
                    for (int next : loc[j]) {
                        if (dp[i] + abs(i - next) < dp[next]) {
                            cur.push({next, dp[next] = dp[i] + abs(i - next)});
                        }
                    }
                } else {
                    auto it = loc[j].lower_bound(i);
                    if (it != loc[j].begin()) {
                        int pre = *prev(it);
                        assert(i > pre);
                        if (dp[i] + i - pre < dp[pre]) {
                            cur.push({pre, dp[pre] = dp[i] + i - pre});
                        }
                    }
                    if (it != loc[j].end()) {
                        if (*it == i) {
                            ++it;
                            if (it == loc[j].end()) {
                                continue;
                            }
                        }
                        int next = *it;
                        if (dp[i] + next - i < dp[next]) {
                            cur.push({next, dp[next] = dp[i] + next - i});
                        }
                    }
                }
            }
        }
    }
    //    cout << "\n";
    //    for (int i = 0; i < n; ++i) {
    //        cout << dp[i] << "\n";
    //    }
    if (dp[n - 1] == inf) {
        cout << -1 << "\n";
    } else {
        cout << dp[n - 1] << "\n";
    }

    return 0;
}
