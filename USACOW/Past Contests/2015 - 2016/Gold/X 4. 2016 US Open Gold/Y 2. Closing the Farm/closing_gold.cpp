/*
ID: izhang01
TASK: closing
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
}

const int maxn = 2e5;
int parent[maxn], depth[maxn], num_comp;
bool open[maxn];
vector<int> adj[maxn];

int get(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = get(parent[x]);
}

void merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        --num_comp;
        if (depth[xroot] > depth[yroot]) {
            parent[yroot] = xroot;
            depth[xroot] = max(depth[xroot], depth[yroot] + 1);
        } else {
            parent[xroot] = yroot;
            depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        }
    }
}

bool same(int x, int y) {
    return get(x) == get(y);
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> barns(n);
    for (int i = 0; i < n; ++i) {
        cin >> barns[i];
        --barns[i];
    }
    reverse(barns.begin(), barns.end());
    vector<bool> sol;
    for (int i : barns) {
        ++num_comp;
        parent[i] = i;
        open[i] = true;
        for (int j : adj[i]) {
            if (open[j]) {
                merge(i, j);
            }
        }
        sol.push_back(num_comp == 1);
    }
    reverse(sol.begin(), sol.end());
    for (bool i : sol) {
        cout << (i ? "YES" : "NO") << "\n";
    }
    return 0;
}
