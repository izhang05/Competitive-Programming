#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
long long sol;
vector<int> adj[mxn];

int sub[mxn];
bool visited[mxn];

int find_size(int v, int p) {
    sub[v] = 1;
    for (auto &i: adj[v]) {
        if (i != p && !visited[i]) {
            sub[v] += find_size(i, v);

        }
    }
    return sub[v];
}

int centroid(int v, int p, int s) {
    for (auto &i: adj[v]) {
        if (i != p && !visited[i] && sub[i] > s / 2) {
            return centroid(i, v, s);
        }
    }
    return v;
}


void solve(int v) {
    find_size(v, -1);
    int c = centroid(v, -1, sub[v]);
    visited[c] = true;

    for (auto &i: adj[c]) {
        if (!visited[i]) {

        }
    }

    for (auto &i: adj[c]) {
        if (!visited[i]) {
            solve(i);
        }
    }
}

segtree seg;
int sz[maxn], depth[maxn], st[maxn], en[maxn], t, par[maxn], top[maxn], tour[maxn];

void dfs1(int c = 0, int p = 0, int d = 0) {
    sz[c] = 1;
    par[c] = p;
    depth[c] = d;
    seg.upd(st[c],);
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

int path(int x, int y) {
    int res = 0;
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return 0;
}
