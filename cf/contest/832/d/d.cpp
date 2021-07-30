/* Author: izhang05
 * Time: 07-29-2021 19:47:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20;
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
    setIO("1");

    int q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs();
    build();
    while (q--) {
        vector<int> a(3);
        for (int i = 0; i < 3; ++i) {
            cin >> a[i];
            --a[i];
        }
        sort(a.begin(), a.end());
        int sol = 1;
        do {
            // a = [s, f, t]
            int s = a[0], f = a[1], t = a[2];
            int l1 = lca(s, f), l2 = lca(s, t);
            int cur = min(dist(s, l1), dist(s, l2)) + 1;
            if (l1 == l2) {
                cur += dist(lca(f, t), l1);
            }
            sol = max(sol, cur);
        } while (next_permutation(a.begin(), a.end()));
        cout << sol << "\n";
    }
    return 0;
}
