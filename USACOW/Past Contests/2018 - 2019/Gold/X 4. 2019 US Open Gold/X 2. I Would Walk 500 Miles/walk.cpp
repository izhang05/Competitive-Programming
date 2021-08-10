/*
ID: izhang01
TASK: walk
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    freopen("walk.out", "w", stderr);
}
//#define DEBUG
const int a = 2019201913, b = 2019201949, mod = 2019201997, maxn = 7505;

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
int dist(long long x, long long y) {
    return (a * (x + 1) + b * (y + 1)) % mod;
}

void jarnik(int source) {
    for (int i = 1; i <= N; i++) D[i] = 2019201997;
    for (int iter = 0; iter < N; iter++) {
        int min_i = 0;
        for (int i = 1; i <= N; i++)
            if (!visited[i] && (min_i == 0 || D[i] < D[min_i])) min_i = i;
        visited[min_i] = 1;
        for (int j = 1; j <= N; j++)
            if (!visited[j])
                D[j] = min(D[j], (2019201913LL * min(min_i, j) + 2019201949LL * max(min_i, j)) % 2019201997LL);
    }
}

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
    vector<pair<int, pair<int, int>>> edges;
    edges.reserve(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.emplace_back(dist(i, j), make_pair(i, j));
        }
    }
    sort(edges.begin(), edges.end());
    int comps = n, sol = 0;
    for (int i = 0; i < (int) edges.size() && comps >= k; ++i) {
        if (merge(edges[i].second.first, edges[i].second.second)) {
            --comps;
            sol = edges[i].first;
        }
    }
    cout << sol << "\n";
    return 0;
}
