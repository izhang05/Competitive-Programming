#include <bits/stdc++.h>

using namespace std;

const int maxn = 40;
int par[maxn], depth[maxn];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        par[xroot] = yroot;
        depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

int main() {
    freopen("Y 107.txt", "r", stdin);
    int orig = 0, n = 40;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            if (a != -1) {
                edges.push({a, {i, j}});
                orig += a;
            }
        }
        par[i] = i;
    }
    orig /= 2;
    int mst = 0;
    while (!edges.empty()) {
        pair<int, pair<int, int>> cur = edges.top();
        if (merge(cur.second.first, cur.second.second)) {
            mst += cur.first;
        }
        edges.pop();
    }
    cout << orig - mst << "\n";
}
