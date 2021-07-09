/* Author: izhang05
 * Time: 07-09-2021 14:38:48
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int mod = 1e9 + 7, maxn = 6e5 + 10;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
long long w[maxn];
struct edge {
    int x, y, w1, w2;
};
edge edges[maxn];

vector<pair<int, int>> adj[maxn];

int main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        adj[0].emplace_back(i, w[i]);
        adj[i].emplace_back(0, w[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> edges[i].x >> edges[i].y >> edges[i].w1 >> edges[i].w2;
        adj[edges[i].x].emplace_back(edges[i].y, edges[i].w1 + edges[i].w2);
        adj[edges[i].y].emplace_back(edges[i].x, edges[i].w1 + edges[i].w2);
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    memset(w, 0x3f, sizeof(w));
    w[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        pair<long long, int> cur = pq.top();
        pq.pop();
        if (w[cur.second] != cur.first) {
            continue;
        }
        for (auto &i : adj[cur.second]) {
            if (w[i.first] > cur.first + i.second) {
                pq.push({w[i.first] = cur.first + i.second, i.first});
            }
        }
    }
    return 0;
}
