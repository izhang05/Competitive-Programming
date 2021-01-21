/*
ID: izhang01
TASK: meeting
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("meeting.in", "r", stdin);
    freopen("meeting.out", "w", stdout);
}

const int maxn = 100;
unordered_set<int> db[maxn], de[maxn];
vector<pair<int, int>> adj_d[maxn], adj_e[maxn];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b, c, d;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c >> d;
        --a, --b;
        adj_d[a].emplace_back(b, c);
        adj_e[a].emplace_back(b, d);
    }
    db[0] = de[0] = {0};
    for (int i = 0; i < n; ++i) {
        for (pair<int, int> j : adj_d[i]) {
            for (int k : db[i]) {
                db[j.first].insert(k + j.second);
            }
        }
        for (pair<int, int> j : adj_e[i]) {
            for (int k : de[i]) {
                de[j.first].insert(k + j.second);
            }
        }
    }
    int sol = 1e9;
    for (int i : db[n - 1]) {
        if (de[n - 1].find(i) != de[n - 1].end()) {
            sol = min(sol, i);
        }
    }
    if (sol == 1e9) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        cout << sol << "\n";
    }
    return 0;
}
