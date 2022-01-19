/* Author: izhang
 * Time: 01-16-2022 09:35:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5, maxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct item {
    long long sum, lz_add;
};

struct segtree {
    int size{};
    vector<item> t;
    constexpr static item neutral = {0, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {a.sum + b.sum, 0};
    }

    void apply(int x, long long v) {
        t[x].sum += v;
        t[x].lz_add += v;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        apply(2 * x + 1, t[x].lz_add), apply(2 * x + 2, t[x].lz_add);
        t[x].lz_add = 0;
    }

    void upd(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply(x, v);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);

        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }
    void upd(int l, int r, long long v) {
        upd(l, r, v, 0, 0, size);
    }

    void upd(int p, long long v) {
        upd(p, p + 1, v, 0, 0, size);
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
int up[maxn][maxs], depth[maxn], n, c[maxn], st[maxn], en[maxn], euler[maxn], t;
vector<int> adj[maxn];

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    x = jmp(x, depth[x] - depth[y]);
    if (x == y) {
        return x;
    }
    for (int i = maxs - 1; i >= 0; --i) {
        int new_x = up[x][i], new_y = up[y][i];
        if (new_x != new_y) {
            x = new_x, y = new_y;
        }
    }
    return up[x][0];
}

int dist(int x, int y) {
    int l = lca(x, y);
    return depth[x] - depth[l] + depth[y] - depth[l];
}

void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    euler[t] = c;
    st[c] = t++;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
    en[c] = t;
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}
segtree seg, black;

void test_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    seg.init(n);
    black.init(n);
    dfs();
    build();
    for (int i = 0; i < n; ++i) {
        black.upd(st[i], c[i]);
        seg.upd(st[i], c[i]);
    }
    for (int i = 0; i < n; ++i) {
        int p = up[i][0];
        if (!c[i]) {
            continue;
        }
        if (p != -1) {
            int cnt = black.query(0, n).sum - black.query(st[i], en[i]).sum;
            if (cnt) {
                seg.upd(st[p], en[p], 1);
            }
            if (black.query(st[p], en[p]).sum - black.query(st[i], en[i]).sum) {
                seg.upd(0, n, 1);
                seg.upd(st[p] + 1, en[p], -1);
            }
        }
        for (auto &j : adj[i]) {
            if (j != p) {
                int cnt = black.query(0, n).sum - black.query(st[j] + 1, en[j]).sum;
                if (cnt) {
                    seg.upd(st[j], en[j], 1);
                }
                if (black.query(st[i] + 1, en[i]).sum) {
                    seg.upd(0, n, 1);
                    vector<int> has;
                    for (auto &k : adj[j]) {
                        if (black.query(st[k], en[k]).sum) {
                            has.push_back(k);
                        }
                    }
                    if (int(has.size()) == 1) {
                        seg.upd(st[has[0]], en[has[0]] - 1);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (seg.query(st[i]).sum) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
