#include <bits/stdc++.h>

#define INF 1000000000
typedef long long ll;

using namespace std;

ll M, N;
ll A, B;
ll T;
vector<int> lines[101];
vector<int> stations[11];
vector<int> adj[101][11];

ll dist[101][101];
// [station i][j swaps]

struct node {
    ll station, swaps, dist, cur_line;

    node(ll station, ll swaps, ll dist, ll cur_line) :
            station(station), swaps(swaps), dist(dist), cur_line(cur_line) {}

    bool operator<(const node &other) const {
        return dist > other.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;
    cin >> A;

    for (int i = 1; i <= N; ++i) {
        int S;
        cin >> S;
        vector<int> v;
        for (int j = 1; j <= S; ++j) {
            int x;
            cin >> x;
            v.push_back(x);
            lines[x].push_back(i);
        }
        for (int j = 0; j < S - 1; ++j) {
            /* cout << "STATION: " << i << " " << v[j] << " " << v[j+1] << endl; */
            adj[v[j]][i].push_back(v[j + 1]);
            adj[v[j + 1]][i].push_back(v[j]);
        }
        stations[i] = v;
    }

    priority_queue<node> q;
    for (auto zz: lines[1]) {
        /* cout << "HUH: " << zz << endl; */
        q.emplace(1, 0, 0, zz);
    }

    for (int kk: adj[1][1]) {
        /* cout << "HUH: " << kk << endl; */
    }

    memset(dist, 63, sizeof(dist));
    /* dist[1][0] = 0; */

    while (!q.empty()) {
        auto [station, swaps, d, cur_line] = q.top();
        /* cout << station << " " << swaps << " " << d << " " << cur_line << endl; */
        q.pop();
        if (dist[station][swaps] <= d) continue;
        dist[station][swaps] = d;
        for (auto next_station: adj[station][cur_line]) {
            q.emplace(next_station, swaps, d + A, cur_line);
        }
        for (auto next_line: lines[station]) {
            if (next_line == cur_line) continue;
            if (swaps + 1 > 100) continue;
            q.emplace(station, swaps + 1, d, next_line);
        }
    }

    cin >> T;
    while (T--) {
        cin >> B;
        ll ans = 1e18;
        for (int i = 0; i <= 100; ++i) {
            ans = min(ans, dist[M][i] + i * B);
        }
        cout << ans << endl;
    }

    return 0;
}