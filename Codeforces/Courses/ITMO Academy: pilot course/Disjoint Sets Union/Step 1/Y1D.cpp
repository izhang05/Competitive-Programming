#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int maxn = 50000;
int parent[maxn], depth[maxn];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    int xroot = find(x), yroot = find(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        parent[xroot] = yroot;
        depth[yroot] += depth[xroot];
        return true;
    } else {
        return false;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
    }
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    vector<tuple<string, int, int>> q(k);
    string c;
    for (int i = 0; i < k; ++i) {
        cin >> c >> a >> b;
        --a, --b;
        q[i] = make_tuple(c, a, b);
    }
    reverse(q.begin(), q.end());
    vector<bool> sol;
    for (int i = 0; i < k; ++i) {
        if (get<0>(q[i]) == "ask") {
            sol.push_back(same(get<1>(q[i]), get<2>(q[i])));
        } else {
            merge(get<1>(q[i]), get<2>(q[i]));
        }
    }
    reverse(sol.begin(), sol.end());
    for (bool i : sol) {
        cout << (i ? "YES" : "NO") << "\n";
    }
    return 0;
}
