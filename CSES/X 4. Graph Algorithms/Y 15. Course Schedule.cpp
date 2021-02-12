#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5;
int deg[maxn];

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        ++deg[b];
        adj[a].push_back(b);
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            q.push(i);
        }
    }
    vector<int> sol;
    while (!q.empty()) {
        int cur = q.front();
        sol.push_back(cur + 1);
        q.pop();
        for (int i : adj[cur]) {
            if (--deg[i] == 0) {
                q.push(i);
            }
        }
    }
    if (sol.size() == n) {
        for (int i : sol) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}
