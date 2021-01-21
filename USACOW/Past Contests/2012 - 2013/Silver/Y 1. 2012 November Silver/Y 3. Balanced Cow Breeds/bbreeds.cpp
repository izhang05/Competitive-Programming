/*
ID: izhang01
TASK: bbreeds
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bbreeds.in", "r", stdin);
    freopen("bbreeds.out", "w", stdout);
}

const int mod = 2012, maxn = 1e3;
int dp[maxn][maxn], unmatched[maxn + 1];
string s;
int n;

int sol(int i, int a) {
    if (i == n) {
        return 1;
    }
    if (dp[i][a] >= 0) {
        return dp[i][a];
    }
    int res = 0;
    if (s[i] == '(') {
        res = sol(i + 1, a + 1) + sol(i + 1, a);
    } else {
        if (a > 0) {
            res += sol(i + 1, a - 1);
        }
        if (unmatched[i] - a > 0) {
            res += sol(i + 1, a);
        }
    }
    return dp[i][a] = res % mod;
}

int main() {
    setIO();
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = -1;
        }
        unmatched[i + 1] = unmatched[i] + (s[i] == '(' ? 1 : -1);
    }
    cout << sol(0, 0) << "\n";
    return 0;
}


