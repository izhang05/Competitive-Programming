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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e6 + 5;

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

    long long query(int l, int r) {
        return query(l, r, 0, 0, size).sum;
    }
};
int a[maxn];

int main() {
    setIO("18");
    int n;
    cin >> n;
    segtree seg;
    seg.init(maxn);
    vector<array<int, 4>> q;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6;
        y1 += 1e6;
        x2 += 1e6;
        y2 += 1e6;
        if (x1 == x2) {
            if (abs(y2 - y1) >= 2) {
                q.push_back({y1, 1, x1, 0});
                q.push_back({y2, 3, x1, 0});
            }
        } else {
            if (abs(x2 - x1) >= 2) {
                q.push_back({y1, 2, x1, x2});
            }
        }
    }
    sort(q.begin(), q.end());
    long long sol = 0;
    for (auto &i : q) {
        int t = i[1];
        if (t == 1) {
            seg.upd(i[2], ++a[i[2]]);
        } else if (t == 2) {
            sol += seg.query(i[2] + 1, i[3]);
        } else {
            seg.upd(i[2], --a[i[2]]);
        }
    }
    cout << sol << "\n";
    return 0;
}
