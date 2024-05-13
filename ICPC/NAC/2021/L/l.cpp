#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Unknown
 * Date: 2002-09-13
 * Source: predates tinyKACTL
 * Description: Topological sorting. Given is an oriented graph.
 * Output is an ordering of vertices, such that there are edges only from left to right.
 * If there are cycles, the returned list will have size smaller than  -- nodes reachable
 * from cycles will not be returned.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */

vi topoSort(const vector<vi> &gr) {
    vi indeg(sz(gr)), ret;
    for (auto &li: gr) for (int x: li) indeg[x]++;
    queue<int> q; // use priority_queue for lexic. largest ans.
    rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int i = q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        for (int x: gr[i])
            if (--indeg[x] == 0) q.push(x);
    }
    return ret;
}


const int mxn = 2e5 + 5;
vector<pair<int, long long>> adj[mxn];
long long dist[mxn];
set<int> pre[mxn];
pair<int, bool> dp[mxn]; // dp[v] = <largest index j such that times t[0...j] have been encountered in path from 0 to v, more than one path?>
int pre_node[mxn];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
    }
    vector<long long> t(d);
    for (auto &i: t) {
        cin >> i;
    }
    sort(t.begin(), t.end());
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        pair<long long, int> cur = pq.top();
        pq.pop();
        if (cur.first != dist[cur.second]) {
            continue;
        }
        for (auto &i: adj[cur.second]) {
            if (dist[i.first] > cur.first + i.second) {
                dist[i.first] = cur.first + i.second;
                pre[i.first] = set<int>{cur.second};
                pq.push({dist[i.first], i.first});
            } else if (dist[i.first] == cur.first + i.second) {
                pre[i.first].insert(cur.second);
            }
        }
    }
    vector<vector<int>> new_adj(n);
    for (int i = 0; i < n; ++i) {
        for (auto &j: pre[i]) {
            new_adj[j].push_back(i);
        }
    }
    vector<int> order = topoSort(new_adj);
    // 0 will be first in order
    for (int i = 0; i < n; ++i) {
        dp[i] = {-1, 0};
    }
    if (t[0] == 0) {
        dp[0] = {1, 0};
    } else {
        dp[0] = {0, 0};
    }
    for (auto &i: order) {
        if (dp[i].first == -1) {
            continue;
        }
        for (auto &j: new_adj[i]) {
            pair<int, int> nxt = dp[i];
//            cout << i << " " << j << " " << t[nxt.first] << " " << dist[j] << "\n";
            if (dp[i].first != d && t[dp[i].first] == dist[j]) {
                ++nxt.first;
            }
            if (dp[j].first < nxt.first) {
                pre_node[j] = i;
                dp[j] = nxt;
            } else if (dp[j].first == nxt.first) {
                dp[j].second = true;
            }
        }
    }
//    for (int i = 0; i < n; ++i) {
//        cout << i << " " << dp[i].first << " " << dp[i].second << "\n";
//    }
    if (dp[n - 1].first != d) {
        cout << 0 << "\n";
    } else if (dp[n - 1].second) {
        cout << 1 << "\n";
    } else {
        vector<int> sol;
        int cur = n - 1;
        sol.push_back(cur + 1);
        while (cur != 0) {
            cur = pre_node[cur];
            sol.push_back(cur + 1);
        }
        cout << sol.size() << "\n";
        reverse(sol.begin(), sol.end());
        for (auto &i: sol) {
            cout << i << "\n";
        }

    }
}