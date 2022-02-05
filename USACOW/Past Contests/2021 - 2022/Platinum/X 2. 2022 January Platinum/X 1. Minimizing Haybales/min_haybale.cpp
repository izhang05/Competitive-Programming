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
const int inf = 0x3f3f3f3f;
struct item {
    int mx, mn;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0, inf};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size, neutral);
    }

    static item merge(item a, item b) {
        return {max(a.mx, b.mx), min(a.mn, b.mn)};
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = {v, v};
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

    void upd(int p, long long v) {
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        seg.upd(i, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> nums;
        for (int j = i; j < n; ++j) {
            nums.emplace_back(a[j], j);
        }
        sort(nums.begin(), nums.end());
        for (auto &j : nums) {
            item cur = seg.query(i, j.second);
            if (cur.mx <= j.first + k && cur.mn >= j.first - k) {
                for (int l = j.second - 1; l >= i; --l) {
                    swap(a[l], a[l + 1]);
                    seg.upd(l + 1, a[l + 1]);
                }
                seg.upd(i, a[i]);
                break;
            }
        }
    }
    for (auto &i : a) {
        cout << i << "\n";
    }

    return 0;
}
