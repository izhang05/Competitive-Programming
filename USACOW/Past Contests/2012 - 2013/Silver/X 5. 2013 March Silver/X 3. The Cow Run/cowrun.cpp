/*
ID: izhang01
TASK: cowrun
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("cowrun.in", "r", stdin);
    //    freopen("cowrun.out", "w", stdout);
    //    freopen("cowrun.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e3 + 5;
const long long inf = 1e18;
pair<long long, long long> dp[maxn][maxn][2];


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(0);
    sort(a.begin(), a.end());
    int ind = 0;
    ++n;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ind = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = {inf, inf};
            }
        }
    }
    dp[ind][ind][0] = make_pair(0, 0);
    for (int d = 0; d < n; ++d) {
        for (int i = 0; i + d < n; ++i) {
            int j = i + d;
            for (int k = 0; k < 2; ++k) {
                pair<long long, long long> cur = dp[i][j][k];
                if (cur.first == inf) {
                    continue;
                }
                if (i > 0) {
                    long long add;
                    if (k == 0) {
                        add = a[i] - a[i - 1];
                    } else {
                        add = a[j] - a[i - 1];
                    }
                    dp[i - 1][j][0] = min(dp[i - 1][j][0], {cur.first + cur.second + add, cur.second + add});
                }
                if (j + 1 < n) {
                    long long add;
                    if (k == 0) {
                        add = a[j + 1] - a[i];
                    } else {
                        add = a[j + 1] - a[j];
                    }
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], {cur.first + cur.second + add, cur.second + add});
                }
            }
        }
    }
    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]).first << "\n";
    return 0;
}
