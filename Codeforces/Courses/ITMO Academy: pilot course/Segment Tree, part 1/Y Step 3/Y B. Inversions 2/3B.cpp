#include <bits/stdc++.h>

using namespace std;

#define DEBUG

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

    int query(int x, int lx, int rx, int k) {
        if (rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
        if (t[2 * x + 1].sum > k) {
            return query(2 * x + 1, lx, m, k);
        } else {
            return query(2 * x + 2, m, rx, k - t[2 * x + 1].sum);
        }
    }

    int query(int k) {
        return query(0, 0, size, k);
    }
};


int main() {
    setIO("1");
    int n;
    cin >> n;
    segtree seg;
    seg.init(n);
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        seg.upd(i, 1);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        int cur = seg.query(a[i]);
        sol[i] = n - cur;
        seg.upd(cur, 0);
    }
    reverse(sol.begin(), sol.end());
    print(sol);
    return 0;
}
