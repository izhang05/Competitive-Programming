/*
ID: izhang01
TASK: decorate
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("decorate.in", "r", stdin);
    freopen("decorate.out", "w", stdout);
}

const int maxn = 50000;
int j, f;
set<int> adj[maxn];
bool visited[maxn];
char sign[maxn];
bool possible = true;
int sol = 0;

void dfs(int node, char s) {
    if (s == 'J') {
        ++j;
    } else {
        ++f;
    }
    visited[node] = true;
    sign[node] = s;
    for (int i : adj[node]) {
        if (visited[i]) {
            if (sign[i] == s) {
                possible = false;
                return;
            }
        } else {
            if (s == 'J') {
                dfs(i, 'F');
            } else {
                dfs(i, 'J');
            }
        }
        if (!possible) {
            return;
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
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            f = 0, j = 0;
            dfs(i, 'J');
            sol += max(f, j);
            if (!possible) {
                break;
            }
//            cout << f << " " << j << " " << i << "\n";
        }
    }
    if (!possible) {
        cout << -1 << "\n";
    } else {
        cout << sol << "\n";
    }
    return 0;
}
