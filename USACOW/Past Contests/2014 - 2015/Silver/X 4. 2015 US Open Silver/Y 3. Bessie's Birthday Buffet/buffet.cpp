/*
ID: izhang01
TASK: buffet
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("buffet.in", "r", stdin);
    freopen("buffet.out", "w", stdout);
}

const int maxn = 1001;
int n, e;
vector<pair<int, int> > quality;
vector<int> adj[maxn];
int dist[maxn][maxn]; // distance between first and second
bool visited[maxn];

void bfs(int node) {
    queue<pair<int, int> > q;
    q.push(make_pair(node, 0));
    visited[node] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        dist[node][cur.first] = cur.second;
        for (int i : adj[cur.first]) {
            if (!visited[i]) {
                q.push(make_pair(i, cur.second + 1));
                visited[i] = true;
            }
        }
    }
}

int dp[maxn];

int main() {
    setIO();
    cin >> n >> e;
    int d, q;
    for (int i = 0; i < n; ++i) {
        cin >> d >> q;
        quality.emplace_back(d, i);
        int a;
        for (int j = 0; j < q; ++j) {
            cin >> a;
            adj[i].push_back(a - 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[j] = false;
        }
        bfs(i);
    }
    sort(quality.begin(), quality.end());

    int sol = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = quality[i].first;
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[i], dp[j] - dist[quality[j].second][quality[i].second] * e + quality[i].first);
        }
        sol = max(sol, dp[i]);
    }

    cout << sol << "\n";
    return 0;
}
