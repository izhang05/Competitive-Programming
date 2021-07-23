/* Author: izhang05
 * Time: 07-23-2021 14:37:20
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
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

int main() {
    setIO("4");

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int ind = 0, pre = a[0].first;
    for (int i = 0; i < n; ++i) {
        if (a[i].first == pre) {
            a[i].first = ind;
        } else {
            pre = a[i].first;
            a[i].first = ++ind;
        }
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left.second == right.second ? left.first < right.first : left.second < right.second;
    });
    ind = 0, pre = a[0].second;
    for (int i = 0; i < n; ++i) {
        if (a[i].second == pre) {
            a[i].second = ind;
        } else {
            pre = a[i].second;
            a[i].second = ++ind;
        }
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left.second == right.second ? left.first < right.first : left.second > right.second;
    });
    long long sol = 0;
    segtree seg;
    seg.init(n);
    int last_y = -1, last_x = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i].second != last_y) {
            last_y = a[i].second;
            last_x = -1;
            for (int j = i; j < n && a[j].second == a[i].second; ++j) {
                seg.upd(a[j].first, 1);
            }
        }
        sol += seg.query(last_x + 1, a[i].first + 1) * seg.query(a[i].first, n);
        last_x = a[i].first;
    }
    cout << sol << "\n";
    return 0;
}
