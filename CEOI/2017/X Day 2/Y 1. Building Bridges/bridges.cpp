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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

const long long is_query = -(1LL << 62);

struct line {
    long long m, b;
    mutable function<const line *()> succ;

    bool operator<(const line &rhs) const {
        if (rhs.b != is_query) {
            return m < rhs.m;
        }
        const line *s = succ();
        if (!s) {
            return false;
        }
        long long x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line> { // will maintain upper hull for maximum
    const long long inf = LLONG_MAX;

    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) {
                return false;
            }
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) {
            return y->m == x->m && y->b <= x->b;
        }
        /* compare two lines by slope, make sure denominator is not 0 */
        long long v1 = (x->b - y->b);
        if (y->m == x->m) {
            v1 = x->b > y->b ? inf : -inf;
        } else {
            v1 /= (y->m - x->m);
        }
        long long v2 = (y->b - z->b);
        if (z->m == y->m) {
            v2 = y->b > z->b ? inf : -inf;
        } else {
            v2 /= (z->m - y->m);
        }
        return v1 >= v2;
    }

    void insert_line(long long m, long long b) {
        auto y = insert({m, b});
        y->succ = [=] {
            return next(y) == end() ? 0 : &*next(y);
        };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) {
            erase(next(y));
        }
        while (y != begin() && bad(prev(y))) {
            erase(prev(y));
        }
    }

    long long eval(long long x) {
        auto l = *lower_bound((line) {x, is_query});
        return l.m * x + l.b;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<long long> w(n), pre(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        pre[i] = pre[max(0, i - 1)] + w[i];
    }
    dynamic_hull cht;
    cht.insert_line(2 * h[0], -(h[0] * h[0] - pre[0]));
    for (int i = 1; i < n - 1; ++i) {
        long long cur = -cht.eval(h[i]) + h[i] * h[i] + pre[i - 1];
        cht.insert_line(2 * h[i], -(cur + h[i] * h[i] - pre[i]));
    }
    cout << -cht.eval(h[n - 1]) + h[n - 1] * h[n - 1] + pre[n - 2] << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
