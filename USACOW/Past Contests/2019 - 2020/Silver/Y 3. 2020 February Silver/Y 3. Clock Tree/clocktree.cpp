/*
ID: izhang01
TASK: clocktree
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
}

const int maxn = 2500;
int n, clocks[maxn], clocks_copy[maxn];
vector<int> adj[maxn];
bool visited[maxn];

void start_dfs(int node, int parent) {
    visited[node] = true;
    for (int i : adj[node]) {
        if (!visited[i]) {
            start_dfs(i, node);
        }
    }
    if (parent != -1) {
        clocks[parent] += 12 - clocks[node];
        clocks[parent] %= 12;
        clocks[node] = 0;
    }
}

int main() {
    setIO();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> clocks_copy[i];
        clocks_copy[i] %= 12;
    }
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        copy(begin(clocks_copy), end(clocks_copy), begin(clocks));
        for (int j = 0; j < n; ++j) {
            visited[j] = false;
        }
        start_dfs(i, -1);
        ++sol;
        if (!(clocks[i] == 0 || clocks[i] == 1)) {
            --sol;
        } else {
            for (int j = 0; j < n; ++j) {
                if (j != i) {
//                    cout << j << " " << clocks[j] << "\n";
                    if (clocks[j] != 0) {
                        --sol;
                        break;
                    }
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
