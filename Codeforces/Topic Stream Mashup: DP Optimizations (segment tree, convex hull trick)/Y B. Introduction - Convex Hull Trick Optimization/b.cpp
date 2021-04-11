#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
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


const long long is_query = -(1LL << 62);
struct line {
    long long m, b;
    mutable function<const line *()> succ;
    bool operator<(const line &rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line *s = succ();
        if (!s) return 0;
        long long x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line> { // will maintain upper hull for maximum
    const long long inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

        /* compare two lines by slope, make sure denominator is not 0 */
        long long v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else
            v1 /= (y->m - x->m);
        long long v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else
            v2 /= (z->m - y->m);
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
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    long long eval(long long x) {
        auto l = *lower_bound((line){x, is_query});
        return l.m * x + l.b;
    }
};

dynamic_hull cht;

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<long long> a(n), pre(n + 1), dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    cht.insert_line(0, 0);
    for (int i = 1; i < n; ++i) {
        dp[i] = pre[i + 1] * b[i] - cht.eval(b[i]);
        cht.insert_line(pre[i], -dp[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    return 0;
}
