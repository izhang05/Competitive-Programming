/*
ID: izhang01
TASK: dec
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("dec.in", "r", stdin);
    freopen("dec.out", "w", stdout);
    freopen("dec.out", "w", stderr);
}
//#define DEBUG
const int maxn = 20;

int dp[1 << maxn];
int skill[maxn][maxn];

vector<pair<int, int>> bonus[maxn];

void award(int &score, int event) {
    for (auto i : bonus[event]) {
        if (score < i.first) {
            break;
        }
        score += i.second;
    }
}

int main() {
    setIO();
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < b; ++i) {
        int a;
        pair<int, int> cur;
        cin >> a >> cur.first >> cur.second;
        --a;
        bonus[a].push_back(cur);
    }
    for (int i = 0; i < n; ++i) {
        sort(bonus[i].begin(), bonus[i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> skill[i][j];
        }
    }
    for (int mask = 1; mask < (1 << n) + 1; ++mask) {
        int ind = __builtin_popcount(mask);
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                dp[mask] = max(dp[mask], dp[mask ^ (1 << i)] + skill[i][ind - 1]);
            }
        }
        award(dp[mask], ind - 1);
    }
    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}
