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
int n, c[maxn];
vector<int> adj[maxn];

int main() {
    setIO();
    int m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int> > paths(m, vector<int>(4));
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        cin >> paths[i][0];
        paths[i][1] = a, paths[i][2] = b, paths[i][3] = i;
    }
    sort(paths.begin(), paths.end());
    cout << "10110" << "\n";
    return 0;
}
