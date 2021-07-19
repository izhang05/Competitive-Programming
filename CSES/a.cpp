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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20;
vector<int> adj[maxn];
int v[maxn];

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

int tin[maxn], tout[maxn], euler[2 * maxn], t, sol[100000];
void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    euler[t] = c;
    tin[c] = t++;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
    euler[t] = c;
    tout[c] = t++;
}
const int k = 200;
int cnt[maxn], cur, cur_colors[maxn];
struct query {
    int l, r, ind;
    bool operator<(query other) const {
        if (l / k != other.l / k) {
            return l < other.l;
        }
        return (l / k & 1) ? (r < other.r) : (r > other.r);
    }
};

void add(int x) {
    int cur_cnt = ++cnt[euler[x]];
    if (cur_cnt == 1) {
        if (++cur_colors[v[euler[x]]] == 1) {
            ++cur;
        }
    } else if (cur_cnt == 2) {
        if (--cur_colors[v[euler[x]]] == 0) {
            --cur;
        }
    }
}
void rem(int x) {
    int cur_cnt = --cnt[euler[x]];
    if (cur_cnt == 1) {
        if (++cur_colors[v[euler[x]]] == 1) {
            ++cur;
        }
    } else if (cur_cnt == 0) {
        if (--cur_colors[v[euler[x]]] == 0) {
            --cur;
        }
    }
}
int main() {
    setIO("1");

    int m;
    cin >> n >> m;
    set<int> colors;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        colors.insert(v[i]);
    }
    int in = 0;
    map<int, int> ind;
    for (auto &i : colors) {
        ind[i] = in++;
    }
    for (int i = 0; i < n; ++i) {
        v[i] = ind[v[i]];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    build();
    vector<query> queries;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (tin[a] > tin[b]) {
            swap(a, b);
        }
        int l = lca(a, b);
        if (a == l) {
            queries.push_back({tin[a], tin[b], i});
            sol[i] = -1;
        } else {
            queries.push_back({tout[a], tin[b], i});
            sol[i] = v[tin[l]];
        }
    }
    sort(queries.begin(), queries.end());
    int l = 0, r = -1;
    for (auto &i : queries) {
        while (r < i.r) {
            ++r;
            add(r);
        }
        while (l > i.l) {
            --l;
            add(l);
        }
        while (r > i.r) {
            rem(r);
            --r;
        }
        while (l < i.l) {
            rem(l);
            ++l;
        }
        if (sol[i.ind] == -1) {
            sol[i.ind] = cur;
        } else {
            int color = sol[i.ind];
            sol[i.ind] = cur;
            if (!cur_colors[color]) {
                ++sol[i.ind];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
