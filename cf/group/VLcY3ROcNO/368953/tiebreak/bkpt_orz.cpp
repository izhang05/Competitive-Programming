#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define MAXN 100100
#define SQRT 400
#define LOG 20

int n, q;
int a[MAXN];
vector<int> g[MAXN];

vector<array<int, 4>> query[MAXN];

int ct = 0;
int ti[MAXN], to[MAXN];
int dep[MAXN];
int jp[LOG][MAXN];
int ans[MAXN];

struct Fenwick {
    int N;
    vector<ll> bit;

    void init(int _n) {

        N = _n + 5;
        bit.resize(N + 5);
        for (int i = 0; i < N + 5; i++)
            bit[i] = 0;
    }

    void upd(int c, int v) {

        c += 2;
        while (c <= N) {
            bit[c] += v;
            c += (c & (-c));
        }
    }

    ll query(int c) {

        c += 2;
        ll res = 0;
        while (c) {
            res += bit[c];
            c -= (c & (-c));
        }
        return res;
    }

} helper;

void dfs(int c, int l, int d) {

    dep[c] = d;
    jp[0][c] = l;
    ti[c] = ct++;
    for (int i : g[c]) {
        if (i == l) continue;
        dfs(i, c, d + 1);
    }
    to[c] = ct - 1;
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);

    int tj = dep[y] - dep[x];
    for (int i = 0; i < LOG; i++)
        if (tj & (1 << i))
            y = jp[i][y];

    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (jp[i][x] == jp[i][y]) continue;
        x = jp[i][x];
        y = jp[i][y];
    }
    return jp[0][x];
}

int cv[MAXN];

void solve(int color) {

    if (!query[color].size()) return;

    for (auto [ty, x, y, z] : query[color]) {

        if (ty == 1) {

            // cout << "updating " << ti[x] << " -> " << to[x] << " with " << y << endl;
            cv[x] += y;
            helper.upd(ti[x], y);
            helper.upd(to[x] + 1, -y);

            // cout << helper.query(0) << " " << helper.query(1) << endl;

        } else {

            int l = lca(x, y);
            // cout  << "lca of " << x << " and " << y << " is " << l << endl;
            ll res = helper.query(ti[x]) + helper.query(ti[y]);
            // cout << res << " so far " << endl;
            res -= 2 * helper.query(ti[l]);
            // cout << res << " so far " << endl;
            res += cv[l];
            // cout << "got " << res << endl;

            ans[z] = res;
        }
    }

    for (auto [ty, x, y, z] : query[color]) {

        if (ty == 1) {

            cv[x] -= y;
            helper.upd(ti[x], -y);
            helper.upd(to[x] + 1, y);
        }
    }

    // cout << "RESET" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        query[a[i]].push_back({1, i, 1, 0});
    }
    for (int i = 1; i < n; i++) {
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }

    dfs(1, 1, 0);

    helper.init(n);
    for (int i = 1; i < LOG; i++)
        for (int j = 1; j <= n; j++)
            jp[i][j] = jp[i - 1][jp[i - 1][j]];

    fill(ans, ans + MAXN, -1);

    for (int tt = 0; tt < q; tt++) {

        int ty;
        scanf("%d", &ty);
        if (ty == 1) {
            int ind, nt;
            scanf("%d%d", &ind, &nt);
            query[a[ind]].push_back({1, ind, -1, 0});
            a[ind] = nt;
            query[a[ind]].push_back({1, ind, 1, 0});
        } else {
            int nt, x, y;
            scanf("%d%d%d", &x, &y, &nt);
            query[nt].push_back({2, x, y, tt});
        }
    }

    for (int i = 1; i < MAXN; i++) {
        solve(i);
    }

    for (int i = 0; i < MAXN; i++) {
        if (ans[i] != -1) {
            printf("%d\n", ans[i]);
        }
    }
}