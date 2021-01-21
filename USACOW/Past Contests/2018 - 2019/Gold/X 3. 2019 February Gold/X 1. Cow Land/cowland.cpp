/*
ID: izhang01
TASK: cowland
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, logn = 30;
int anc[maxn][logn];

int st[maxn], en[maxn], cnt, t_n, par[maxn];
vector<int> adj[maxn];
long long t[2 * maxn];

long long calc(long long a, long long b) {
    return a ^ b;
}

void update(int p, long long val) {
    for (t[p += t_n] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]); // p ^ 1 is the other child for node p / 2
    }
}

long long query(int l, int r) {
    long long res = 0;
    for (l += t_n, r += t_n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++]);
        }
        if (r & 1) {
            res = calc(res, t[--r]);
        }
    }
    return res;
}

void dfs(int c, int p) {
    par[c] = p;
    st[c] = cnt++;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
    en[c] = cnt - 1;
}

int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    t_n = n + 1;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    int b, c;
    for (int i = 0; i < n - 1; ++i) {
        cin >> b >> c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs(1, 1);
    for (int i = 1; i < n + 1; ++i) {
        update(st[i], query(st[i], 1 + st[i]) ^ a[i]);
        update(1 + en[i], query(1 + en[i], 2 + en[i]) ^ a[i]);
    }
    for (int i = 1; i < n + 1; ++i) {
        anc[i][0] = par[i];
    }
    for (int j = 1; j < logn; ++j) {
        for (int i = 1; i < n + 1; ++i) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }

    int d;
    for (int i = 0; i < q; ++i) {
        cin >> d;
        if (d == 1) {
            cin >> b >> c;
            update(st[b], query(st[b], 1 + st[b]) ^ a[b] ^ c);
            update(1 + en[b], query(1 + en[b], 2 + en[b]) ^ a[b] ^ c);
            a[b] = c;
        } else {
            cin >> b >> c;
            int lca = b, c_copy = c;
            while (c_copy) {
                lca = anc[lca][int(log2(c_copy))];
                c_copy -= 1 << int(log2(c_copy));
            }
            cout << lca << "\n";
            cout << query(0, st[b] + 1) << "\n";
            cout << query(0, st[c] + 1) << "\n";
            cout << a[lca] << "\n";
            cout << (query(0, st[b] + 1) ^ query(0, st[c] + 1) ^ a[lca]) << "\n";
            cout << "\n";
        }
    }
    return 0;
}
