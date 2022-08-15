#include "crocodile.h"
#ifdef LOCAL
#include "crocodile_grader.cpp"
#endif
 
#include <bits/stdc++.h>
 
using namespace std;
//#define DEBUG
const int maxn = 1e5 + 5, inf = 2e9;
int sol[maxn];
vector<pair<int, int>> adj[maxn];
pair<int, int> c[maxn];
bool ex[maxn];
set<pair<int, int>> q;
 
void comb(int node, int cost) {
    if (cost < c[node].first) {
        if (c[node].second != inf) {
            q.erase({c[node].second, node});
        }
        swap(c[node].first, c[node].second);
        c[node].first = cost;
        if (c[node].second != inf) {
            q.insert({c[node].second, node});
        }
 
    } else if (cost < c[node].second) {
        if (c[node].second != inf) {
            q.erase({c[node].second, node});
        }
        c[node].second = cost;
        q.insert({c[node].second, node});
    }
}
 
int travel_plan(int n, int m, int r[][2], int l[], int k, int p[]) {
    for (int i = 0; i < m; ++i) {
        int a = r[i][0], b = r[i][1], cost = l[i];
        adj[a].emplace_back(b, cost);
        adj[b].emplace_back(a, cost);
    }
    for (int i = 0; i < n; ++i) {
        sol[i] = inf;
        c[i] = {inf, inf};
    }
    for (int i = 0; i < k; ++i) {
        sol[p[i]] = 0;
        ex[p[i]] = true;
    }
    for (int i = 0; i < k; ++i) {
        for (auto j : adj[p[i]]) {
            if (!ex[j.first]) {
                comb(j.first, j.second);
            }
        }
    }
    while (sol[0] == inf) {
        pair<int, int> cur = *q.begin();
        q.erase(q.begin());
        int node = cur.second, cost = cur.first;
        sol[node] = cur.first;
        for (auto i : adj[node]) {
            if (sol[i.first] == inf) {
                comb(i.first, cost + i.second);
            }
        }
    }
#ifdef DEBUG
    for (int j = 0; j < n; ++j) {
        cout << sol[j] << "\n";
    }
#endif
    return sol[0];
}