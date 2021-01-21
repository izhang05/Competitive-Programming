///*
//ID: izhang01
//TASK: msched
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
//    freopen("msched.in", "r", stdin);
//    freopen("msched.out", "w", stdout);
//}
//
//
//int main() {
//    setIO();
//    int n;
//    cin >> n;
//    vector<pair<int, int> > cows(n);
//    int max_d = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> cows[i].second >> cows[i].first;
//        max_d = max(max_d, cows[i].first);
//    }
//    sort(cows.begin(), cows.end());
//    int dp[n][max_d + 1];
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < max_d + 1; ++j) {
//            dp[i][j] = 0;
//        }
//    }
//    dp[0][1] = cows[0].second;
//    for (int i = 1; i < n; ++i) {
//        for (int j = 0; j < cows[i].first; ++j) {
//            dp[i][j + 1] = max((short) dp[i - 1][j + 1], (short) (dp[i - 1][j] + cows[i].second));
//        }
//    }
//    int sol = 0;
//    for (int i : dp[n - 1]) {
//        sol = max(sol, i);
//    }
//    cout << sol << "\n";
//    return 0;
//}

/*
ID: izhang01
TASK: msched
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("msched.in", "r", stdin);
    freopen("msched.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int> > cows(n);
    int max_d = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].second >> cows[i].first;
        cows[i].first = -cows[i].first;
        max_d = max(max_d, -cows[i].first);
    }
    sort(cows.begin(), cows.end());
    priority_queue<int> cur;
    int i = 0, sol = 0;
    for (int t = max_d + 1; t > 0; --t) {
        while (-cows[i].first >= t) {
            cur.push(cows[i].second);
            ++i;
        }
        if (!cur.empty()) {
            sol += cur.top();
            cur.pop();
        }
    }
    cout << sol << "\n";
    return 0;
}
