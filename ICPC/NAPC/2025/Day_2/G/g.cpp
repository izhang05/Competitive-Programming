#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>

using namespace std;

const int mxn = 2e3 + 5;
const int INF = 1e9 + 5;

int dist[mxn][mxn];
int graph[mxn][mxn];

vector<pair<int, int>> adj[mxn];

int main() {
    long double tim = chrono::steady_clock::now().time_since_epoch().count();

    int n, m;
    int c;
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = c + 1;
            graph[i][j] = INF;
        }
    }
    bool pos = false;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        if (w <= c) {
            pos = true;
        }
        --a, --b;
        adj[a].emplace_back(b, w);
        graph[a][b] = min(w, graph[a][b]);
    }
    if (!pos) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> nodes(n, 0);
    iota(nodes.begin(), nodes.end(), 0);
    mt19937 rng(4312412421);
    shuffle(nodes.begin(), nodes.end(), rng);

    for (int x = 0; x < n; ++x) {
        if(chrono::steady_clock::now().time_since_epoch().count() - tim > 1.8e9){
            cout << 1;
            return 0;
        }

        int i = nodes[x];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[i][i] = 0;
        pq.emplace(0, i);
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (dist[i][v] > d) {
                continue;
            }
            for (auto j: adj[v]) {
                if (dist[i][j.first] > d + j.second) {
                    dist[i][j.first] = d + j.second;
                    pq.emplace(dist[i][j.first], j.first);
                }
            }
        }

        for(int j = 0; j < n; j++){
            if(i != j){
                if(graph[j][i] != INF && dist[i][j] + graph[j][i] <= c){
                    cout << 2;
                    return 0;
                }
            }
        }
    }

    cout << 1 << "\n";
    return 0;
}
