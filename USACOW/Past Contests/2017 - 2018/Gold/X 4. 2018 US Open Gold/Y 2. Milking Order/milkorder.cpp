/*
ID: izhang01
TASK: milkorder
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    vector<int> observe[m];
    set<int> adj[n];
    int b, state[n], deg[n];
    for (int i = 0; i < m; ++i) {
        cin >> b;
        int c;
        for (int j = 0; j < b; ++j) {
            cin >> c;
            observe[i].push_back(c - 1);
        }
    }
    int low = 0, high = m - 1, mid;
    vector<int> sol;
    while (low <= high) {
        mid = (low + high) / 2;
        for (int i = 0; i < n; ++i) {
            state[i] = 0;
            deg[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < mid; ++i) {
            for (int j = 0; j < observe[i].size() - 1; ++j) {
                adj[observe[i][j]].insert(observe[i][j + 1]);
                ++deg[observe[i][j + 1]];
            }
        }
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                q.push(i);
            }
        }
        vector<int> path;
        while (!q.empty()) {
            int cur = q.top();
            q.pop();
            path.push_back(cur + 1);
            for (int i : adj[cur]) {
                if (--deg[i] == 0) {
                    q.push(i);
                }
            }
        }
        bool pos = true;
        for (int i = 0; i < n; ++i) {
            if (deg[i] > 0) {
                pos = false;
            }
        }
        if (pos) {
            sol = path;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << sol[0];
    sol.erase(sol.begin());
    for (int i : sol) {
        cout << " " << i;
    }
    cout << "\n";
    return 0;
}
