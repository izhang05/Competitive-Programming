/* Author: izhang05
 * Time: 07-06-2021 21:55:23
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
const int maxn = 5e5 + 5;
vector<int> adj[maxn];
struct item {
    long long lz, mx;
};

struct segtree {
    int size{};
    vector<item> t;
    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }
    void push(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        t[2 * x + 1].lz = max(t[2 * x + 1].lz, t[x].lz);
        t[2 * x + 1].mx = max(t[2 * x + 1].mx, t[x].lz);
        t[2 * x + 2].lz = max(t[2 * x + 2].lz, t[x].lz);
        t[2 * x + 2].mx = max(t[2 * x + 2].mx, t[x].lz);
        t[x].lz = 0;
    }

    void upd(int l, int r, long long v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            t[x].lz = v;
            t[x].mx = max(t[x].mx, v);
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m);
        upd(l, r, v, 2 * x + 2, m, rx);
        t[x].mx = max(t[2 * x + 1].mx, t[2 * x + 2].mx);
    }

    void upd(int l, int r, int v) {
        upd(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return t[x].mx;
        }
        int m = (lx + rx) / 2;
        return max(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int tin[maxn], tout[maxn], t = 0;

void dfs(int c, int p) {
    tin[c] = t++;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
    tout[c] = t;
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    segtree fill, empty;
    fill.init(n);
    empty.init(n);
    dfs(0, -1);
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int a, c;
        cin >> a >> c;
        --c;
        if (a == 1) {
            fill.upd(tin[c], tout[c], i);
        } else if (a == 2) {
            empty.upd(tin[c], tin[c] + 1, i);
        } else {
            cout << (fill.query(tin[c], tin[c] + 1) > empty.query(tin[c], tout[c])) << "\n";
        }
    }
    return 0;
}
