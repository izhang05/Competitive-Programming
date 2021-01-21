/*
ID: izhang01
TASK: cruise
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
}


int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int> > adj(n);
    vector<char> dir(m);
    vector<int> pre;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[i].first = a, adj[i].second = b;
    }
    for (int i = 0; i < m; ++i) {
        cin >> dir[i];
    }
    int loc = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dir[j] == 'L') {
                loc = adj[loc].first;
            } else {
                loc = adj[loc].second;
            }
        }
        auto it = find(pre.begin(), pre.end(), loc);
        if (it != pre.end()) {
            int index = it - pre.begin();
            cout << pre[(index + (k - 1 - i) % (pre.size() - index))] + 1 << "\n";
            return 0;
        }
        pre.push_back(loc);
    }
    cout << loc + 1 << "\n";
    return 0;
}
