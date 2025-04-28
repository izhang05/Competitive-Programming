/* Author: izhang
 * Time: 06-25-2024 10:35:01
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct segtree {
    struct item {
        long long mn, mx;
    };
    int size{};
    vector<item> t;
    item neutral = {INFL, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {min(a.mn, b.mn), max(a.mx, b.mx)};
    }

    static item single(long long v) {
        return {v, v};
    }

    void upd(int p, long long v, int x, int lx, int rx) {
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

void test_case() {
    int n;
    cin >> n;
    map<int, int> ind;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ind[a[i]];
    }
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (auto &i : queries) {
        cin >> i.first >> i.second;
        --i.first;
        ind[i.second];
    }
    int cur_ind = 0;
    for (auto &i : ind) {
        i.second = cur_ind++;
    }
    segtree seg1;
    seg1.init(n);
    for (int i = 0; i < n; ++i) {
        a[i] = ind[a[i]];
        seg1.upd(i, a[i]);
    }
    for (auto &i : queries) {
        i.second = ind[i.second];
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
