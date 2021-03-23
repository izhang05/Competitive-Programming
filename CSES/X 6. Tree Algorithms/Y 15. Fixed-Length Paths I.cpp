#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("15.in", "r", stdin);
    freopen("15.out", "w", stdout);
    freopen("15.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 20;
vector<int> adj[maxn];
int depths[maxn], sub[maxn], n, k, mx_depth;
bool visited[maxn];
long long sol = 0;

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

void dfs1(int c, int p, int d) {
#ifdef DEBUG
    cout << c << " " << p << " " << d << " " << depths[k - d] << "\n";
#endif
    if (d > k) {
        return;
    }
    sol += depths[k - d];
    mx_depth = max(mx_depth, d);
    for (auto i : adj[c]) {
        if (i != p && !visited[i]) {
            dfs1(i, c, d + 1);
        }
    }
}
void dfs2(int c, int p, int d) {
    if (d > k) {
        return;
    }
    ++depths[d];
    for (auto i : adj[c]) {
        if (i != p && !visited[i]) {
            dfs2(i, c, d + 1);
        }
    }
}

void solve(int v = 0) {
    find_size(v);
    int c = find_centroid(v, -1, sub[v]);
#ifdef DEBUG
    cout << "c: " << c << "\n";
#endif
    visited[c] = true;
    depths[0] = 1;
    mx_depth = 0;
    for (auto i : adj[c]) {
        if (!visited[i]) {
            dfs1(i, c, 1);
            dfs2(i, c, 1);
#ifdef DEBUG
            cout << i << " " << sol << "\n";
#endif
        }
    }
    fill(depths + 1, depths + mx_depth + 1, 0);

    for (int x : adj[c]) {
        if (!visited[x]) {
            solve(x);
        }
    }
}

int main() {
    setIO();
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve();
#ifdef DEBUG
    cout << "sol: ";
#endif
    cout << sol << "\n";
    return 0;
}
