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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

struct item {
    long long sum;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {a.sum + b.sum};
    }

    static item single(int v) {
        return {v};
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v);
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

    void upd(int p, int v) {
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


int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<int> a(2 * n);
    map<int, pair<int, int>> ind;
    for (int i = 0; i < n; ++i) {
        ind[i].first = inf, ind[i].second = 0;
    }
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        --a[i];
        ind[a[i]].first = min(ind[a[i]].first, i);
        ind[a[i]].second = max(ind[a[i]].second, i);
    }
    segtree seg;
    seg.init(2 * n);
    vector<int> sol(n);
    for (int i = 0; i < 2 * n; ++i) {
        if (ind[a[i]].second == i) {
            sol[a[i]] = ind[a[i]].second - ind[a[i]].first - 1 - 2 * (int) seg.query(ind[a[i]].first, ind[a[i]].second + 1).sum;
            seg.upd(ind[a[i]].first, 1);
        }
    }
    print(sol);
    return 0;
}
