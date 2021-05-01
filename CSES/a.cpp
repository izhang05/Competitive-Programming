#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

#define int long long
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 20;
vector<pair<int, int>> tree[maxn];

pair<int, int> up[maxn][maxs];
int depth[maxn], n;

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i].first;
        }
    }
    return x;
}

int get_cost(int x, int d) {
    int cost = 0;
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            cost = max(cost, up[x][i].second);
            x = up[x][i].first;
        }
    }
    return cost;
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
        int new_x = up[x][i].first, new_y = up[y][i].first;
        if (new_x != new_y) {
            x = new_x, y = new_y;
        }
    }
    return up[x][0].first;
}

int dist(int x, int y) {
    int l = lca(x, y);
    return depth[x] - depth[l] + depth[y] - depth[l];
}

void dfs(int c = 0, int p = -1, int d = 0, int cost = 0) {
    up[c][0].first = p;
    up[c][0].second = cost;
    depth[c] = d;
    for (pair<int, int> i : tree[c]) {
        if (i.first != p) {
            dfs(i.first, c, d + 1, i.second);
        }
    }
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1].first == -1) {
                up[j][i].first = -1;
            } else {
                up[j][i].first = up[up[j][i - 1].first][i - 1].first;
                up[j][i].second = max(up[j][i - 1].second, up[up[j][i - 1].first][i - 1].second);
            }
        }
    }
}

int parent[maxn];

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        parent[xroot] = yroot;
        return true;
    }
    return false;
}

vector<pair<int, int>> adj[maxn];

signed main() {
    setIO("1");

    int m;
    cin >> n >> m;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<pair<pair<int, int>, int>> q(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        q[i] = {{a, b}, c};
        pq.push({c, {a, b}});
    }
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    int comp = n, cost = 0;
    while (comp > 1) {
        pair<int, pair<int, int>> cur = pq.top();
        pq.pop();
        if (merge(cur.second.first, cur.second.second)) {
            --comp;
            tree[cur.second.first].emplace_back(cur.second.second, cur.first);
            tree[cur.second.second].emplace_back(cur.second.first, cur.first);
            cost += cur.first;
        }
    }
    dfs();
    build();
    for (int i = 0; i < m; ++i) {
        int l = lca(q[i].first.first, q[i].first.second);
        int sub = max(get_cost(q[i].first.first, depth[q[i].first.first] - depth[l]),
                      get_cost(q[i].first.second, depth[q[i].first.second] - depth[l]));
        cout << cost + q[i].second - sub << "\n";
    }
    return 0;
}
