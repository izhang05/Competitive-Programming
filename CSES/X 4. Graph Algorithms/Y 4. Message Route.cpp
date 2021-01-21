#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5;
vector<int> adj[maxn];
int parent[maxn];

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
    for (int i = 0; i < n; ++i) {
        parent[i] = -1;
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : adj[cur]) {
            if (parent[i] < 0) {
                q.push(i);
                parent[i] = cur;
            }
        }
    }
    stack<int> sol;
    if (parent[n - 1] < 0) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        int u = n - 1;
        while (u) {
            sol.push(u);
            u = parent[u];
        }
        sol.push(0);
        cout << sol.size() << "\n";
        while (!sol.empty()) {
            cout << sol.top() + 1 << " ";
            sol.pop();
        }
        cout << "\n";
    }
    return 0;
}

