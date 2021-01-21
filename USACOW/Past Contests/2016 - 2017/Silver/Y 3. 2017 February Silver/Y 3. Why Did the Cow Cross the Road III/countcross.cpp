/*
ID: izhang01
TASK: countcross
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
}

map<pair<int, int>, int> component;
map<pair<int, int>, bool> visited;
map<pair<int, int>, vector<pair<int, int> > > adj;
int num;

void dfs(pair<int, int> n) {
    visited[n] = true;
    component[n] = num;
    for (pair<int, int> i : adj[n]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}


int main() {
    setIO();
    int n, k, r;
    cin >> n >> k >> r;
    visited[pair<int, int>{0, 0}] = false;
    for (int i = 1; i < n; ++i) {
        visited[pair<int, int>{0, i}] = false;
        adj[pair<int, int>{0, i}].emplace_back(0, i - 1);
        adj[pair<int, int>{0, i - 1}].emplace_back(0, i);
    }
    for (int i = 1; i < n; ++i) {
        visited[pair<int, int>{i, 0}] = false;
        adj[pair<int, int>{i, 0}].emplace_back(i - 1, 0);
        adj[pair<int, int>{i - 1, 0}].emplace_back(i, 0);
        for (int j = 1; j < n; ++j) {
            visited[pair<int, int>{i, j}] = false;
            adj[pair<int, int>{i, j}].emplace_back(i - 1, j);
            adj[pair<int, int>{i - 1, j}].emplace_back(i, j);
            adj[pair<int, int>{i, j}].emplace_back(i, j - 1);
            adj[pair<int, int>{i, j - 1}].emplace_back(i, j);
        }
    }
    int r1, r2, c1, c2;
    for (int i = 0; i < r; ++i) {
        cin >> r1 >> c1 >> r2 >> c2;
        --r1, --r2, --c1, --c2;
        adj[pair<int, int>{r1, c1}].erase(
                remove(adj[pair<int, int>{r1, c1}].begin(), adj[pair<int, int>{r1, c1}].end(), pair<int, int>{r2, c2}),
                adj[pair<int, int>{r1, c1}].end());
        adj[pair<int, int>{r2, c2}].erase(
                remove(adj[pair<int, int>{r2, c2}].begin(), adj[pair<int, int>{r2, c2}].end(), pair<int, int>{r1, c1}),
                adj[pair<int, int>{r2, c2}].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[pair<int, int>{i, j}]) {
                dfs(pair<int, int>{i, j});
                ++num;
            }
        }
    }
    vector<pair<int, int> > cows(k);
    for (int i = 0; i < k; ++i) {
        cin >> cows[i].first >> cows[i].second;
        --cows[i].first, --cows[i].second;
    }
    int sol = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
//            cout << cows[i].first << " " << cows[i].second << " " << i << " " << component[cows[i]] << "\n";
//            cout << cows[j].first << " " << cows[j].second << " " << j << " " << component[cows[j]] << "\n";
            if (component[cows[i]] != component[cows[j]]) {
//                cout << i << " " << j << "\n";
                ++sol;
            }
        }
    }
//    for (pair<int, int> i : adj[pair<int, int>{2, 2}]) {
//        cout << i.first << " " << i.second << "\n";
//    }
    cout << sol << "\n";
    return 0;
}
