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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

vector<int> val[maxn][maxs];
int up[maxn][maxs], depth[maxn], n;
vector<int> adj[maxn];

vector<int> merge(vector<int> a, const vector<int> &b) {
    for (auto &i : b) {
        a.push_back(i);
    }
    sort(a.begin(), a.end());
    while (a.size() > 10) {
        a.erase(prev(a.end()));
    }
    return a;
}

vector<int> jmp_val(int x, int d) {
    vector<int> res;
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            res = merge(res, val[x][i]);
            x = up[x][i];
        }
    }
    return res;
}

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
                val[j][i] = merge(val[j][i - 1], val[up[j][i - 1]][i - 1]);
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}

int main() {
    setIO("1");

    int m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        --c;
        val[c][0] = merge(val[c][0], vector<int>{i + 1});
    }
    dfs();
    build();
    while (q--) {
        int x, y, a;
        cin >> x >> y >> a;
        --x, --y;
        int l = lca(x, y);
        vector<int> res;
        res = merge(res, jmp_val(x, depth[x] - depth[l]));
        res = merge(res, jmp_val(y, depth[y] - depth[l] + 1));
        while ((int) res.size() > a) {
            res.erase(prev(res.end()));
        }
        cout << res.size() << " ";
        print(res);
    }
    return 0;
}
