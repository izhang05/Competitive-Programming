#include <bits/stdc++.h>

using namespace std;

const int mxn = 505;
vector<pair<int, int>> adj[mxn];
bool vis[mxn], has[mxn];

void dfs1(int c) {
    vis[c] = true;
    for (auto &i: adj[c]) {
        if (i.second == 0 && !vis[i.first]) {
            dfs1(i.first);
        }
    }
}

void dfs2(int c) {
    vis[c] = true;
    for (auto &i: adj[c]) {
        if (!vis[i.first] || (!has[i.first] && (has[c] + i.second))) {
            has[i.first] = has[c] + i.second;
            dfs2(i.first);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int ind = 0;
    map<string, int> nodes;
    for (int i = 0; i < n; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        if (nodes.find(a) == nodes.end()) {
            nodes[a] = ind++;
        }
        if (nodes.find(c) == nodes.end()) {
            nodes[c] = ind++;
        }
        if (b == "is-a") {
            adj[nodes[a]].emplace_back(nodes[c], 0);
        } else {
            adj[nodes[a]].emplace_back(nodes[c], 1);
        }
    }
//    for (auto &i: nodes) {
//        cout << i.first << " " << i.second << "\n";
//    }

    for (int i = 0; i < m; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        for (auto &j: vis) {
            j = false;
        }
        for (auto &j: has) {
            j = false;
        }

        if (b == "is-a") {
            dfs1(nodes[a]);
            cout << "Query " << i + 1 << ": " << (vis[nodes[c]] ? "true" : "false") << "\n";
        } else {
            dfs2(nodes[a]);
            cout << "Query " << i + 1 << ": " << ((vis[nodes[c]] && has[nodes[c]]) ? "true" : "false") << "\n";
        }
    }
}
