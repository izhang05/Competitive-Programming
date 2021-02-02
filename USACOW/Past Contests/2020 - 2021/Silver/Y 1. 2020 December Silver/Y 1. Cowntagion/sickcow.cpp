#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
}
const int maxn = 1e5 + 1;
vector<int> adj[maxn];
int sol = 0;

void dfs(int cur, int p) {
    int child = adj[cur].size();
    if (p != -1) {
        --child;
    }
    sol += child;
    int cur_inf = 1;
    while (cur_inf < child + 1) {
        ++sol;
        cur_inf *= 2;
    }
    for (int i : adj[cur]) {
        if (i != p) {
            dfs(i, cur);
        }
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    cout << sol << "\n";
    return 0;
}
