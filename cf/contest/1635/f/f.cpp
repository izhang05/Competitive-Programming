/* Author: izhang
 * Time: 02-20-2022 09:35:36
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct item {
    long long mn;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {INFL};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size, neutral);
    }

    static item merge(item a, item b) {
        return {min(a.mn, b.mn)};
    }

    void upd(int p, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = {min(t[x].mn, v)};
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

struct query {
    int l, r;
    long long ind;
    bool operator<(const query &rhs) const {
        return r == rhs.r ? l < rhs.l : r < rhs.r;
    }
    friend ostream &operator<<(ostream &os, const query &query);
};
ostream &operator<<(ostream &os, const query &query) {
    os << "l: " << query.l << " r: " << query.r << " ind: " << query.ind;
    return os;
}

void test_case() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector<query> qu(q);
    for (int i = 0; i < q; ++i) {
        cin >> qu[i].l >> qu[i].r;
        qu[i].ind = i;
        --qu[i].l;
        --qu[i].r;
    }
    vector<query> seg;
    stack<pair<long long, int>> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top().first > a[i].second) {
            st.pop();
        }
        if (!st.empty()) {
            seg.push_back({st.top().second, i, (st.top().first + a[i].second) * abs(a[i].first - a[st.top().second].first)});
        }
        st.push({a[i].second, i});
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top().first > a[i].second) {
            st.pop();
        }
        if (!st.empty()) {
            seg.push_back({i, st.top().second, (st.top().first + a[i].second) * abs(a[i].first - a[st.top().second].first)});
        }
        st.push({a[i].second, i});
    }
    sort(qu.begin(), qu.end());
    sort(seg.begin(), seg.end());
    int i = 0;
    vector<long long> sol(q);
    segtree f;
    f.init(n);
    for (int j = 0; j < q; ++j) {
        while (i < int(seg.size()) && seg[i].r <= qu[j].r) {
            f.upd(seg[i].l, seg[i].ind);
            ++i;
        }
        sol[qu[j].ind] = f.query(qu[j].l, qu[j].r + 1).mn;
    }
    for (auto &j : sol) {
        cout << j << "\n";
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
