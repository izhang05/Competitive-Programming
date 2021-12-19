/* Author: izhang05
 * Time: 12-15-2021 11:28:55
**/
#include <bits/stdc++.h>
#include <ostream>

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];

struct girl {
    long long weight, c, ind;
    bool operator<(const girl &rhs) const {
        return weight == rhs.weight ? c < rhs.c : weight < rhs.weight;
    }
    friend ostream &operator<<(ostream &os, const girl &girl);
};

vector<girl> girls[maxn];
int tour[maxn];

struct item {
    girl mn;
    long long lz_add;
};
ostream &operator<<(ostream &os, const girl &girl) {
    os << "weight: " << girl.weight << " c: " << girl.c << " ind: " << girl.ind;
    return os;
}

struct segtree {
    int size{};
    vector<item> t;
    constexpr static item neutral = {{INFL, INFL, INFL}, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {min(a.mn, b.mn), 0};
    }

    void build(int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (tour[lx] == -1) {
                t[x] = neutral;
            } else {
                t[x].mn = girls[tour[lx]].back();
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m), build(2 * x + 2, m, rx);
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void build() {
        build(0, 0, size);
    }

    void apply(int x, long long v) {
        t[x].mn.weight += v;
        t[x].lz_add += v;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        apply(2 * x + 1, t[x].lz_add), apply(2 * x + 2, t[x].lz_add);
        t[x].lz_add = 0;
    }

    void add(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply(x, v);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m), add(l, r, v, 2 * x + 2, m, rx);

        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }
    void add(int l, int r, long long v) {
        add(l, r, v, 0, 0, size);
    }

    void add(int p, long long v) {
        add(p, p + 1, v, 0, 0, size);
    }

    void upd(int p, int x, int lx, int rx) {
        if (rx - lx == 1) {
            girls[tour[lx]].pop_back();
            t[x].mn = girls[tour[lx]].back();
            t[x].mn.weight += t[x].lz_add;
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        if (p < m) {
            upd(p, 2 * x + 1, lx, m);
        } else {
            upd(p, 2 * x + 2, m, rx);
        }
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }
    void upd(int p) {
        upd(p, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
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

    item query(int p) {
        return query(p, p + 1, 0, 0, size);
    }
};

segtree seg;
int sz[maxn], depth[maxn], st[maxn], en[maxn], t, par[maxn], top[maxn];
void dfs1(int c = 0, int p = 0, int d = 0) {
    sz[c] = 1;
    par[c] = p;
    depth[c] = d;
    for (auto &i : adj[c]) {
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
    for (auto i : adj[c]) {
        if (i != p) {
            top[i] = i == adj[c][0] ? top[c] : i;
            dfs2(i, c);
        }
    }
    en[c] = t;
}

girl path(int x, int y) {
    girl res = {INFL, INFL, INFL};
    while (top[x] != top[y]) {
        if (depth[top[x]] < depth[top[y]]) {
            swap(x, y);
        }
        res = min(res, seg.query(st[top[x]], st[x] + 1).mn);
        x = par[top[x]];
    }
    if (depth[x] > depth[y]) {
        swap(x, y);
    }
    res = min(res, seg.query(st[x], st[y] + 1).mn);
    return res;
}

void test_case() {
    memset(tour, -1, sizeof(tour));
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        --c;
        girls[c].push_back({i + 1, c, i + 1});
    }
    for (int i = 0; i < n; ++i) {
        girls[i].push_back({INFL, INFL, INFL});
        reverse(girls[i].begin(), girls[i].end());
    }
    seg.init(n);
    dfs1();
    dfs2();
    seg.build();
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v, k;
            cin >> u >> v >> k;
            --u, --v;
            vector<int> sol;
            for (int i = 0; i < k; ++i) {
                girl cur = path(u, v);
                if (cur.ind == INFL) {
                    break;
                }
                sol.push_back(cur.ind);
                seg.upd(st[cur.c]);
            }
            cout << sol.size();
            for (auto &i : sol) {
                cout << " " << i;
            }
            cout << "\n";
        } else {
            int v, k;
            cin >> v >> k;
            --v;
            seg.add(st[v], en[v], k);
        }
    }
}

int main() {
    setIO("3");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
