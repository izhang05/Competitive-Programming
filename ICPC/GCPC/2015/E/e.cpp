#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b)
#define all(x) begin(x), end(x)
#define sz(x) (long long) (x).size()
typedef long long ll;
typedef pair<long long, long long> pii;
typedef vector<long long> vi;

const long long mxn = 1e4 + 5, inf = 1e9;

vector<pair<long long, long long>> adj[mxn];

pair<long long, long long> dist[mxn]; // 1 in second coordinate = unique, 0 = not unique
map<pair<long long, long long>, long long> mn_edge;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> order(k);
    for (long long i = 0; i < k; ++i) {
        cin >> order[i];
        --order[i];
    }
    for (long long i = 0; i < m; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        if (a > b) {
            swap(a, b);
        }
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        if (mn_edge.find({a, b}) == mn_edge.end()) {
            mn_edge[{a, b}] = c;
        }
        mn_edge[{a, b}] = min(mn_edge[{a, b}], c);
    }
    for (long long i = 0; i < n; ++i) {
        dist[i] = {inf, inf};
    }
    dist[0] = {0, 1};
    priority_queue<pair<pair<long long, long long>, long long>, vector<pair<pair<long long, long long>, long long>>, greater<>> pq;
    pq.push({{0, 1}, 0});
    while (!pq.empty()) {
        pair<pair<long long, long long>, long long> cur = pq.top();
        pq.pop();
        if (cur.first != dist[cur.second]) {
            continue;
        }
        for (auto &i: adj[cur.second]) {
            pair<long long, long long> nxt_dist = cur.first;
            nxt_dist.first += i.second;
            if (dist[i.first].first == nxt_dist.first) {
                nxt_dist.second = 0;
            }
            if (dist[i.first] > nxt_dist) {
                dist[i.first] = nxt_dist;
                pq.push({nxt_dist, i.first});
            }
        }
    }
    if (dist[n - 1].second == 0) {
        cout << "yes" << "\n";
        return 0;
    }
    long long orig_dist = 0;
    for (int i = 1; i < n; ++i) {
        pair<int, int> cur_edge{order[i - 1], order[i]};
        if (order[i - 1] > order[i]) {
            swap(cur_edge.first, cur_edge.second);
        }
        orig_dist += mn_edge[cur_edge];
    }
//    cout << orig_dist << " " << dist[n - 1].first << "\n";
    cout << (dist[n - 1].first == orig_dist ? "no" : "yes") << "\n";
    return 0;
}