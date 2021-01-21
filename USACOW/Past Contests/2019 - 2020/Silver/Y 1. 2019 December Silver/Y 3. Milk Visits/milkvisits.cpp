/*
ID: izhang01
TASK: milkvisits
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
}

const int maxn = 1e5;
int comp[maxn];
bool visited[maxn];
vector<int> adj[maxn];
string cow;
int c;
void dfs(int n) {
    visited[n] = true;
    comp[n] = c;
    for (int i: adj[n]) {
        if (!visited[i] && cow[i] == cow[n]) {
            dfs(i);
        }
    }
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m >> cow;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
            ++c;
        }
    }
    char p;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> p;
        --a, --b;
        if (comp[a] != comp[b] || cow[a] == p) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << "\n";
    return 0;
}
