#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


const int maxn = 2e5;
long long t[4 * maxn];
int n, a[maxn];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
    }
}

long long query(int v, int tl, int tr, int pos, long long sol) {
    if (tl == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        sol += t[v] + query(v * 2, tl, tm, pos, sol);
        return sol;
    } else {
        sol += t[v] + query(v * 2 + 1, tm + 1, tr, pos, sol);
        return sol;
    }
}

void upd(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        t[v] += val;
    } else {
        int tm = (tl + tr) / 2;
        upd(v * 2, tl, tm, l, min(r, tm), val);
        upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
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
    int b, c, d, e;
    for (int i = 0; i < q; ++i) {
        cin >> b;
        if (b == 2) {
            cin >> c;
            cout << query(1, 1, n, c, 0) << "\n";
        } else {
            cin >> c >> d >> e;
            upd(1, 1, n, c, d, e);
        }
    }
    return 0;
}
