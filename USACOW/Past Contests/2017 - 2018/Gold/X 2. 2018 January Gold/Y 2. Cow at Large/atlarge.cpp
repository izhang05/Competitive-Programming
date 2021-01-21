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
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
}

const int maxn = 1e5;
int n, k, to_start[maxn], to_leaf[maxn], parent[maxn];
bool visited[maxn];
vector<int> adj[maxn];
vector<int> leafs;

void start_dfs(int node, int dist) {
    visited[node] = true;
    if (adj[node].size() == 1) {
        leafs.push_back(node);
    }
    to_start[node] = dist;
    for (int i : adj[node]) {
        if (!visited[i]) {
            parent[i] = node;
            start_dfs(i, dist + 1);
        }
    }
}

void leaf_bfs() {
    queue<pair<int, int> > q;
    for (int i : leafs) {
        q.push(make_pair(i, 0));
        visited[i] = true;
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        to_leaf[cur.first] = cur.second;
        for (int i : adj[cur.first]) {
            if (!visited[i]) {
                q.push(make_pair(i, cur.second + 1));
                visited[i] = true;
            }
        }
    }
}

int main() {
    setIO();
    cin >> n >> k;
    --k;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    start_dfs(k, 0);
    for (int i = 0; i < n; ++i) {
        assert(visited[i]);
        visited[i] = false;
    }
    leaf_bfs();
    int sol = 0;
//    parent[k] = k;
    for (int i = 0; i < n; ++i) {
        if (to_start[parent[i]] < to_leaf[parent[i]] && to_start[i] >= to_leaf[i]) { // Bessie can always reach parent[i], but not i
            ++sol;
//            cout << to_start[i] << " " << to_leaf[i] << " " << to_start[parent[i]] << " " << to_leaf[parent[i]] << "\n";
        }
    }
    if (find(leafs.begin(), leafs.end(), k) != leafs.end()) {
        cout << 1 << "\n";
    } else {
        cout << sol << "\n";
    }
    return 0;
}
