#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int maxn = 2500, inf = 1e9;
vector<int> adj[maxn];
bool visited[maxn];
int dist[maxn];

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int sol = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[j] = false;
        }
        queue<pair<pair<int, int>, int> > q;
        q.push(make_pair(make_pair(i, 0), -1));
        visited[i] = true;
        bool found = false;
        while (!q.empty()) {
            pair<pair<int, int>, int> cur = q.front();
            q.pop();
            visited[cur.first.first] = true;
            dist[cur.first.first] = cur.first.second;
            for (int j : adj[cur.first.first]) {
                if (!visited[j]) {
                    q.push(make_pair(make_pair(j, cur.first.second + 1), cur.first.first));
                } else if (j != cur.second) {
                    sol = min(sol, dist[cur.first.first] + dist[j] + 1);
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
    }
    cout << (sol == inf ? -1 : sol) << "\n";
    return 0;
}
