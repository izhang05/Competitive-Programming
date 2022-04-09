/* Author: izhang
 * Time: 03-31-2022 11:08:49
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

    static item single(long long v) {
        return {v};
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
        upd(p, v + query(p, p + 1).sum, 0, 0, size);
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
    string s;
    cin >> s;
    vector<int> pre(n + 1);
    array<segtree, 3> seg;
    for (int i = 0; i < 3; ++i) {
        seg[i].init(n);
    }
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i];
        if (s[i] == '-') {
            ++pre[i + 1];
        } else {
            --pre[i + 1];
        }
        int m = abs(pre[i + 1] % 3);
        seg[m].upd((pre[i + 1] - m) / 3, 1);
        dbg() << m << " " << (pre[i + 1] - m) / 3;
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        int m = abs(pre[i] % 3), cur = (pre[i] - m) / 3;
        sol += seg[m].query(cur, n).sum;
        cout << i << " " << seg[m].query(cur, n).sum << "\n";
        m = abs(pre[i + 1] % 3);
        seg[m].upd((pre[i + 1] - m) / 3, -1);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        dbg() << test_case_number;
        test_case();
    }
    return 0;
}
