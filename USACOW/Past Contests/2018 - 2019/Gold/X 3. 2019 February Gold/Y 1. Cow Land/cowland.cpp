/*
ID: izhang01
TASK: cowland
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
}
//#define DEBUG
const int maxn = 1e5 + 5, maxs = 17; // log_2 1e5

int up[maxn][maxs], depth[maxn], st[maxn], en[maxn], timer = 1, n, q, a[maxn], bit[4 * maxn];
vector<int> adj[maxn];

void update(int p, int v) {
    for (; p <= 2 * n; p += p & (-p)) {
        bit[p] ^= v;
    }
}
long long query(int p) {
    long long res = 0;
    for (; p > 0; p -= p & (-p)) {
        res ^= bit[p];
    }
    return res;
}

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x ?: -1; // modification to return -1 if not found
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
void dfs(int c, int p, int d) {
    up[c][0] = p;
    depth[c] = d;
    st[c] = timer++;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
    en[c] = timer++;
}

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    cin >> n >> q;
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs(1, 0, 0);
    for (int i = 1; i < maxs; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    for (int i = 1; i < n + 1; ++i) {
#ifdef DEBUG
        cout << i << " " << query(st[i]) << "\n";
#endif
        update(st[i], a[i]);
#ifdef DEBUG
        cout << i << " " << query(st[i]) << "\n";
        cout << "\n";
#endif
        update(en[i], a[i]);
    }

#ifdef DEBUG
    for (int i = 1; i < n + 1; ++i) {
        cout << i << " " << depth[i] << " " << st[i] << " " << en[i] << "\n";
    }
    cout << "\n";
    for (int i = 1; i < n + 1; ++i) {
        cout << i << " " << query(st[i]) << "\n";
    }
    cout << "\n";
#endif
    for (int i = 0; i < q; ++i) {
        int b;
        cin >> b;
        if (b == 1) {
            int node, val;
            cin >> node >> val;
            update(st[node], a[node]);
            update(en[node], a[node]);
            a[node] = val;
            update(st[node], a[node]);
            update(en[node], a[node]);
        } else {
            int x, y;
            cin >> x >> y;
            int l = lca(x, y);
            cout << (query(st[x]) ^ query(st[y]) ^ a[l]) << "\n";
#ifdef DEBUG
            cout << x << " " << y << " " << up[l][0] << "\n";
            cout << query(st[x]) << " " << query(st[y]) << " " << query(st[up[l][0]]) << "\n";
            cout << "\n";
#endif
        }
    }
#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
