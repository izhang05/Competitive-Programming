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
int deg[maxn];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        ++deg[b];
    }
    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            q.push(-i);
        }
    }
    while (!q.empty()) {
        int cur = -q.top();
        q.pop();
        for (int i : adj[cur]) {
            if (--deg[i] == 0) {
                q.push(-i);
            }
        }
        cout << cur + 1 << " ";
    }
    return 0;
}
