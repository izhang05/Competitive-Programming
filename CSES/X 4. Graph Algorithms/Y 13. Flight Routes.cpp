#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("13.in", "r", stdin);
    freopen("13.out", "w", stdout);
    freopen("13.out", "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<pair<int, int>> adj[maxn];
priority_queue<long long> dist[maxn];

int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[0].push(0);
    pq.push({0, 0});
    while (!pq.empty()) {
        pair<long long, int> cur = pq.top();
        pq.pop();
        int node = cur.second;
        long long cost = cur.first;
        if (cost > dist[node].top()) {
            continue;
        }
        for (auto i : adj[node]) {
            if ((int) dist[i.first].size() < k) {
                dist[i.first].push(cost + i.second);
                pq.push({cost + i.second, i.first});
            } else if (cost + i.second < dist[i.first].top()) {
                dist[i.first].pop();
                dist[i.first].push(cost + i.second);
                pq.push({cost + i.second, i.first});
            }
        }
    }
    vector<long long> sol;
    while (!dist[n - 1].empty()) {
        sol.push_back(dist[n - 1].top());
        dist[n - 1].pop();
    }
    reverse(sol.begin(), sol.end());
    print(sol);
    return 0;
}
