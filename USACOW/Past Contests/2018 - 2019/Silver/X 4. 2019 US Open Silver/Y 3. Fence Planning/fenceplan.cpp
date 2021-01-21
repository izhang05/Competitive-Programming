/*
ID: izhang01
TASK: fenceplan
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
}

const int maxn = 1e5;
bool visited[maxn];
vector<int> adj[maxn];
vector<pair<int, int> > cows;
int max_x, min_x, max_y, min_y;

void dfs(int n) {
    visited[n] = true;
    max_x = max(max_x, cows[n].first);
    min_x = min(min_x, cows[n].first);
    max_y = max(max_y, cows[n].second);
    min_y = min(min_y, cows[n].second);
    for (int i : adj[n]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}


int main() {
    setIO();
    int n, m;
    int sol = 1e9;
    cin >> n >> m;
    cows.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            max_x = 0, min_x = 1e9, max_y = 0, min_y = 1e9;
            dfs(i);
//            cout << max_x << " " << min_x << " " << max_y << " " << min_y << "\n";
            sol = min(sol, 2 * (max_x - min_x + max_y - min_y));
        }
    }
    cout << sol << "\n";
    return 0;
}
