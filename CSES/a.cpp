#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
struct node {
    int sum, lazy, lx{}, rx{}, lc, rc;
    node() : sum(0), lazy(0), lc(-1), rc(-1) {}
};

struct segtree {
    int size = 1, cnt = 1;
    vector<node> t;

    void init(int n) {
        while (size < n) {
            size *= 2;
        }
        t.resize(64 * size);
    }

    void create(int x) {
        int m = (t[x].lx + t[x].rx) / 2;
        if (t[x].lc == -1) {
            t[x].lc = cnt++;
            t[t[x].lc].lx = t[x].lx;
            t[t[x].lc].rx = m;
        }
        if (t[x].rc == -1) {
            t[x].rc = cnt++;
            t[t[x].rc].lx = m;
            t[t[x].rc].rx = t[x].rx;
        }
    }

    void propagate(int x) {
        if (t[x].rx - t[x].lx == 1) {
            return;
        }
        if (t[x].lazy) {
            int m = (t[x].lx + t[x].rx) / 2;
            create(x);
            t[t[x].lc].sum = m - t[x].lx;
            t[t[x].rc].sum = t[x].rx - m;
            t[t[x].lc].lazy = t[t[x].rc].lazy = 1;
            t[x].lazy = 0;
        }
    }

    void upd(int x, int l, int r) {
        if (t[x].lx >= r || t[x].rx <= l) {
            return;
        }
        if (t[x].lx >= l && t[x].rx <= r) {
            t[x].lazy = 1;
            t[x].sum = t[x].rx - t[x].lx;
            return;
        }
        propagate(x);
        create(x);
        upd(t[x].lc, l, r), upd(t[x].rc, l, r);
        t[x].sum = t[t[x].lc].sum + t[t[x].rc].sum;
    }

    int query(int x, int l, int r) {
        if (t[x].lx >= r || t[x].rx <= l) {
            return 0;
        }
        if (t[x].lx >= l && t[x].rx <= r) {
            return t[x].sum;
        }
        propagate(x);
        create(x);
        return query(t[x].lc, l, r) + query(t[x].rc, l, r);
    }
};

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("1");

    int m;
    cin >> m;
    segtree seg;
    seg.init(m);
    seg.t[0].lx = 0, seg.t[0].rx = 1e9;
    int c = 0;
    while (m--) {
        int t, x, y;
        cin >> t >> x >> y;
        --x, --y;
        if (t == 1) {
            c = seg.query(0, x + c, y + c + 1);
            cout << c << "\n";
        } else {
            seg.upd(0, x + c, y + c + 1);
        }
    }
    return 0;
}
