/* Author: izhang05
 * Time: 08-04-2021 18:46:24
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 7e4 + 5;
vector<int> adj[maxn];
int deg[maxn], depth[maxn], dist[maxn], sol = 0;

int sub[maxn];
bool visited[maxn];

int find_size(int v, int p) {
    sub[v] = 1;
    for (auto &i : adj[v]) {
        if (i != p && !visited[i]) {
            sub[v] += find_size(i, v);
        }
    }
    return sub[v];
}

int centroid(int v, int p, int s) {
    for (auto &i : adj[v]) {
        if (i != p && !visited[i] && sub[i] > s / 2) {
            return centroid(i, v, s);
        }
    }
    return v;
}

void dfs(int c, int p, int d) {
    for (auto &i : adj[c]) {
        if (!visited[i] && i != p) {
            dfs(i, c, d + 1);
        }
    }
}

void solve(int v) {
    find_size(v, -1);
    int c = centroid(v, -1, sub[v]);
    visited[c] = true;
    depth[c] = 0;
    dfs(0, -1, 0);

    for (auto &i : adj[c]) {
        if (!visited[i]) {
            solve(i);
        }
    }
}

int main() {
    setIO("atlarge");
    int n;
    cin >> n;
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
    solve(0);
    __t
    return 0;
}
