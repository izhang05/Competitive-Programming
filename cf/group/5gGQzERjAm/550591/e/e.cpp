/* Author: izhang
 * Time: 09-16-2024 19:44:05
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct item {
    long long val;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {(1 << 30) - 1};
    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {a.val & b.val};
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

int compute(vector<int> v) {
    int sol = 0;
    for (int i = 0; i < 30; ++i) {
        if (v[i]) {
            sol += 1 << i;
        }
    }
    return sol;
}

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<int> pre(n + 1);
    vector<vector<int>> diff(n + 1, vector<int>(30));

    vector<pair<pair<int, int>, int>> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first.first >> q[i].first.second >> q[i].second;
        --q[i].first.first, --q[i].first.second;
        for (int j = 0; j < 30; ++j) {
            if (q[i].second & (1 << j)) {
                ++diff[q[i].first.first][j];
                --diff[q[i].first.second + 1][j];
            }
        }
    }
    vector<int> cur(30);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 30; ++j) {
            cur[j] += diff[i][j];
        }
        pre[i] = compute(cur);
    }
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        seg.upd(i, pre[i]);
    }

    for (auto &i : q) {
        if (seg.query(i.first.first, i.first.second + 1).val != i.second) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << pre[i] << " \n"[i == n - 1];
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
