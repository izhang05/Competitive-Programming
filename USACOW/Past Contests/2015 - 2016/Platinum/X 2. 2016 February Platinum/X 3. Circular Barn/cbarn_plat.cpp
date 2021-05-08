/*
ID: izhang01
TASK: cbarn
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    freopen("cbarn.out", "w", stderr);
}
//#define DEBUG
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

const int maxn = 1e3 + 5, maxk = 10;
long long dp[maxn][maxk], sum[maxn], pre[maxn];
dynamic_hull cht[maxk];

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = 1e18;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pre[j + 1] = pre[j] + a[j];
            sum[j + 1] = sum[j] + a[j] * j;
        }
        for (int j = 0; j <= k; ++j) {
            cht[j].clear();
        }
#ifdef DEBUG
        cout << "pre: \n";
        for (int j = 0; j < n + 1; ++j) {
            cout << pre[j] << " ";
        }
        cout << "\n";
        cout << "sum: \n";
        for (int j = 0; j < n + 1; ++j) {
            cout << sum[j] << " ";
        }
        cout << "\n";
#endif
        cht[0].insert_line(0, 0);
        for (int j = 1; j <= k; ++j) {
            for (int l = 0; l <= n; ++l) {
                dp[l][j] = sum[l] - cht[j - 1].eval(pre[l]);
#ifdef DEBUG
                cout << l << " " << j << " " << dp[l][j] << "\n";
#endif
                cht[j].insert_line(l, -(dp[l][j] - sum[l] + l * pre[l]));
            }
        }

        sol = min(sol, dp[n][k]);
        a.push_back(a[0]);
        a.erase(a.begin());
    }
    cout << sol << "\n";
    return 0;
}
