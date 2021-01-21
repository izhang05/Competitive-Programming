#ifndef DEBUG
#include <traffic.h>
#endif

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5, inf = 2e9;
vector<int> adj[maxn];
int down[maxn], v[maxn], n, con[maxn];

void dfs(int node, int p) {
    for (int i : adj[node]) {
        if (i != p) {
            dfs(i, node);
            int cur = down[i] + v[i];
            down[node] += cur;
            con[node] = max(con[node], cur);
        }
    }
}

int LocateCentre(int cur_n, int cur_p[], int s[], int d[]) {
    n = cur_n;
    for (int i = 0; i < n - 1; ++i) {
        adj[s[i]].push_back(d[i]);
        adj[d[i]].push_back(s[i]);
    }
    for (int i = 0; i < n; ++i) {
        v[i] = cur_p[i];
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        con[i] = max(con[i], down[0] - down[i] - v[i] + v[0]);
    }
    pair<int, int> sol = {inf, 0};
    for (int i = 0; i < n; ++i) {
        sol = min(sol, make_pair(con[i], i));
    }
    return sol.second;
}

#ifdef DEBUG

int main() {
    const int n = 5;
    int p[n]{3, 5, 8, 10, 9}, s[n - 1]{0, 1, 2, 3}, d[n - 1]{1, 2, 3, 4};
    cout << LocateCentre(n, p, s, d) << "\n";
}

#endif