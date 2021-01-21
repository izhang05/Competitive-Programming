/*
ID: izhang01
TASK: msched
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("msched.in", "r", stdin);
    freopen("msched.out", "w", stdout);
}
const int maxn = 1e5 + 1;
vector<int> adj[maxn]; // outgoing edges
int dist[maxn], a[maxn];

int find_dist(int n) {
    if (dist[n]) {
        return dist[n];
    }
    int cur = 0;
    for (int i : adj[n]) {
        cur = max(cur, find_dist(i));
    }
    return dist[n] = cur + a[n];
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int b, c;
    for (int i = 0; i < m; ++i) {
        cin >> b >> c;
        --b, --c;
        adj[c].push_back(b);
    }

    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, find_dist(i));
    }
    cout << sol << "\n";
    return 0;
}
