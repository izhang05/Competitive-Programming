/*
ID: izhang01
TASK: cbarn
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    freopen("cbarn.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e3 + 5, maxk = 8;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn][maxk], pre[maxn], pre_mult[maxn];

long long cost(int x, int y) {
    assert(x <= y);
    return pre_mult[y] - pre_mult[x - 1] - (x - 1) * (pre[y] - pre[x - 1]);
}

void solve(int g, int i, int j, int l, int r) {
    if (j < i) {
        return;
    }
    int mid = (i + j) / 2, best_ind = l;
    for (int k = l; k <= min(mid, r); ++k) {
        long long cur = dp[k - 1][g - 1] + cost(k, mid);
        if (cur < dp[mid][g]) {
            dp[mid][g] = cur;
            best_ind = k;
        }
    }

    solve(g, i, mid - 1, l, best_ind);
    solve(g, mid + 1, j, best_ind, r);
}

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = inf;
    for (int _ = 0; _ < n; ++_) {
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        pre[0] = pre_mult[0] = 0;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + a[i];
            pre_mult[i + 1] = pre_mult[i] + i * a[i];
        }
        for (int i = 1; i <= k; ++i) {
            solve(i, 1, n, 1, n);
        }
        sol = min(sol, *min_element(dp[n] + 1, dp[n] + k + 1));
        rotate(a.begin(), a.end() - 1, a.end());
    }
    cout << sol << "\n";
    return 0;
}
