///*
//ID: izhang01
//TASK: gpsduel
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("gpsduel.in", "r", stdin);
//    freopen("gpsduel.out", "w", stdout);
//}
//const int maxm = 5e4 + 5, maxn = 1e4 + 5, inf = 0x3f3f3f3f;
//
//vector<pair<int, int>> adj[maxm][2], adj_rev[maxm][2], final_adj[maxm];
//int to_dist[maxn][2], from_dist[maxn][2], sol[maxn], n, costs[maxm][2];
//
//bool valid_path(int i, int j, int t, int cost) {
//    return to_dist[i][t] + cost == to_dist[j][t];
//}
//
//int main() {
//    setIO();
//    int m;
//    cin >> n >> m;
//    for (int i = 0; i < m; ++i) {
//        int a, b, p, q;
//        cin >> a >> b >> p >> q;
//        --a, --b;
//        adj[a][0].emplace_back(b, p);
//        adj[a][1].emplace_back(b, q);
//        final_adj[a].emplace_back(b, i);
//        adj_rev[b][0].emplace_back(a, p);
//        adj_rev[b][1].emplace_back(a, q);
//        costs[i][0] = p, costs[i][1] = q;
//    }
//    memset(to_dist, 0x3f, sizeof(to_dist));
//    memset(from_dist, 0x3f, sizeof(from_dist));
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//    for (int rep = 0; rep < 2; ++rep) {
//        to_dist[0][rep] = 0;
//        q.push({0, 0});
//        while (!q.empty()) {
//            int dist = q.top().first, ind = q.top().second;
//            q.pop();
//            if (to_dist[ind][rep] != dist) {
//                continue;
//            }
//            for (pair<int, int> i : adj[ind][rep]) {
//                int next_dist = dist + i.second;
//                if (to_dist[i.first][rep] > next_dist) {
//                    q.push({to_dist[i.first][rep] = next_dist, i.first});
//                }
//            }
//        }
//    }
//    //    for (int i = 0; i < n; ++i) {
//    //        cout << to_dist[i][0] << "\n";
//    //    }
//    //    cout << "\n";
//    //    for (int i = 0; i < n; ++i) {
//    //        cout << to_dist[i][1] << "\n";
//    //    }
//    //    cout << "\n";
//    assert(q.empty());
//    for (int rep = 0; rep < 2; ++rep) {
//        from_dist[n - 1][rep] = 0;
//        q.push({0, n - 1});
//        while (!q.empty()) {
//            int dist = q.top().first, ind = q.top().second;
//            q.pop();
//            if (from_dist[ind][rep] != dist) {
//                continue;
//            }
//            for (pair<int, int> i : adj_rev[ind][rep]) {
//                int next_dist = dist + i.second;
//                if (from_dist[i.first][rep] > next_dist) {
//                    q.push({from_dist[i.first][rep] = next_dist, i.first});
//                }
//            }
//        }
//    }
//    //    for (int i = 0; i < n; ++i) {
//    //        cout << from_dist[i][0] << "\n";
//    //    }
//    //    cout << "\n";
//    //    for (int i = 0; i < n; ++i) {
//    //        cout << from_dist[i][1] << "\n";
//    //    }
//    //    cout << "\n";
//    assert(q.empty());
//    memset(sol, 0x3f, sizeof(sol));
//    q.push({sol[0] = 0, 0});
//    while (!q.empty()) {
//        int dist = q.top().first, ind = q.top().second;
//        q.pop();
//        if (sol[ind] != dist) {
//            continue;
//        }
//        for (pair<int, int> i : final_adj[ind]) {
//            int next_dist = dist;
//            for (int j = 0; j < 2; ++j) {
//                if (!valid_path(ind, i.first, j, costs[i.second][j])) {
//                    ++next_dist;
//                }
//            }
//            if (sol[i.first] > next_dist) {
//                q.push({sol[i.first] = next_dist, i.first});
//            }
//        }
//    }
//    cout << sol[n - 1] << "\n";
//    return 0;
//}


/*
ID: izhang01
TASK: gpsduel
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gpsduel.in", "r", stdin);
    freopen("gpsduel.out", "w", stdout);
}
const int maxm = 5e4 + 5, maxn = 1e4 + 5, inf = 0x3f3f3f3f;

vector<pair<int, int>> adj[maxm][2], adj_rev[maxm][2], final_adj[maxm];
int to_dist[maxn][2], from_dist[maxn][2], sol[maxn], n, costs[maxm][2];
pair<int, unordered_set<int>> optimal[maxn][2];

bool valid_path(int i, int j, int t, int cost) {
    auto it = optimal[i][t].second.find(j);
    return it != optimal[i][t].second.end();
    //    return to_dist[i][t] + cost == to_dist[j][t];
}

int main() {
    setIO();
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        --a, --b;
        adj[a][0].emplace_back(b, p);
        adj[a][1].emplace_back(b, q);
        final_adj[a].emplace_back(b, i);
        adj_rev[b][0].emplace_back(a, p);
        adj_rev[b][1].emplace_back(a, q);
        costs[i][0] = p, costs[i][1] = q;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            optimal[i][j].first = inf;
        }
    }
    memset(to_dist, 0x3f, sizeof(to_dist));
    memset(from_dist, 0x3f, sizeof(from_dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int rep = 0; rep < 2; ++rep) {
        to_dist[0][rep] = 0;
        q.push({0, 0});
        while (!q.empty()) {
            int dist = q.top().first, ind = q.top().second;
            q.pop();
            if (to_dist[ind][rep] != dist) {
                continue;
            }
            for (pair<int, int> i : adj[ind][rep]) {
                int next_dist = dist + i.second;
                if (to_dist[i.first][rep] > next_dist) {
                    q.push({to_dist[i.first][rep] = next_dist, i.first});
                }
            }
        }
    }
    //    for (int i = 0; i < n; ++i) {
    //        cout << to_dist[i][0] << "\n";
    //    }
    //    cout << "\n";
    //    for (int i = 0; i < n; ++i) {
    //        cout << to_dist[i][1] << "\n";
    //    }
    //    cout << "\n";
    assert(q.empty());
    for (int rep = 0; rep < 2; ++rep) {
        from_dist[n - 1][rep] = 0;
        q.push({0, n - 1});
        while (!q.empty()) {
            int dist = q.top().first, ind = q.top().second;
            q.pop();
            if (from_dist[ind][rep] != dist) {
                continue;
            }
            for (pair<int, int> i : adj_rev[ind][rep]) {
                int next_dist = dist + i.second;
                if (from_dist[i.first][rep] > next_dist) {
                    q.push({from_dist[i.first][rep] = next_dist, i.first});
                }
            }
        }
    }
    for (int rep = 0; rep < 2; ++rep) {
        for (int i = 0; i < n; ++i) {
            for (pair<int, int> j : adj[i][rep]) {
                int dist = j.second + from_dist[j.first][rep];
                if (dist > inf) {
                    assert(false);
                }
                if (dist == optimal[i][rep].first) {
                    optimal[i][rep].second.insert(j.first);
                } else if (dist < optimal[i][rep].first) {
                    optimal[i][rep].first = dist;
                    optimal[i][rep].second.clear();
                    optimal[i][rep].second.insert(j.first);
                }
            }
        }
    }
    //    for (int i = 0; i < n; ++i) {
    //        cout << from_dist[i][0] << "\n";
    //    }
    //    cout << "\n";
    //    for (int i = 0; i < n; ++i) {
    //        cout << from_dist[i][1] << "\n";
    //    }
    //    cout << "\n";
    assert(q.empty());
    memset(sol, 0x3f, sizeof(sol));
    q.push({sol[0] = 0, 0});
    while (!q.empty()) {
        int dist = q.top().first, ind = q.top().second;
        q.pop();
        if (sol[ind] != dist) {
            continue;
        }
        for (pair<int, int> i : final_adj[ind]) {
            int next_dist = dist;
            for (int t = 0; t < 2; ++t) {
                if (!valid_path(ind, i.first, t, costs[i.second][t])) {
                    ++next_dist;
                }
            }
            if (sol[i.first] > next_dist) {
                q.push({sol[i.first] = next_dist, i.first});
            }
        }
    }
    cout << sol[n - 1] << "\n";
    return 0;
}
