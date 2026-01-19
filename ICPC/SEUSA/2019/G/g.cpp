#include <bits/stdc++.h>

using namespace std;

const int mod = 11092019;

struct item {
    long long mx, sum;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        if (a.mx == b.mx) {
            return {a.mx, (a.sum + b.sum) % mod};
        }
        if (a.mx > b.mx) {
            return a;
        }
        return b;
    }

//    static item single(pair<long long, long long> v) {
//        return {v.first, v.second};
//    }

    void upd(int p, item v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            upd(p, v, 2 * x + 1, lx, m);
        } else {
            upd(p, v, 2 * x + 2, m, rx);
        }
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void upd(int p, item v) {
        upd(p, v, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

const int mxn = 1e6 + 5;

int x[mxn];
vector<int> adj[mxn];

segtree seg;

item sol = seg.neutral;

void dfs(int c, int p) {
    item orig = seg.query(x[c], x[c] + 1);
    item quer = seg.query(0, x[c] + 1);
    ++quer.mx;
    quer.sum = max(quer.sum, (long long) 1);
    sol = seg.merge(sol, quer);
    seg.upd(x[c], quer);
    for (auto &i: adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
    seg.upd(x[c], orig);
}


int main() {
    seg.init(mxn);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(0, -1);
    cout << sol.mx << " " << sol.sum << "\n";
}
