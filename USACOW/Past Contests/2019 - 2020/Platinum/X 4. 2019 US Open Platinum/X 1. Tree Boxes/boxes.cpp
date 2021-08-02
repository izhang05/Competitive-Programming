/*
ID: izhang01
TASK: boxes
LANG: C++11
*/

#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
int n, q;
const int maxn = 1e5 + 5, maxs = 20;
vector<int> adj[maxn];
int sub[maxn], up[maxn][maxs], depth[maxn];
pair<int, int> ind[maxn];

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
    sub[c] = 1;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
            sub[c] += sub[i];
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


void addRoad(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void dfs1(int c, int p) {
    sub[c] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            sub[c] += sub[i];
        }
    }
}

void dfs2(int c, int p, int x1, int y1, int x2, int y2) {
    setFarmLocation(c, x1, y1);
    ind[c] = {x1, y1};
    int nx = x1, ny = y2;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c, nx, ny - sub[i] + 1, nx + sub[i] - 1, ny);
            nx += sub[i] - 1, ny -= sub[i] - 1;
        }
    }
}
void buildFarms() {
    n = getN();
    q = getQ();
    dfs();
    build();
    dfs2(0, -1, 1, 1, n, n);
}

void notifyFJ(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    int l = lca(a, b), l2 = jmp(b, dist(l, b) - 1);
    addBox(ind[l].first, ind[l].second, ind[a].first, ind[a].second);
    if (a != b) {
        addBox(ind[l2].first, ind[l2].second, ind[b].first, ind[b].second);
    }
}