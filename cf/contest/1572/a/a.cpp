/* Author: izhang05
 * Time: 09-28-2021 16:10:08
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn], radj[maxn];
int in_deg[maxn], dist[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        radj[i].clear();
        in_deg[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            --a;
            if (a < i) {
                adj[a].emplace_back(i, 0);
                radj[i].emplace_back(a, 0);
            } else {
                adj[a].emplace_back(i, 1);
                radj[i].emplace_back(a, 1);
            }
            ++in_deg[i];
        }
    }
    memset(dist, 0, sizeof(dist));
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!in_deg[i]) {
            q.push(i);
            dist[i] = 1;
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ++cnt;
        for (auto &i : adj[cur]) {
            if (--in_deg[i.first] == 0) {
                q.push(i.first);
            }
            dist[i.first] = max(dist[i.first], dist[cur] + i.second);
        }
    }
    if (cnt != n) {
        cout << -1 << "\n";
        return;
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, dist[i]);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
