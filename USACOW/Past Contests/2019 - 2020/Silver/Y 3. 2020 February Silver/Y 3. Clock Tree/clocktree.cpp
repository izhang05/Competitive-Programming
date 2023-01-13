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
    cin.exceptions(istream::failbit);
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    freopen("clocktree.out", "w", stderr);
}
//#define DEBUG
const int maxn = 2505;
int c[maxn], cur_c[maxn], n;
vector<int> adj[maxn];

void dfs(int cur, int p) {
//    cout << cur << " " << p << " " << cur_c[cur] << "\n";
    if (p != -1) {
        ++cur_c[cur];
        cur_c[cur] %= 12;
    }
    for (auto &i : adj[cur]) {
        if (i != p) {
            dfs(i, cur);
        }
    }
    if (p != -1) {
        int diff = 12 - cur_c[cur];
        cur_c[cur] += diff;
        cur_c[cur] %= 12;
        cur_c[p] += diff + 1;
        cur_c[p] %= 12;
    }
//    cout << cur << " " << p << " " << cur_c[cur] << "\n";
}

bool solve(int root) {
    for (int i = 0; i < n; ++i) {
        cur_c[i] = c[i];
    }
    dfs(root, -1);
    return cur_c[root] == 0 || cur_c[root] == 1;
}

int main() {
    setIO();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        c[i] %= 12;
    }
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += solve(i);
        //        cout << i << " " << solve(i) << " " << cur_c[i] << "\n";
    }
    cout << sol << "\n";
    return 0;
}
