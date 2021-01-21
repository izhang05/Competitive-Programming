/*
ID: izhang01
TASK: shortcut
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
}
const int maxn = 1e5;
vector<pair<long long, long long>> adj[maxn];
long long dist[maxn], cows[maxn];

int main() {
    setIO();
    int n, m, t;
    cin >> n >> m >> t;
    int a, b, c;
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    q.push(make_pair(dist[0] = 0, 0));
    while (!q.empty()) {
        pair<long long, long long> cur = q.top();
        q.pop();
        if (dist[cur.second] != cur.first) {
            continue;
        }
        for (pair<long long, long long> i : adj[cur.second]) {
            if (dist[i.first] > cur.first + i.second) {
                q.push(make_pair(dist[i.first] = cur.first + i.second, i.first));
            }
        }
    }
    priority_queue<pair<long long, long long>> queue;
    for (int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        queue.push(make_pair(dist[i], i));
    }
    while (!queue.empty()) {
        pair<long long, long long> cur = queue.top();
        queue.pop();
        for (pair<long long, long long> i : adj[cur.second]) {
            if (dist[i.first] + i.second == dist[cur.second]) {
                cows[i.first] += cows[cur.second];
                break;
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, cows[i] * (dist[i] - t));
    }
    cout << sol << "\n";
    return 0;
}
