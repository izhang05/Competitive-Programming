/* Author: izhang05
 * Time: 06-23-2021 18:37:50
**/
#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr \
    if (false) cerr
#endif
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 35005, maxk = 105;
int dp[maxn][maxk], lp = 1, rp = 0, cost = 0;
vector<int> a;
deque<int> occ[maxn];

void update(int l, int r) {
    while (rp < r) {
        ++rp;
        if (!occ[a[rp]].empty()) {
            cost += rp - occ[a[rp]].back();
        }
        occ[a[rp]].push_back(rp);
    }
    while (lp > l) {
        --lp;
        if (!occ[a[lp]].empty()) {
            cost += occ[a[lp]].front() - lp;
        }
        occ[a[lp]].push_front(lp);
    }
    while (rp > r) {
        occ[a[rp]].pop_back();
        if (!occ[a[rp]].empty()) {
            cost -= rp - occ[a[rp]].back();
        }
        --rp;
    }
    while (lp < l) {
        occ[a[lp]].pop_front();
        if (!occ[a[lp]].empty()) {
            cost -= occ[a[lp]].front() - lp;
        }
        ++lp;
    }
}

void solve(int g, int i, int j, int l, int r) {
    if (j < i) {
        return;
    }
    int mid = (i + j) / 2, best_ind = l;
    for (int k = l; k <= min(mid, r); ++k) {
        update(k, mid);
        int cur = dp[k - 1][g - 1] + cost;
        if (cur < dp[mid][g]) {
            dp[mid][g] = cur;
            best_ind = k;
        }
    }
    solve(g, i, mid - 1, l, best_ind);
    solve(g, mid + 1, j, best_ind, r);
}

int main() {
    setIO("1");
    int n, k;
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));

    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        solve(i, 1, n, 1, n);
    }
    cout << dp[n][k] << "\n";
    return 0;
}
