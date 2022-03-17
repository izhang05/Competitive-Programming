/* Author: izhang
 * Time: 03-17-2022 02:04:59
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4e5 + 5, maxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> tmp_adj[maxn], adj[maxn];
int dist[maxn];
int par[maxn], owner[maxn], dsu_depth[maxn];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (dsu_depth[xroot] > dsu_depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        par[xroot] = yroot;
        dsu_depth[yroot] = max(dsu_depth[yroot], dsu_depth[xroot] + 1);
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

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

int get_dist(int x, int y) {
    int l = lca(x, y);
    return depth[x] - depth[l] + depth[y] - depth[l];
}

void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    for (auto &i : adj[c]) {
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

void test_case() {
    int k, r;
    cin >> n >> k >> r;
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        tmp_adj[node1].push_back(node2);
        tmp_adj[node2].push_back(node1);
    }
    int cur_node = n;
    for (int i = 0; i < n; ++i) {
        for (auto &j : tmp_adj[i]) {
            if (j > i) {
                adj[i].push_back(cur_node);
                adj[cur_node].push_back(i);
                adj[cur_node].push_back(j);
                adj[j].push_back(cur_node);
                ++cur_node;
            }
        }
    }
    n = cur_node;
    dbg() << n;
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
    vector<int> stops(r);
    for (int i = 0; i < r; ++i) {
        cin >> stops[i];
        --stops[i];
    }
    memset(dist, 0x3f, sizeof(dist));
    memset(owner, -1, sizeof(owner));
    for (auto &i : stops) {
        queue<int> q;
        q.push(i);
        if (owner[i] != -1) {
            merge(i, owner[i]);
        }
        dist[i] = 0;
        owner[i] = i;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &j : adj[cur]) {
                if (owner[j] != -1 && owner[j] != i) {
                    merge(owner[j], cur);
                }
                if (dist[j] > dist[cur] + 1) {
                    dist[j] = dist[cur] + 1;
                    owner[j] = i;
                    merge(cur, j);
                    if (dist[j] < k) {
                        q.push(j);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        dbg() << i << " " << get(i);
    }
    dfs();
    build();
    int que;
    cin >> que;
    while (que--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (get_dist(a, b) <= 2 * k) {
            cout << "YES"
                 << "\n";
            continue;
        }
        int l = lca(a, b);
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
        if (get_dist(a, l) < k) {
            int cur = k - (depth[a] - depth[l]);
            a = l;
            a = jmp(b, (depth[b] - depth[l]) - cur);
        } else {
            a = jmp(a, k);
        }
        b = jmp(b, k);
        cout << (get(a) == get(b) ? "YES" : "NO") << "\n";
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
