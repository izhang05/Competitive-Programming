/* Author: izhang
 * Time: 06-22-2024 13:43:21
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5, mxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];
int nxt[mxn][mxs], depth[mxn], n;

int jmp(int x, int d) {
    for (int i = 0; i < mxs; i++) {
        if ((d >> i) & 1) {
            x = nxt[x][i];
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
    for (int i = mxs - 1; i >= 0; --i) {
        int new_x = nxt[x][i], new_y = nxt[y][i];
        if (new_x != new_y) {
            x = new_x, y = new_y;
        }
    }
    return nxt[x][0];
}

int dist(int x, int y) {
    int l = lca(x, y);
    return depth[x] - depth[l] + depth[y] - depth[l];
}

void build() {
    for (int i = 1; i < mxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (nxt[j][i - 1] == -1) {
                nxt[j][i] = -1;
            } else {
                nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
            }
        }
    }
}

void dfs(int c = 0, int p = -1, int d = 0) {
    nxt[c][0] = p;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

int d[mxn];
pair<int, int> diam;

void dfs1(int c = 0, int p = -1, int cur_d = 0) {
    diam = max(diam, {cur_d, c});
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c, cur_d + 1);
        }
    }
}

void test_case() {
    int a, b;
    cin >> n >> a >> b;
    --a, --b;
    for (int i = 0; i < n; ++i) {
        depth[i] = 0;
        adj[i].clear();
        for (int j = 0; j < mxs; ++j) {
            nxt[i][j] = 0;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    dfs();
    build();
    diam = {-1, -1};
    dfs1(0, -1, 0);
    pair<int, int> cur_diam = {diam.second, -1};
    diam = {-1, -1};
    dfs1(cur_diam.first, -1, 0);
    cur_diam.second = diam.second;
    int sol = inf;
    dbg() << cur_diam;
    for (int i = 0; i < n; ++i) {
        dbg() << "hi";
        int cur = 2 * (n - 1) - max(dist(i, cur_diam.first), dist(i, cur_diam.second));
        cur += max(dist(i, b), dist(i, a));
        if ((dist(i, a) > dist(i, b)) && ((dist(i, b) % 2) != (dist(i, a) % 2))) {
            ++cur;
        }
        dbg() << i << " " << cur;
        sol = min(sol, cur);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
        dbg();
    }
    return 0;
}
