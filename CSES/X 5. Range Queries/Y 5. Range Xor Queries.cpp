#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 2e5;
int n, a[maxn];

unsigned long long t[4 * maxn];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = t[2 * v] ^ t[2 * v + 1];
    }
}

unsigned long long query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (tl == l && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) ^ query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            upd(v * 2, tl, tm, pos, val);
        } else {
            upd(v * 2 + 1, tm + 1, tr, pos, val);
        }
        t[v] = t[2 * v] ^ t[2 * v + 1];
    }
}


int main() {
    setIO();
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    int b, c;
    for (int i = 0; i < q; ++i) {
        cin >> b >> c;
        cout << query(1, 1, n, b, c) << "\n";
    }

    return 0;
}
