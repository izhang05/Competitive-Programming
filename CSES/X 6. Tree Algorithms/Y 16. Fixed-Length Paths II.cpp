#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 20;
vector<int> adj[maxn];
int sub[maxn], n, k1, k2, mx_depth;
bool visited[maxn];
long long sol = 0, bit[2 * maxn];

struct item {
    long long sum;
};

void update(int pos, long long val) {
    for (pos++; pos <= n; pos += pos & -pos) bit[pos] += val;
}

long long query(int l, int r) {
    long long ans = 0;
    for (r++; r; r -= r & -r) ans += bit[r];
    for (; l; l -= l & -l) ans -= bit[l];
    return ans;
}

int find_centroid(int c, int p, int s) {
    for (auto i : adj[c]) {
        if (!visited[i] && sub[i] > s / 2 && i != p) {
            return find_centroid(i, c, s);
        }
    }
    return c;
}

int find_size(int v, int p = -1) {
    sub[v] = 1;

    for (int i : adj[v]) {
        if (i != p && !visited[i]) {
            sub[v] += find_size(i, v);
        }
    }

    return sub[v];
}

int depths[maxn];
void dfs1(int c, int p, int d) {
    if (d > k2) {
        return;
    }
    sol += query(max(0, k1 - d), k2 - d);
    mx_depth = max(mx_depth, d);
    for (auto i : adj[c]) {
        if (i != p && !visited[i]) {
            dfs1(i, c, d + 1);
        }
    }
}
void dfs2(int c, int p, int d) {
    if (d > k2) {
        return;
    }
    update(d, 1);
    for (auto i : adj[c]) {
        if (i != p && !visited[i]) {
            dfs2(i, c, d + 1);
        }
    }
}

void solve(int v = 0) {
    find_size(v);
    int c = find_centroid(v, -1, sub[v]);
    visited[c] = true;
    update(0, 1);
    mx_depth = 0;
    for (auto i : adj[c]) {
        if (!visited[i]) {
            dfs1(i, c, 1);
            dfs2(i, c, 1);
        }
    }
    for (int i = 0; i <= mx_depth; ++i) {
        update(i, -query(i, i));
    }

    for (int x : adj[c]) {
        if (!visited[x]) {
            solve(x);
        }
    }
}

int main() {
    setIO("16");
    cin >> n >> k1 >> k2;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve();
    cout << sol << "\n";
    return 0;
}
