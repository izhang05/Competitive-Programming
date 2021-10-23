/*
ID: izhang01
TASK: fencedin
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
}

int x, y, n, m;
const int maxn = 2e3 + 5;

int ind(int i, int j) {
    return i * (n + 1) + j;
}
int par[maxn * maxn], depth[maxn * maxn];

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
    setIO();
    cin >> x >> y >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < (n + 1) * (m + 1); ++i) {
        par[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(x);
    a.push_back(0);
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    b.push_back(y);
    b.push_back(0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m + 1; ++i) {
        edges.push_back({b[i + 1] - b[i], {0, i}});
    }
    for (int i = 0; i < n + 1; ++i) {
        edges.push_back({a[i + 1] - a[i], {1, i}});
    }
    long long sol = 0;
    sort(edges.begin(), edges.end());
    for (auto &i : edges) {
        if (i.second.first == 0) {
            for (int j = 0; j < n; ++j) {
                if (merge(i.second.second * (n + 1) + j, i.second.second * (n + 1) + j + 1)) {
                    sol += i.first;
                }
            }
        } else {
            for (int j = 0; j < m; ++j) {
                if (merge(j * (n + 1) + i.second.second, (j + 1) * (n + 1) + i.second.second)) {
                    sol += i.first;
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
