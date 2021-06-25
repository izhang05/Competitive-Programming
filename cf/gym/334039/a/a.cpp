/* Author: izhang05
 * Time: 06-24-2021 20:31:59
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

struct item {
    int sum;
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

segtree lef, rig;
int n;
int mx(int x) {
    return max({lef.query(0, x).sum, rig.query(0, x).sum, lef.query(x, n).sum, rig.query(x, n).sum});
}

int main() {
    setIO("balancing");
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](auto lef, auto rig) {
        return lef.second == rig.second ? lef.first < rig.first : lef.second < rig.second;
    });
    int pre = a[0].second, ind = 0;
    a[0].second = ind;
    for (int i = 1; i < n; ++i) {
        if (a[i].second != pre) {
            ++ind;
            pre = a[i].second;
        }
        a[i].second = ind;
    }
    sort(a.begin(), a.end());
    pre = a[0].first, ind = 0;
    a[0].first = ind;
    for (int i = 1; i < n; ++i) {
        if (a[i].first != pre) {
            ++ind;
            pre = a[i].first;
        }
        a[i].first = ind;
    }
    int sol = 1e9;
    lef.init(n), rig.init(n);
    vector<int> lef_val(n), rig_val(n);
    for (auto &i : a) {
        rig.upd(i.second, ++rig_val[i.second]);
    }
    for (int i = 0; i < n; ++i) {
        int cur = a[i].first;
        rig.upd(a[i].second, --rig_val[a[i].second]);
        lef.upd(a[i].second, ++lef_val[a[i].second]);
        while (i + 1 < n && a[i + 1].first == cur) {
            ++i;
            rig.upd(a[i].second, --rig_val[a[i].second]);
            lef.upd(a[i].second, ++lef_val[a[i].second]);
        }
        // find last ind res where max(lef[0,res), rig[0,res)) < max(lef[res,n), rig[res,n))
        int l = 0, r = n - 1, mid, res = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            int bl = lef.query(0, mid).sum, br = rig.query(0, mid).sum, tl = lef.query(mid, n).sum, tr = rig.query(mid, n).sum;
            if (max(bl, br) <= max(tl, tr)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        assert(res != -1);
        sol = min({sol, mx(res), mx(res + 1)});
    }
    cout << sol << "\n";
    return 0;
}
