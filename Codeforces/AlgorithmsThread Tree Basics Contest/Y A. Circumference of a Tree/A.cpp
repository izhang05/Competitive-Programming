#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("3.in", "r", stdin);
#endif
}

const int maxn = 3e5;
vector<int> adj[maxn];
pair<int, int> max_depth; // first = depth, second = ind
int sol;

void start_dfs(int n, int parent, int cur) {
    if (cur > max_depth.first) {
        max_depth.first = cur;
        max_depth.second = n;
    }
    for (int i : adj[n]) {
        if (i != parent) {
            start_dfs(i, n, cur + 1);
        }
    }
}

void solve(int n, int parent, int depth) {
    sol = max(sol, 3 * depth);
    for (int i : adj[n]) {
        if (i != parent) {
            solve(i, n, depth + 1);
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
    start_dfs(0, -1, 0);
    solve(max_depth.second, -1, 0);
    cout << sol << "\n";
    return 0;
}