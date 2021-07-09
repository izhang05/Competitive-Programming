/* Author: izhang05
 * Time: 07-08-2021 23:40:31
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
        auto l = *lower_bound((line){x, is_query});
        return l.m * x + l.b;
    }
};

const long long inf = 1e18;

int main() {
    setIO("1");
    int n;
    cin >> n;
    dynamic_hull cht;
    vector<long long> a(n + 1), pre(n + 1), mult(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
        mult[i] = mult[i - 1] + i * a[i];
    }
    long long sol = -inf;
    for (int i = 1; i <= n; ++i) {
        cht.insert_line(i, -pre[i - 1]);
        sol = max(sol, cht.eval(a[i]) + mult[i - 1] + pre[i - 1] + mult[n] - mult[i]);
    }
    cht.clear();
    for (int i = n; i >= 1; --i) {
        cht.insert_line(i, -pre[i]);
        sol = max(sol, cht.eval(a[i]) + mult[n] + pre[i] - i * a[i]);
    }
    cout << sol << "\n";
    return 0;
}
