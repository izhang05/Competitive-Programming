/* Author: izhang05
 * Time: 06-27-2021 22:00:31
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
struct item {
    long long sum;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {a.sum + b.sum};
    }

    static item single(int v) {
        return {v};
    }

    void upd(int p, int v, int x, int lx, int rx) {
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

    void upd(int p, int v) {
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn];
int depth[maxn];

struct euler {
    int t = 1, tin[2 * maxn], tout[2 * maxn], val[2 * maxn], c_tin[2 * maxn], c_tout[2 * maxn];
    segtree seg;
};
euler tours[2];

void dfs(int c, int p, int d) {
    depth[c] = d % 2;
    tours[d % 2].tin[c] = tours[d % 2].t++;
    tours[d % 2].c_tin[c] = tours[(d % 2) ^ 1].t;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
    tours[d % 2].tout[c] = tours[d % 2].t - 1;
    tours[d % 2].c_tout[c] = tours[(d % 2) ^ 1].t - 1;
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    for (auto &i : tours) {
        i.seg.init(2 * n + 2);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs(0, -1, 0);
    for (int i = 0; i < n; ++i) {
        euler &cur = tours[depth[i]];
        cur.seg.upd(cur.tin[i], cur.val[cur.tin[i]] + a[i]);
        cur.val[cur.tin[i]] += a[i];
        cur.seg.upd(cur.tin[i] + 1, cur.val[cur.tin[i] + 1] - a[i]);
        cur.val[cur.tin[i] + 1] -= a[i];
    }
    for (int i = 0; i < m; ++i) {
        int t, x;
        cin >> t >> x;
        --x;
        euler &cur = tours[depth[x]];
        if (t == 1) {
            int v;
            cin >> v;
            cur.seg.upd(cur.tin[x], cur.val[cur.tin[x]] + v);
            cur.val[cur.tin[x]] += v;
            cur.seg.upd(cur.tout[x] + 1, cur.val[cur.tout[x] + 1] - v);
            cur.val[cur.tout[x] + 1] -= v;

            euler &other = tours[depth[x] ^ 1];
            other.seg.upd(cur.c_tin[x], other.val[cur.c_tin[x]] - v);
            other.val[cur.c_tin[x]] -= v;
            other.seg.upd(cur.c_tout[x] + 1, other.val[cur.c_tout[x] + 1] + v);
            other.val[cur.c_tout[x] + 1] += v;
        } else {
            cout << cur.seg.query(0, cur.tin[x] + 1).sum << "\n";
        }
    }
    return 0;
}
