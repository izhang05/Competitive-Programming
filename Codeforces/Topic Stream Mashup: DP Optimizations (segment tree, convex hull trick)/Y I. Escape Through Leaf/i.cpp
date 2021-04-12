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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

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

long long dp[maxn], a[maxn], b[maxn], s[maxn];
vector<int> adj[maxn];
dynamic_hull *cht[maxn];

void dfs(int c, int p) {
    s[c] = 1;
    long long bigc = -1, bigs = -1;
    for (auto i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            s[c] += s[i];
            if (s[i] > bigs) {
                bigs = s[i];
                bigc = i;
            }
        }
    }
    if (s[c] == 1) {
        dp[c] = 0;
        cht[c] = new dynamic_hull;
        cht[c]->insert_line(-b[c], -dp[c]);
    } else {
        cht[c] = cht[bigc];
        for (auto i : adj[c]) {
            if (i != p && i != bigc) {
                for (auto j : *cht[i]) {
                    cht[c]->insert_line(j.m, j.b);
                }
            }
        }
        dp[c] = -cht[c]->eval(a[c]);
        cht[c]->insert_line(-b[c], -dp[c]);
    }
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int c, d;
        cin >> c >> d;
        --c, --d;
        adj[c].push_back(d);
        adj[d].push_back(c);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    return 0;
}
