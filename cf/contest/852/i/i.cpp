/* Author: izhang05
 * Time: 09-16-2021 00:06:12
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20, k = 350;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool a[maxn];
int color[maxn], st[2 * maxn], en[2 * maxn], t = 0;
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
int euler[2 * maxn];

void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    euler[t] = c;
    st[c] = t++;

    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
    euler[t] = c;
    en[c] = t++;
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

struct query {
    int l, r, ind;
    bool operator<(query other) const {
        if (l / k != other.l / k) {
            return l < other.l;
        }
        return (l / k & 1) ? (r < other.r) : (r > other.r);
    }
};

long long add[maxn], sol[maxn], cur_sol = 0, val[2][maxn], occ[maxn];

void change(int x, bool ad) {
    int cur = euler[x];
    if (ad) {
        ++occ[cur];
    } else {
        --occ[cur];
    }
    int cur_occ = occ[cur];
    if (cur_occ == 1) {
        cur_sol -= val[0][color[cur]] * val[1][color[cur]];
        ++val[a[cur]][color[cur]];
        cur_sol += val[0][color[cur]] * val[1][color[cur]];
    } else {
        cur_sol -= val[0][color[cur]] * val[1][color[cur]];
        --val[a[cur]][color[cur]];
        cur_sol += val[0][color[cur]] * val[1][color[cur]];
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> nums;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        nums.insert(b[i]);
    }
    map<int, int> ind;
    int tmp = 0;
    for (auto &i : nums) {
        ind[i] = tmp++;
    }
    for (int i = 0; i < n; ++i) {
        color[i] = ind[b[i]];
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
    int q;
    cin >> q;
    vector<query> queries(q);
    for (int i = 0; i < q; ++i) {
        int c, d;
        cin >> c >> d;
        --c, --d;
        if (st[c] > st[d]) {
            swap(c, d);
        }
        int l = lca(c, d);
        if (l == c) {
            queries[i] = {st[c], st[d], i};
            add[i] = -1;
        } else {
            queries[i] = {en[c], st[d], i};
            add[i] = st[l];
        }
    }
    sort(queries.begin(), queries.end());
    int l = 0, r = -1;
    for (auto &i : queries) {
        while (r < i.r) {
            ++r;
            change(r, true);
        }
        while (l > i.l) {
            --l;
            change(l, true);
        }
        while (r > i.r) {
            change(r, false);
            --r;
        }
        while (l < i.l) {
            change(l, false);
            ++l;
        }
        if (add[i.ind] != -1) {
            change(add[i.ind], true);
        }
        sol[i.ind] = cur_sol;
        if (add[i.ind] != -1) {
            change(add[i.ind], false);
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << sol[i] << "\n";
    }
}

int main() {
    setIO("2");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
