/* Author: izhang05
 * Time: 10-17-2021 23:44:23
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 19;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int e[maxn];
vector<pair<int, int>> adj[maxn];

struct query {
    int v, x, ind;
    bool operator>(query &other) const {
        return v > other.v;
    }
};

int up[maxn][maxs], depth[maxn], n, mx_up[maxn][maxs];

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

int jmp_mx(int x, int d) {
    int res = 0;
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            res = max(res, mx_up[x][i]);
            x = up[x][i];
        }
    }
    return res;
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

int get_mx(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int l = lca(a, b);
    return max(jmp_mx(a, depth[a] - depth[l]), jmp_mx(b, depth[b] - depth[l]));
}

void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c, d + 1);
            mx_up[i.first][0] = i.second;
        }
    }
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                mx_up[j][i] = max(mx_up[j][i - 1], mx_up[up[j][i - 1]][i - 1]);
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}

int par[maxn], d[maxn], mx_edges[maxn];
pair<int, int> mx[maxn]; // pair<val, ind>

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (d[xroot] > d[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        par[xroot] = yroot;
        if (mx[yroot].first == mx[xroot].first) {
            mx_edges[yroot] = max({mx_edges[yroot], mx_edges[xroot], get_mx(mx[yroot].second, mx[xroot].second)});
        } else if (mx[xroot].first > mx[yroot].first) {
            mx_edges[yroot] = mx_edges[xroot];
        }
        mx[yroot] = max(mx[yroot], mx[xroot]);
        d[yroot] = max(d[yroot], d[xroot] + 1);
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
        par[i] = i;
        mx[i] = {e[i], i};
    }
    priority_queue<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        --a, --b;
        adj[a].emplace_back(b, t);
        adj[b].emplace_back(a, t);
        edges.push({c, {a, b}});
    }
    dfs();
    build();
    vector<pair<int, int>> sol(q);
    vector<query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].v >> queries[i].x;
        --queries[i].x;
        queries[i].ind = i;
    }
    sort(queries.begin(), queries.end(), greater<>());
    for (auto &i : queries) {
        while (!edges.empty() && edges.top().first >= i.v) {
            pair<int, pair<int, int>> cur = edges.top();
            edges.pop();
            merge(cur.second.first, cur.second.second);
        }
        sol[i.ind].first = mx[get(i.x)].first;
        sol[i.ind].second = max(mx_edges[get(i.x)], get_mx(i.x, mx[get(i.x)].second));
    }
    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
