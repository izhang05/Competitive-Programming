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


const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> tmp_adj[maxn];
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

    long long query(int l, int r) {
        return query(l, r, 0, 0, size).sum;
    }
};


struct tree {
    vector<int> adj[maxn];
    segtree seg;
    int sz[maxn], depth[maxn], st[maxn], en[maxn], t, par[maxn], top[maxn], tour[maxn];

    void dfs1(int c = 0, int p = 0, int d = 0) {
        sz[c] = 1;
        par[c] = p;
        depth[c] = d;
        seg.upd(st[c], 0);
        for (auto &i: adj[c]) {
            if (i != p) {
                dfs1(i, c, d + 1);
                sz[c] += sz[i];
                if (sz[i] > sz[adj[c][0]]) {
                    swap(i, adj[c][0]);
                }
            }
        }
    }

    void dfs2(int c = 0, int p = 0) {
        tour[t] = c;
        st[c] = t++;
        for (auto i: adj[c]) {
            if (i != p) {
                top[i] = i == adj[c][0] ? top[c] : i;
                dfs2(i, c);
            }
        }
        en[c] = t;
    }

    long long path(int x, int y) {
        long long res = 0;
        while (top[x] != top[y]) {
            if (depth[top[x]] < depth[top[y]]) {
                swap(x, y);
            }
            res = max(res, seg.query(st[top[x]], st[x] + 1));
            x = par[top[x]];
        }
        if (depth[x] > depth[y]) {
            swap(x, y);
        }
        res = max(res, seg.query(st[x], st[y] + 1));
        return res;
    }
};

tree trees[2];
int comp[maxn];
long long cnt[maxn],sol;

void dfs(int c, int p, int d) {
    if (d % 2 == 0) {
        sol += d * cnt[c];
    }
    for (auto &i: tmp_adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);

        }
    }
}


void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        tmp_adj[node1].push_back(node2);
        tmp_adj[node2].push_back(node1);
    }
    while (m--) {
        int t, a;
        cin >> t >> a;
        --a;
        if (t == 1) {
            int x;
            cin >> x;
            cnt[a] += x;
        } else {
            sol = 0;
            dfs(a, -1, 0);
            cout << sol << "\n";
        }
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
