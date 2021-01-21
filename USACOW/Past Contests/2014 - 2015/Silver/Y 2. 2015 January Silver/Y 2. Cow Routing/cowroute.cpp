/*
ID: izhang01
TASK: cowroute
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
}

const int maxn = 1e3;
vector<pair<pair<int, int>, int>> adj[maxn];
pair<long long, int> dist[maxn];

int main() {
    setIO();
    int a, b, n;
    cin >> a >> b >> n;
    --a, --b;
    for (int i = 0; i < n; ++i) {
        int cost, num;
        cin >> cost >> num;
        vector<int> c(num);
        for (int j = 0; j < num; ++j) {
            cin >> c[j];
            --c[j];
        }
        for (int j = 0; j < num; ++j) {
            for (int k = j + 1; k < num; ++k) {
                adj[c[j]].emplace_back(make_pair(c[k], cost), k - j);
            }
        }
//        for (int j = 0; j < num - 1; ++j) {
//            cin >> c;
//            --c;
//            adj[first].emplace_back(make_pair(c, cost), j + 1);
//        }
    }
    for (auto &i : dist) {
        i = make_pair(1e18, 0);
    }
    priority_queue<pair<pair<long long, int>, int>, vector<pair<pair<long long, int>, int>>, greater<pair<pair<long long, int>, int>>> q;
    q.push(make_pair(make_pair(0, 0), a));
    dist[a] = make_pair(0, 0);
    while (!q.empty()) {
        pair<pair<long long, int>, int> cur = q.top();
        q.pop();
        if (dist[cur.second] != cur.first) {
            continue;
        }
        for (pair<pair<int, int>, int> i : adj[cur.second]) {
            long long cur_dist = cur.first.first + i.first.second;
            if (cur_dist < dist[i.first.first].first || (cur_dist == dist[i.first.first].first &&
                                                         cur.first.second + i.second < dist[i.first.first].second)) {
                q.push(make_pair(dist[i.first.first] = make_pair(cur_dist, cur.first.second + i.second),
                                 i.first.first));
            }
        }
    }
    if (dist[b].first == 1e18) {
        cout << "-1 -1" << "\n";
    } else {
        cout << dist[b].first << " " << dist[b].second << "\n";
    }
    return 0;
}
