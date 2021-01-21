/*
ID: izhang01
TASK: timeline
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
}
const int maxn = 1e5;
int deg[maxn];
vector<pair<int, int> > adj[maxn];

int main() {
    setIO();
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> s(n), sol(n, 1e9);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sol[i] = s[i];
    }
    int a, b, x;
    for (int i = 0; i < c; ++i) {
        cin >> a >> b >> x;
        --a, --b;
        adj[a].emplace_back(b, x);
        ++deg[b];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (pair<int, int> i : adj[cur]) {
            if (--deg[i.first] == 0) {
                q.push(i.first);
            }
            sol[i.first] = max(sol[i.first], sol[cur] + i.second);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
