/* Author: izhang
 * Time: 03-03-2023 22:43:01
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#include <ostream>
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
    char c;
    int ind;
    bool operator<(const item &rhs) const {
        if (c == rhs.c) {
            return ind > rhs.ind;
        }
        return c < rhs.c;
    }
    friend ostream &operator<<(ostream &os, const item &item) {
        os << "c: " << item.c << " ind: " << item.ind;
        return os;
    }
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {'z' + 1, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }

    static item single(char v, int ind) {
        return {v, ind};
    }

    void upd(int p, char v, int ind, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v, ind);
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            upd(p, v, ind, 2 * x + 1, lx, m);
        } else {
            upd(p, v, ind, 2 * x + 2, m, rx);
        }
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void upd(int p, char v, int ind) {
        upd(p, v, ind, 0, 0, size);
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
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        seg.upd(i, s[i], i);
    }
    int cur = n;
    for (int i = 0; i < n; ++i) {
        item res = seg.query(i + 1, cur);
        if (res.c <= 'z') {
            if (s[i] > res.c) {
                swap(s[i], s[res.ind]);
                cur = res.ind;
            }
        } else {
            break;
        }
        dbg() << s;
    }
    cout << s << "\n";

    //    }vector<pair<char, int>> mn(n);
    //    mn[0] = {s[0], 0};
    //    for (int i = 1; i < n; ++i) {
    //        mn[i] = min(mn[i - 1], {s[i], -i});
    //    }
    //    int cur = n - 1;
    //    for (int i = 0; i < n; ++i) {
    //        dbg() << i << " " << cur << " " << mn[cur] << " " << s;
    //        if (-mn[cur].second > i) {
    //            if (s[i] > mn[cur].first) {
    //                swap(s[i], s[-mn[cur].second]);
    //                cur = -mn[cur].second - 1;
    //            }
    //        } else {
    //        }
    //    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
