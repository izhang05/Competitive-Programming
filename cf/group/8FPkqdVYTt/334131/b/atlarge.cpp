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
const int maxn = 7e4 + 5, maxd = 7e3 + 5;
vector<int> adj[maxn];
int deg[maxn], dist[maxn], sol = 0;
void dfs(int c, int p, int d = 0) {
    for (auto &i : adj[c]) {
        if (i != p) {
            if (dist[i] <= d + 1) {
                ++sol;
            } else {
                dfs(i, c, d + 1);
            }
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
    for (int i = 0; i < n; ++i) {
        sol = 0;
        dfs(i, -1);
        cout << sol << "\n";
    }
    return 0;
}
