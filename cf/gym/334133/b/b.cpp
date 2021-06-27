/* Author: izhang05
 * Time: 06-26-2021 13:15:02
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 1e5 + 5, maxs = 20;
int sol;

int up[maxn][maxs], depth[maxn], n, comp[maxn];
pair<int, int> diam[maxn];

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

void update(int c, int p) {
    up[c][0] = p;
    depth[c] = depth[p] + 1;
    comp[c] = comp[p];
    for (int i = 1; i < maxs; ++i) {
        if (up[c][i - 1] == -1) {
            up[c][i] = -1;
        } else {
            up[c][i] = up[up[c][i - 1]][i - 1];
        }
    }
    int cur_comp = comp[c], a = diam[cur_comp].first, b = diam[cur_comp].second;
    int best_dist = dist(a, b);
    if (dist(a, c) > best_dist) {
        best_dist = dist(a, c);
        diam[cur_comp] = {a, c};
    }
    if (dist(c, b) > best_dist) {
        diam[cur_comp] = {c, b};
    }
}

int main() {
    setIO("newbarn");
    int q;
    cin >> q;
    int node = 0, forest = 1;
    memset(up, -1, sizeof(up));
    while (q--) {
        char t;
        int a;
        cin >> t >> a;
        --a;
        if (t == 'B') {
            if (a >= 0) {
                update(node, a);
            } else {
                comp[node] = forest++;
            }
            ++node;
        } else if (t == 'Q') {
            int cur_comp = comp[a], b = diam[cur_comp].first, c = diam[cur_comp].second;
            cout << max(dist(a, b), dist(a, c)) << "\n";
        } else {
            assert(false);
        }
    }
    return 0;
}
