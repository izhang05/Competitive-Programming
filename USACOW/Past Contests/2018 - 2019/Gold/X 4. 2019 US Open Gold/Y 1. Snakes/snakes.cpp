/*
ID: izhang01
TASK: snakes
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
}

int n, k;
vector<int> a;

const int maxn = 401, inf = 1e9;

int dp[maxn][maxn], pre[maxn];

int max_val(int lo, int hi) {
    int sol = 0;
    for (int i = lo; i < hi; ++i) {
        sol = max(sol, a[i]);
    }
    return sol;
}

int solve(int pos, int remain) {
    if (remain == 0) {
        dp[pos][remain] = max_val(0, pos) * (pos) - (pre[pos]);
    }
    if (dp[pos][remain] != inf) {
        return dp[pos][remain];
    }
    int &cur = dp[pos][remain];
    for (int i = pos - 1; i >= remain; --i) {
        cur = min(cur, max_val(i, pos) * (pos - i) - (pre[pos] - pre[i]) + solve(i, remain - 1));
    }
    //        cout << max_val(i, pos) * (pos - i + 1) << " " << pre[pos] - pre[i] << "\n";
    return cur;
}

int main() {
    setIO();
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            dp[i][j] = inf;
        }
    }
    cout << solve(n, k) << "\n";
    return 0;
}
