#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, alph = 26, mxn = 1e5 + 5;

int nxt[alph][mxn], pre[alph][mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n);
    memset(nxt, 0x3f, sizeof(nxt));
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'a';
        if (i) {
            for (int j = 0; j < alph; ++j) {
                pre[j][i] = pre[j][i - 1];
            }
        }
        pre[a[i]][i] = nxt[a[i]][i] = i;
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < alph; ++j) {
            nxt[j][i] = min(nxt[j][i], nxt[j][i + 1]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        long long sol = -1;
        for (int i = 0; i < alph; ++i) {
            int x = nxt[i][l];
            if (x + 1 >= r) {
                continue;
            }
            for (int j = 0; j < alph; ++j) {
                if (i == j) {
                    continue;
                }
                int y = pre[j][r];
                if (y <= x + 1) {
                    continue;
                }
                int m = (x + y) / 2;
                int z1 = nxt[j][m], z2 = pre[j][m];
                long long cur = -1;
                if (z1 > x && z1 < y) {
                    cur = (long long) (y - z1) * (z1 - x);
                }
                if (z2 > x && z2 < y) {
                    cur = max(cur, (long long) (y - z2) * (z2 - x));
                }
                sol = max(sol, cur);
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
