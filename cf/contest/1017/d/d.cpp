/* Author: izhang05
 * Time: 08-18-2021 00:15:45
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const int maxn = 12, maxw = 105;

int sol[1 << maxn][maxw];

int cnt[1 << maxn];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                cur |= 1 << j;
            }
        }
        ++cnt[cur];
    }
    memset(sol, -1, sizeof(sol));
    for (int i = 0; i < q; ++i) {
        string tmp;
        int t;
        cin >> tmp >> t;
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (tmp[j] == '1') {
                cur |= 1 << j;
            }
        }
        if (sol[cur][t] != -1) {
            cout << sol[cur][t] << "\n";
            continue;
        }
        for (int j = 0; j < maxw; ++j) {
            sol[cur][j] = 0;
        }
        for (int k = 0; k < (1 << n); ++k) {
            if (!cnt[k]) {
                continue;
            }
            int x = ~(cur ^ k), val = 0;
            for (int l = 0; l < n; ++l) {
                if (x & (1 << l)) {
                    val += w[l];
                }
            }
            if (val < maxw) {
                sol[cur][val] += cnt[k];
            }
        }
        for (int j = 1; j < maxw; ++j) {
            sol[cur][j] += sol[cur][j - 1];
        }
        cout << sol[cur][t] << "\n";
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
