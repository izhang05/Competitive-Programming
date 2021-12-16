/* Author: izhang05
 * Time: 12-14-2021 00:47:17
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
int sz[maxn], top[maxn], bot[maxn], depth[maxn];

int up[maxn][maxs], n;

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

void dfs1(int c, int p, int d = 0) {
    depth[c] = d;
    up[c][0] = p;
    sz[c] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c, d + 1);
            sz[c] += sz[i];
            if (sz[i] > sz[adj[c][0]]) {
                swap(i, adj[c][0]);
            }
        }
    }
}
void dfs2(int c, int p) {
    bot[c] = c;
    for (auto &i : adj[c]) {
        if (i != p) {
            top[i] = (i == adj[c][0] ? top[c] : i);
            dfs2(i, c);
            if (i == adj[c][0]) {
                bot[c] = bot[i];
            }
        }
    }
}

int d(int x) {
    cout << "d " << x + 1 << endl;
    int res;
    cin >> res;
    return res;
}
int s(int x) {
    cout << "s " << x + 1 << endl;
    int res;
    cin >> res;
    if (res == -1) {
        exit(0);
    }
    return res - 1;
}

int solve(int x) {
    cout << "! " << x + 1 << endl;
    exit(0);
}

void test_case() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    build();
    int cur = 0;
    int goal = d(0);
    while (true) {
        int cur_d = d(bot[cur]);
        int l_depth = (goal - cur_d + depth[bot[cur]]) / 2;
        cur = jmp(bot[cur], depth[bot[cur]] - l_depth);
        if (l_depth == goal) {
            solve(cur);
        }
        cur = s(cur);
        if (depth[cur] == goal) {
            solve(cur);
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
