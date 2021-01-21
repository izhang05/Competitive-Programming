/*
ID: izhang01
TASK: dining
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
}
const int maxn = 5e4 + 1;
int dist[maxn], new_dist[maxn];
vector<pair<int, int>> adj[maxn];


int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    int a, b, c;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(dist[n - 1] = 0, n - 1));
    while (!q.empty()) {
        pair<int, int> cur = q.top();
        q.pop();
        if (dist[cur.second] == cur.first) {
            for (pair<int, int> i : adj[cur.second]) {
                if (dist[i.first] > cur.first + i.second) {
                    q.push(make_pair(dist[i.first] = cur.first + i.second, i.first));
                }
            }
        }
    }
    memset(new_dist, 0x3f, sizeof(new_dist));
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        --a;
        q.push(make_pair(new_dist[a] = dist[a] - b, a));
    }
    while (!q.empty()) {
        pair<int, int> cur = q.top();
        q.pop();
        if (new_dist[cur.second] == cur.first) {
            for (pair<int, int> i : adj[cur.second]) {
                if (new_dist[i.first] > cur.first + i.second) {
                    q.push(make_pair(new_dist[i.first] = cur.first + i.second, i.first));
                }
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
//        cout << i << " " << new_dist[i] << " " << dist[i] << "\n";
        cout << (new_dist[i] <= dist[i]) << "\n";
    }
    return 0;
}
