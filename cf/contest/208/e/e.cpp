///* Author: izhang05
 * Time: 07-07-2021 18:12:14
**/
#include <bits/stdc++.h>

using namespace std;
//
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
vector<int> child[maxn];

int up[maxn][maxs], depth[maxn], n;
bool visited[maxn];

vector<pair<int, int>> queries[maxn];

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
            if (x == -1) {
                return x;
            }
        }
    }
    return x;
}

void dfs(int c = 0, int p = -1, int d = 0) {
    visited[c] = true;
    up[c][0] = p;
    depth[c] = d;
    for (int i : child[c]) {
        dfs(i, c, d + 1);
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
int sol[maxn];
map<int, int> cnt[maxn];

void dfs2(int c, int d) {
    visited[c] = true;
    ++cnt[c][d];
    for (auto &i : child[c]) {
        dfs2(i, d + 1);
        if (cnt[i].size() > cnt[c].size()) {
            swap(cnt[i], cnt[c]);
        }
        for (auto &j : cnt[i]) {
            cnt[c][j.first] += j.second;
        }
        cnt[i].clear();
    }

    for (auto &i : queries[c]) {
        sol[i.second] = max(0, cnt[c][d + i.first] - 1);
    }
}

int main() {
    setIO("1");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        if (p >= 0) {
            child[p].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    memset(visited, false, sizeof(visited));
    build();
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int v, p;
        cin >> v >> p;
        --v;
        int par = jmp(v, p);
        if (par >= 0) {
            queries[par].emplace_back(p, i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs2(i, 0);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << sol[i] << " \n"[i == m - 1];
    }
    return 0;
}
