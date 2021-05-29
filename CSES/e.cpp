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

int up[maxn][maxs], depth[maxn], n;

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

bool anc(int x, int y) { // x is an ancestor of y?
    if (depth[x] > depth[y]) {
        return false;
    }
    return jmp(y, depth[y] - depth[x]) == x;
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
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
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

int main() {
    setIO("e");

    int m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    build();
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        vector<pair<int, int>> a(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[j].second;
            --a[j].second;
            if (a[j].second) {
                a[j].second = up[a[j].second][0];
            }
            a[j].first = depth[a[j].second];
        }
        sort(a.begin(), a.end());
#ifdef DEBUG
        for (int j = 0; j < k; ++j) {
            cout << a[j].first << " " << a[j].second << "\n";
        }
#endif
        bool sol = true;
        for (int j = 0; j < k - 1; ++j) {
            if (!anc(a[j].second, a[j + 1].second)) {
                sol = false;
#ifdef DEBUG
                cout << a[j].second << " " << a[j + 1].second << "\n";
#endif
                cout << "NO"
                     << "\n";
                break;
            }
        }
        if (sol) {
            cout << "YES"
                 << "\n";
        }
    }
    return 0;
}
