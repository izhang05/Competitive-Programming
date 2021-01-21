#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("4.in", "r", stdin);
#endif
}

const int maxn = 3e5;
vector<int> adj[maxn];
int depth[maxn], parent[maxn];
int lift[maxn][20]; // log2(3e5) ≈ 19

void find_depth(int n, int p, int d) {
    depth[n] = d;
    parent[n] = p;
    for (int i : adj[n]) {
        if (i != p) {
            find_depth(i, n, d + 1);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) {
        while (depth[a] - depth[b]) {
            a = lift[a][(int) log2(depth[a] - depth[b])];
        }
    } else if (depth[b] > depth[a]) {
        while (depth[b] - depth[a]) {
            b = lift[b][(int) log2(depth[b] - depth[a])];
        }
    }

    if (a == b) {
        return a;
    }
    a = lift[a][0], b = lift[b][0];
    if (a == b) {
        return a;
    }
    for (int i = 1; i < 20; ++i) {
        int nexta = lift[a][i], nextb = lift[b][i];
        if (nexta == nextb) {
            return lca(a, b);
        }
        a = nexta, b = nextb;
    }
}


int main() {
    setIO();
    int n;
    cin >> n;
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_depth(0, -1, 0);
    for (int i = 0; i < n; ++i) {
        lift[i][0] = parent[i];
        for (int j = 1; j < 20; ++j) {
            lift[i][j] = -1;
        }
    }
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            if (lift[j][i - 1] >= 0) {
                lift[j][i] = lift[lift[j][i - 1]][i - 1];
            }
        }
    }
    int q;
    cin >> q;
    int a, b, c;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        int ancestor = lca(a, b);
        if (depth[a] + depth[b] - 2 * depth[ancestor] <= c) {
            cout << b + 1 << "\n";
        } else {
            if (depth[a] - depth[ancestor] == c) {
                cout << ancestor + 1 << "\n";
            } else if (depth[a] - depth[ancestor] > c) {
                while (c > 0) {
                    a = lift[a][(int) log2(c)];
                    c -= pow(2, (int) log2(c));
                }
                cout << a + 1 << "\n";
            } else {
                c = depth[a] + depth[b] - 2 * depth[ancestor] - c;
                while (c > 0) {
                    b = lift[b][(int) log2(c)];
                    c -= pow(2, (int) log2(c));
                }
                cout << b + 1 << "\n";
            }
        }
    }
    return 0;
}
