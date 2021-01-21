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

const int maxn = 2001;
int parent[maxn * maxn];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    if (xroot == yroot) {
        return false;
    }
    parent[xroot] = parent[yroot] = parent[x] = parent[y] = rand() % 2 ? xroot : yroot;
    return true;
}

int main() {
    setIO();
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    vector<int> vert(n);
    for (int i = 0; i < n; ++i) {
        cin >> vert[i];
    }
    vert.push_back(0);
    vert.push_back(a);
    vector<int> hor(m);
    for (int i = 0; i < m; ++i) {
        cin >> hor[i];
    }
    hor.push_back(0);
    hor.push_back(b);
    sort(vert.begin(), vert.end());
    sort(hor.begin(), hor.end());
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            int cur = i + j * (n + 1);
            if (i < n) {
                edges.emplace_back(hor[j + 1] - hor[j], make_pair(cur, cur + 1));
            }
            if (j < m) {
                edges.emplace_back(vert[i + 1] - vert[i], make_pair(cur, cur + n + 1));
            }
            parent[cur] = cur;
        }
    }
    long long sol = 0;
    sort(edges.begin(), edges.end());
    for (auto i : edges) {
        if (merge(i.second.first, i.second.second)) {
            sol += i.first;
        }
    }
    cout << sol << "\n";
    return 0;
}