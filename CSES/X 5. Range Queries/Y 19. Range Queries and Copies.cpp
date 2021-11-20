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

using namespace std;
struct node {
    long long sum;
    node *l, *r;
    node(long long x) : sum(x), l(nullptr), r(nullptr) {}
    node(node *nl, node *nr) {
        l = nl, r = nr;
        sum = 0;
        if (l) {
            sum += l->sum;
        }
        if (r) {
            sum += r->sum;
        }
    }
    node(node *n) : sum(n->sum), l(n->l), r(n->r) {}
};
int n;
vector<int> a;

struct segtree {
    int size{}, cnt = 1;
    vector<node *> roots;

    void init() {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        roots.resize(2 * size);
    }

    node *upd(node *cur, int p, long long v, int lx, int rx) {
        if (rx - lx == 1) {
            return new node(v);
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            return new node(upd(cur->l, p, v, lx, m), cur->r);
        } else {
            return new node(cur->l, upd(cur->r, p, v, m, rx));
        }
    }

    node *build(int lx = 0, int rx = n) {
        if (rx - lx == 1) {
            return new node(a[lx]);
        }
        int mid = (lx + rx) / 2;
        return new node(build(lx, mid), build(mid, rx));
    }

    void upd(int k, int p, int x) {
        roots[k] = upd(roots[k], p, x, 0, n);
    }

    long long query(node *cur, int l, int r, int lx = 0, int rx = n) {
        if (r <= lx || l >= rx) {
            return 0;
        }
        if (l <= lx && rx <= r) {
            return cur->sum;
        }
        int m = (lx + rx) / 2;
        return query(cur->l, l, r, lx, m) + query(cur->r, l, r, m, rx);
    }

    void copy(int k) {
        roots[cnt++] = new node(roots[k]);
    }
};

int main() {
    setIO("19");
    int q;
    cin >> n >> q;
    segtree seg;
    seg.init();
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    seg.roots[0] = seg.build();
    while (q--) {
        int t, k;
        cin >> t >> k;
        --k;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            seg.upd(k, p - 1, x);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.query(seg.roots[k], l - 1, r) << "\n";
        } else {
            seg.copy(k);
        }
    }
    return 0;
}
