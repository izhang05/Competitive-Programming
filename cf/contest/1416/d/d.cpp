/* Author: izhang05
 * Time: 07-26-2021 22:54:48
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
    long long mx, ind;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {-1, (int) 1e9};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        item res{};
        res.mx = max(a.mx, b.mx);
        if (a.mx > b.mx) {
            res.ind = a.ind;
        } else {
            res.ind = b.ind;
        }
        return res;
    }

    static item single(int v, int p) {
        return {v, p};
    }

    void upd(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v, p);
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

    pair<int, int> query(int l, int r) {
        item res = query(l, r, 0, 0, size);
        return {res.mx, res.ind};
    }
};

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5;
int par[maxn], depth[maxn], n, t = 0, tin[maxn], tout[maxn];
vector<int> adj[maxn];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        par[n] = n, par[xroot] = n, par[yroot] = n;
        adj[n].push_back(xroot), adj[n].push_back(yroot);
        ++n;
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

void dfs(int c) {
    tin[c] = t++;
    for (auto &i : adj[c]) {
        dfs(i);
    }
    tout[c] = t;
}

int main() {
    setIO("1");
    int m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        cin >> a[i];
    }
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first, --edges[i].second;
    }
    vector<bool> used(m);
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        --queries[i].second;
        if (queries[i].first == 2) {
            used[queries[i].second] = true;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (!used[i]) {
            merge(edges[i].first, edges[i].second);
        }
    }
    reverse(queries.begin(), queries.end());
    for (auto &i : queries) {
        if (i.first == 2) {
            merge(edges[i.second].first, edges[i.second].second);
        } else {
            i.second = get(i.second);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (get(i) == i) {
            dfs(i);
        }
    }
    segtree seg;
    seg.init(int(a.size()) + m);
    for (int i = 0; i < int(a.size()); ++i) {
        seg.upd(tin[i], a[i]);
    }
    reverse(queries.begin(), queries.end());
    for (auto &i : queries) {
        if (i.first == 1) {
            pair<int, int> cur = seg.query(tin[i.second], tout[i.second]);
            cout << cur.first << "\n";
            seg.upd(cur.second, 0);
        }
    }
    return 0;
}
