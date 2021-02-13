#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 2e5;
vector<int> adj[maxn];
int n, dist[maxn], sol[maxn];


void bfs(int node) {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
    }
    queue<pair<int, int> > q;
    q.push(make_pair(node, 0));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        dist[cur.first] = cur.second;
        for (int i : adj[cur.first]) {
            if (dist[i] == -1) {
                q.push(make_pair(i, cur.second + 1));
            }
        }
    }
}

pair<int, int> farthest() {
    pair<int, int> res;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > res.first) {
            res.first = dist[i];
            res.second = i;
        }
    }
    return res;
}


int main() {
    setIO();

    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    bfs(farthest().second);
    for (int i = 0; i < n; ++i) {
        sol[i] = dist[i];
    }
    bfs(farthest().second);
    for (int i = 0; i < n; ++i) {
        cout << max(dist[i], sol[i]) << " ";
    }
    cout << "\n";
    return 0;
}
