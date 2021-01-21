#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;
int parent[maxn], points[maxn], depth[maxn];

int get_points(int x) {
    int res = 0;
    while (parent[x] != x) {
        res += points[x];
        x = parent[x];
    }
    return res + points[x];
}

int get(int x) {
    return parent[x] == x ? x : get(parent[x]);
}

void merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        points[xroot] -= points[yroot];
        parent[xroot] = yroot;
        depth[yroot] += depth[xroot];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("C.in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        depth[i] = 1;
    }
    string s;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (s == "join") {
            cin >> a >> b;
            --a, --b;
            merge(a, b);
        } else if (s == "add") {
            cin >> a >> b;
            --a;
            points[get(a)] += b;
        } else if (s == "get") {
            cin >> a;
            --a;
            cout << get_points(a) << "\n";
        } else {
            assert(false);
        }
    }
    return 0;
}
