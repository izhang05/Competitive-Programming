#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int mod = 1e9 + 7, maxn = 2e3 + 5;
const long long inf = 1e18;
int grid[maxn][maxn];

int parent[maxn];
vector<pair<int, int>> adj[maxn];
long long dist[maxn][maxn];

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        parent[xroot] = yroot;
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

int n;

int main() {
    setIO("c");

    cin >> n;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
            cin >> grid[i][j];
            if (i == j && grid[i][j]) { // main diagonal should be 0
                cout << "NO"
                     << "\n";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((grid[i][j] != grid[j][i]) || grid[i][j] == 0) {
                cout << "NO"
                     << "\n";
                return 0;
            }
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pq.push({grid[i][j], {i, j}});
        }
    }
    while (!pq.empty()) {
        pair<int, pair<int, int>> cur = pq.top();
        pq.pop();
        if (merge(cur.second.first, cur.second.second)) {
            adj[cur.second.first].emplace_back(cur.second.second, cur.first);
            adj[cur.second.second].emplace_back(cur.second.first, cur.first);
        }
    }
    for (int i = 0; i < n; ++i) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &j : adj[cur]) {
                if (dist[i][j.first] > dist[i][cur] + j.second) {
                    q.push(j.first);
                    dist[i][j.first] = dist[i][cur] + j.second;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] != grid[i][j]) {
                cout << "NO"
                     << "\n";
                return 0;
            }
        }
    }
    cout << "YES"
         << "\n";
    return 0;
}
