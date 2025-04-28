#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b);++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct item {
    long long mn;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {(long long) 1e18};

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        t.resize(2 * size);
    }

    static item merge(item a, item b) { return {min(a.mn, b.mn)}; }

    static item single(long long v) { return {v}; }

    void upd(int p, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) upd(p, v, 2 * x + 1, lx, m);
        else upd(p, v, 2 * x + 2, m, rx);
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void upd(int p, long long v) { upd(p, v, 0, 0, size); }

    item query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return neutral;
        if (lx >= l && rx <= r) return t[x];
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    item query(int l, int r) { return query(l, r, 0, 0, size); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    segtree seg;
    seg.init(n + 2);

    vector<int> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    vector<pair<int, int>> exhibit(m);
    int mx_start = 0;
    for (int i = 0; i < m; ++i) {
        cin >> exhibit[i].first >> exhibit[i].second;
        mx_start = max(mx_start, exhibit[i].first);
    }
    sort(exhibit.begin(), exhibit.end(), [](auto left, auto right) {
        return left.second == right.second ? left.first < right.first : left.second < right.second;
    });
    int lstart = 0;
    int j = -1;
    vector<long long> dp(n + 1, 1e18);
    dp[0] = 0;
    seg.upd(0, dp[0]);
    for (int i = 1; i <= n; ++i) {
        while (j < m && exhibit[j + 1].second < i) {
            ++j;
            lstart = max(lstart, exhibit[j].first);
        }
//        cout << i << " " << j << " " << lstart << "\n";
        dp[i] = c[i] + seg.query(lstart, i).mn;
        seg.upd(i, dp[i]);
//        cout << i << " " << dp[i] << "\n";
    }
    long long sol = 1e18;

    for (int i = mx_start; i <= n; ++i) {
        sol = min(sol, dp[i]);
    }
    cout << sol << "\n";
}
