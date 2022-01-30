/* Author: izhang
 * Time: 01-30-2022 13:51:33
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 100, maxs = 22;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
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
    int q;
    cin >> q;
    n = 4;
    vector<pair<int, int>> a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i].first;
        --a[i].first;
        a[i].second = n;
        for (int j = 0; j < 2; ++j) {
            adj[a[i].first].push_back(n);
            adj[n].push_back(a[i].first);
            ++n;
        }
    }
    for (int i = 1; i < 4; ++i) {
        adj[0].push_back(i);
        adj[i].push_back(0);
    }
    dfs();
    build();
    pair<int, int> diam{1, 2};
    int len = 2;
    for (auto &i : a) {
        if (dist(diam.first, i.second) > len) {
            diam = {diam.first, i.second};
            len = dist(diam.first, i.second);
        } else if (dist(diam.second, i.second) > len) {
            diam = {i.second, diam.second};
            len = dist(diam.second, i.second);
        }
        cout << len << "\n";
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
