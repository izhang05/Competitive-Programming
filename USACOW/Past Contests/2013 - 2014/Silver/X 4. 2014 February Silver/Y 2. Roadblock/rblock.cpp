/*
ID: izhang01
TASK: rblock
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rblock.in", "r", stdin);
    freopen("rblock.out", "w", stdout);
}
const int maxm = 25001, maxn = 250;
int dist[maxm][maxn]; // dist[i][j] = dist from 0 to j without using path i. i = m = using all paths
vector<pair<int, int>> adj[maxn];


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> paths(m);
    for (int i = 0; i < m; ++i) {
        cin >> paths[i].first.first >> paths[i].first.second >> paths[i].second;
        --paths[i].first.first, --paths[i].first.second;
        adj[paths[i].first.first].emplace_back(paths[i].first.second, paths[i].second);
        adj[paths[i].first.second].emplace_back(paths[i].first.first, paths[i].second);
    }
    for (int i = 0; i < m + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = 1e9;
        }
    }
    for (int i = 0; i < m + 1; ++i) {
        if (i < m) {
            adj[paths[i].first.first].erase(find(adj[paths[i].first.first].begin(), adj[paths[i].first.first].end(), make_pair(paths[i].first.second, paths[i].second)));
            adj[paths[i].first.second].erase(find(adj[paths[i].first.second].begin(), adj[paths[i].first.second].end(), make_pair(paths[i].first.first, paths[i].second)));
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[i][0] = 0;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            for (pair<int, int> j : adj[cur.second]) {
                if (dist[i][j.first] > cur.first + j.second) {
                    q.push(make_pair(dist[i][j.first] = cur.first + j.second, j.first));
                }
            }
        }
        if (i < m) {
            adj[paths[i].first.first].emplace_back(paths[i].first.second, paths[i].second);
            adj[paths[i].first.second].emplace_back(paths[i].first.first, paths[i].second);
        }
    }
    int sol = 0;
    for (int i = 0; i < m; ++i) {
        sol = max(sol, min(dist[i][n - 1] - dist[m][n - 1], paths[i].second));
    }
    cout << sol << "\n";
    return 0;
}
