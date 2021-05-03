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
    cin.exceptions(istream::failbit);
    freopen("rblock.in", "r", stdin);
    freopen("rblock.out", "w", stdout);
    freopen("rblock.out", "w", stderr);
}
//#define DEBUG
const int maxn = 255;

struct edge {
    int b, cost, ind;
};

vector<edge> adj[maxn];
const long long inf = 1e18;
long long dist[maxn];
int pre_path[maxn];
int pre[maxn];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c, i});
        adj[b].push_back({a, c, i});
    }
    for (int i = 0; i < n; ++i) {
        dist[i] = inf;
    }
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.top();
        q.pop();
        if (cur.first != dist[cur.second]) {
            continue;
        }
        for (auto &i : adj[cur.second]) {
            if (dist[i.b] > cur.first + i.cost) {
                pre_path[i.b] = i.ind;
                pre[i.b] = cur.second;
                q.push({dist[i.b] = cur.first + i.cost, i.b});
            }
        }
    }
    vector<int> path;
    int pos = n - 1;
    while (pos != 0) {
        path.push_back(pre_path[pos]);
        pos = pre[pos];
    }
#ifdef DEBUG
    for (auto &i : path) {
        cout << i << " ";
    }
    cout << "\n";
#endif
    long long orig = dist[n - 1], sol = 0;
    for (auto &add : path) {
        for (int i = 0; i < n; ++i) {
            dist[i] = inf;
        }
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, 0});
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            if (cur.first != dist[cur.second]) {
                continue;
            }
            for (auto &i : adj[cur.second]) {
                int ne = cur.first + i.cost;
                if (i.ind == add) {
                    ne += i.cost;
                }
                if (dist[i.b] > ne) {
                    pre_path[i.b] = i.ind;
                    pre[i.b] = cur.second;
                    q.push({dist[i.b] = ne, i.b});
                }
            }
        }
        sol = max(sol, dist[n - 1]);
    }
    cout << sol - orig << "\n";
    return 0;
}
