/* Author: izhang05
 * Time: 06-22-2021 17:19:45
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 35005, maxk = 52;
#define int long long
int a[maxn], dp[maxn][maxk];

int freq[maxn];
int lp = 1, rp = 0, cost = 0;

void update(int l, int r) {
    while (rp < r) {
        rp++;
        cost += min(1ll, freq[a[rp]]);
        freq[a[rp]]++;
    }
    while (lp > l) {
        lp--;
        cost += min(1ll, freq[a[lp]]);
        freq[a[lp]]++;
    }
    while (rp > r) {
        freq[a[rp]]--;
        cost -= min(1ll, freq[a[rp]]);
        rp--;
    }
    while (lp < l) {
        freq[a[lp]]--;
        cost -= min(1ll, freq[a[lp]]);
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
        int val = dp[k - 1][g - 1] + mid - k + 1 - cost;
        if (val > dp[mid][g]) {
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
    cout << *max_element(dp[n] + 1, dp[n] + k + 1) << "\n";
    return 0;
}
