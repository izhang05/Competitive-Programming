#include "race.h"
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5, inf = 1e9;
vector<pair<int, int>> adj[maxn];
long long sol = inf, k, sub[maxn];
bool visited[maxn];
unordered_map<long long, long long> occ;

int find_centroid(int c, int p, long long s) {
    for (auto &i : adj[c]) {
        if (i.first != p && !visited[i.first] && sub[i.first] > s / 2) {
            return find_centroid(i.first, c, s);
        }
    }
    return c;
}

int find_size(int c, int p) {
    sub[c] = 1;
    for (auto &i : adj[c]) {
        if (i.first != p && !visited[i.first]) {
            sub[c] += find_size(i.first, c);
        }
    }
    return sub[c];
}

void dfs(int c, int p, bool add, long long dist, long long depth) {
    if (dist > k) {
        return;
    }
    if (add) {
        if (occ.find(k - dist) != occ.end()) {
#ifdef DEBUG
            cout << c << " " << p << " " << dist << " " << k - dist << " " << depth << " " << occ[k - dist] << "\n";
#endif
            sol = min(sol, occ[k - dist] + depth);
        }
    } else {
        if (occ.find(dist) == occ.end()) {
            occ[dist] = depth;
        } else {
            occ[dist] = min(occ[dist], depth);
        }
    }
    for (auto &i : adj[c]) {
        if (i.first != p && !visited[i.first]) {
            dfs(i.first, c, add, dist + i.second, depth + 1);
        }
    }
}

void solve(int v) {
    find_size(v, -1);
    int c = find_centroid(v, -1, sub[v]);
#ifdef DEBUG
    cout << "c: " << c << endl;
#endif
    visited[c] = true;
    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            dfs(i.first, c, true, i.second, 1);
            dfs(i.first, c, false, i.second, 1);
        }
    }
    if (occ.find(k) != occ.end()) {
        sol = min(sol, occ[k]);
    }
    unordered_map<long long, long long> empty;
    occ.swap(empty);
    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            solve(i.first);
        }
    }
}

int best_path(int N, int K, int H[][2], int L[]) {
    k = K;
    for (int i = 0; i < N - 1; ++i) {
        adj[H[i][0]].emplace_back(H[i][1], L[i]);
        adj[H[i][1]].emplace_back(H[i][0], L[i]);
    }
    solve(0);
    return sol == inf ? -1 : sol;
}