/* Author: izhang05
 * Time: 06-22-2021 16:14:09
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxk = 22;
#define int long long
int a[maxn], dp[maxn][maxk];

int freq[maxn];
int lp = 1, rp = 0, cost = 0;

void update(int l, int r) {
    while (rp < r) {
        rp++;
        cost += freq[a[rp]];
        freq[a[rp]]++;
    }
    while (lp > l) {
        lp--;
        cost += freq[a[lp]];
        freq[a[lp]]++;
    }
    while (rp > r) {
        freq[a[rp]]--;
        cost -= freq[a[rp]];
        rp--;
    }
    while (lp < l) {
        freq[a[lp]]--;
        cost -= freq[a[lp]];
        lp++;
    }
}

void solve(int g, int i, int j, int l, int r) {
    if (i > j) {
        return;
    }
    int mid = (i + j) / 2, best_ind = l;
    for (int k = l; k <= min(mid, r); ++k) {
        update(k, mid);
        int val = dp[k - 1][g - 1] + cost;
        if (val < dp[mid][g]) {
            dp[mid][g] = val;
            best_ind = k;
        }
    }
    solve(g, i, mid - 1, l, best_ind);
    solve(g, mid + 1, j, best_ind, r);
}

signed main() {
    setIO("1");
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        solve(i, 1, n, 1, n);
    }
#ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
#endif
    cout << *min_element(dp[n] + 1, dp[n] + k + 1) << "\n";
    return 0;
}
