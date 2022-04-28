/* Author: izhang
 * Time: 04-17-2022 10:35:03
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
namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: Simon Lindholm
     * Date: 2017-04-20
     * License: CC0
     * Source: own work
     * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
     *  Useful for dynamic programming (``convex hull trick'').
     * Time: O(\log N)
     * Status: stress-tested
     */

    struct Line {
        mutable ll k, m, p;
        bool operator<(const Line &o) const { return k < o.k; }
        bool operator<(ll x) const { return p < x; }
    };

    struct LineContainer : multiset<Line, less<>> {
        // (for doubles, use inf = 1/.0, div(a,b) = a/b)
        static const ll inf = LLONG_MAX;
        ll div(ll a, ll b) { // floored division
            return a / b - ((a ^ b) < 0 && a % b);
        }
        bool isect(iterator x, iterator y) {
            if (y == end()) return x->p = inf, 0;
            if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
            else
                x->p = div(y->m - x->m, x->k - y->k);
            return x->p >= y->p;
        }
        void add(ll k, ll m) {
            auto z = insert({k, m, 0}), y = z++, x = y;
            while (isect(y, z)) z = erase(z);
            if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
            while ((y = x) != begin() && (--x)->p >= y->p)
                isect(x, erase(y));
        }
        ll query(ll x) {
            assert(!empty());
            auto l = *lower_bound(x);
            return l.k * x + l.m;
        }
    };

} // namespace kactl
//using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    long long a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    vector<long long> pre(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        pre[i] = pre[max(i - 1, 0)] + x[i];
    }
    kactl::LineContainer cht;
    cht.add(0, 0);
    long long sol = b * pre[n - 1];
    for (int i = 0; i < n; ++i) {
        long long cur = b * pre[i] - cht.query(i) + a * x[i];
        dbg() << i << " " << cur;
        long long k = -b * x[i];
        long long m = -b * pre[i] + b * i * x[i] - a * x[i] + cur;
        cht.add(-k, -m);
        sol = min(sol, cur + b * (pre[n - 1] - pre[i] - (n - 1 - i) * x[i]));
    }
    cout << sol << "\n";
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
