/*
ID: izhang01
TASK: disrupt
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
    freopen("disrupt.out", "w", stderr);
}
//#define DEBUG
const int maxn = 5e4 + 5;
vector<pair<int, int>> adj[maxn];
vector<int> endp[maxn];
int sol[maxn], w[maxn];


set<pair<int, int>> dfs(int c, int p) {
    set<pair<int, int>> cur;
    for (auto i : endp[c]) {
        cur.insert({w[i], i});
    }

    for (auto i : adj[c]) {
        if (i.first != p) {
            set<pair<int, int>> next = dfs(i.first, c);
            if (next.empty()) {
                sol[i.second] = -1;
            } else {
                sol[i.second] = next.begin()->first;
            }
            if (next.size() > cur.size()) {
                swap(next, cur);
            }
            for (auto j : next) {
                auto it = cur.find(j);
                if (it == cur.end()) {
                    cur.insert(j);
                } else {
                    cur.erase(j);
                }
            }
        }
    }
    return cur;
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        endp[a].push_back(i);
        endp[b].push_back(i);
        w[i] = c;
    }
    dfs(0, -1);
    for (int i = 0; i < n - 1; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
