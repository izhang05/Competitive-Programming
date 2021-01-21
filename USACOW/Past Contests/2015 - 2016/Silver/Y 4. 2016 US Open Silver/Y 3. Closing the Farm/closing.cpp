/*
ID: izhang01
TASK: closing
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
}

const int maxn = 3000;
bool deleted[maxn];
bool visited[maxn];
vector<int> adj[maxn];


void dfs(int node) {
    visited[node] = true;
    if (deleted[node]) {
        return;
    }
    bool last = true;
    for (int i: adj[node]) {
        if (!deleted[i] && !visited[i]) {
            last = false;
            break;
        }
    }
    if (last) {
        return;
    }
    for (int i : adj[node]) {
        if (!deleted[i] && !visited[i]) {
            dfs(i);
        }
    }
}


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
    int d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[j] = false;
        }

        for (int j = 0; j < n; ++j) {
            if (!deleted[j]) {
                dfs(j);
                break;
            }
        }
        string answer = "YES";
        for (int j = 0; j < n; ++j) {
//            cout << deleted[j] << " " << visited[j] << "\n";
            if (!visited[j] && !deleted[j]) {
                answer = "NO";
                break;
            }
        }
        cout << answer << "\n";
        cin >> d;
        deleted[d - 1] = true;
    }
    return 0;
}