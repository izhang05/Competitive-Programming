/* Author: izhang05
 * Time: 06-29-2021 14:33:25
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
const int maxn = 2e5 + 5;

struct segtree {
    int size{};
    long long neutral = 0, no_op = 0;
    vector<long long> operations, values;

    long long modify_op(long long a, long long b, long long len) {
        if (b == no_op) {
            return a;
        }
        if (b == 0) {
            return a;
        }
        if (b == 1) {
            return len - a;
        }
        assert(false);
    }

    long long calc_op(long long a, long long b) {
        return a + b;
    }

    void apply_mod_op(long long &a, long long b, long long len) {
        a = modify_op(a, b, len);
    }

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        operations.resize(2 * size);
        values.resize(2 * size);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        int m = (lx + rx) / 2;
        operations[2 * x + 1] ^= operations[x];
        operations[2 * x + 2] ^= operations[x];
        apply_mod_op(values[2 * x + 1], operations[x], m - lx);
        apply_mod_op(values[2 * x + 2], operations[x], rx - m);
        operations[x] = no_op;
    }

    void upd(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            operations[x] ^= v;
            apply_mod_op(values[x], v, rx - lx);
            return;
        }
        int m = (lx + rx) / 2;

        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
    }

    void upd(int l, int r, int v) {
        upd(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        long long m1 = query(l, r, 2 * x + 1, lx, m), m2 = query(l, r, 2 * x + 2, m, rx);
        return calc_op(m1, m2);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
vector<int> adj[maxn];
int tin[maxn], tout[maxn], ti = 0;

void dfs(int c, int p) {
    tin[c] = ti++;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
    tout[c] = ti - 1;
}

int main() {
    setIO("1");
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs(0, -1);
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        if (s) {
            seg.upd(tin[i], tin[i] + 1, 1);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        --x;
        if (s == "get") {
            cout << seg.query(tin[x], tout[x] + 1) << "\n";
        } else {
            seg.upd(tin[x], tout[x] + 1, 1);
        }
    }
    return 0;
}
