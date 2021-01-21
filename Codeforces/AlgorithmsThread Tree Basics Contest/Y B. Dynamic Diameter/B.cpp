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

const int maxn = 3e5 + 1;
vector<int> adj[maxn];
bool visited[maxn], diam[maxn];
int n, dist[maxn];

void bfs(int node) {
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    queue<pair<int, int> > q;
    q.push(make_pair(node, 0));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        visited[cur.first] = true;
        dist[cur.first] = cur.second;
        for (int i : adj[cur.first]) {
            if (!visited[i]) {
                q.push(make_pair(i, cur.second + 1));
            }
        }
    }
}

pair<int, int> farthest() {
    pair<int, int> sol;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > sol.first) {
            sol.first = dist[i];
            sol.second = i;
        }
    }
    return sol;
}

int main() {
    setIO();
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    pair<int, int> endpoints;
    endpoints.first = farthest().second;
    bfs(endpoints.first);
    pair<int, int> cur = farthest();
    endpoints.second = cur.second;
    int orig_diam = cur.first;
    for (int i = 0; i < n; ++i) {
        diam[i] |= dist[i] == orig_diam;
    }
    bfs(endpoints.second);
    for (int i = 0; i < n; ++i) {
        diam[i] |= dist[i] == orig_diam;
    }
    for (int i = 0; i < n; ++i) {
        cout << (diam[i] ? orig_diam + 1 : orig_diam) << "\n";
    }
    return 0;
}
