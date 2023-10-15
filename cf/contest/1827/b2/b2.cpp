/* Author: izhang
 * Time: 10-14-2023 16:22:43
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
struct item {
    long long mx, mn;
};

int n;
struct segtree {
    int size{};
    vector<item> t;
    item neutral = {-1, n};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.clear();
        t.resize(2 * size, neutral);
    }

    static item merge(item a, item b) {
        return {max(a.mx, b.mx), min(a.mn, b.mn)};
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
    cin >> n;
    vector<int> a(n);
    segtree seg;
    seg.init(n);
    set<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    map<int, int> ind;
    int cur_ind = 0;
    for (auto &i : nums) {
        ind[i] = cur_ind++;
    }
    for (auto &i : a) {
        i = ind[i];
    }
    long long sol = 0;
    for (long long i = 0; i < n; ++i) {
        sol += (i * (i + 1)) / 2;
    }
    vector<long long> res(n);
    vector<vector<int>> q(n);
    for (int i = 0; i < n; ++i) {
        long long mid = seg.query(0, a[i]).mx;
        if (mid >= 0) {
            q[mid].emplace_back(i);
        }
        seg.upd(a[i], i);
    }
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        for (auto &j : q[i]) {
            long long l = seg.query(a[j], n).mx;
            res[j] = i - l;
        }
        seg.upd(a[i], i);
    }
    seg.init(n);
    for (int i = n - 1; i >= 0; --i) {
        long long r = seg.query(0, a[i]).mn;
        sol -= res[i] * (r - i);
        dbg() << i << " " << res[i] * (r - i);
        seg.upd(a[i], i);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
        dbg();
    }
    return 0;
}
