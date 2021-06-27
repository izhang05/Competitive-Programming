/*
ID: izhang01
TASK: atlarge
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    freopen("atlarge.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e5 + 5, inf = 0x3f3f3f3f;
vector<int> adj[maxn];
int deg[maxn], dist[maxn], sol = 0;
void dfs(int c, int p, int d = 0) {
    for (auto &i : adj[c]) {
        if (i != p) {
            if (dist[i] <= d + 1) {
                // A farmer can reach node i faster than Bessie. Therefore, we don't need to dfs in subtree i
                ++sol;
            } else {
                dfs(i, c, d + 1);
            }
        }
    }
}

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    --k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++deg[a], ++deg[b];
    }
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            q.push(i);
            dist[i] = 0;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : adj[cur]) {
            if (dist[i] > dist[cur] + 1) {
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }
    dfs(k, -1);
    cout << sol << "\n";
    return 0;
}
