/* Author: izhang05
 * Time: 10-23-2021 12:45:02
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
int deg[maxn], in_deg[maxn], out_deg[maxn];
bool used[maxn], sol[maxn];

vector<int> adj2[maxn];

void dfs(int c, int p) {
    sol[c] = true;
    for (auto &i : adj[c]) {
        if (i != p && !out_deg[i]) {
            dfs(i, c);
        }
    }
}

int main() {
    // must always take a leaf of remaining tree
    setIO("gathering");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++deg[a], ++deg[b];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ++out_deg[a], ++in_deg[b];
        adj2[a].push_back(b);
    }
    set<int> rem;
    queue<int> avail;
    for (int i = 0; i < n; ++i) {
        if (deg[i] <= 1 && !in_deg[i]) {
            avail.push(i);
            used[i] = true;
        }
        rem.insert(i);
    }
    while (!avail.empty() && rem.size() > 1) {
        int cur = avail.front();
        avail.pop();
        rem.erase(cur);
        for (auto &i : adj2[cur]) {
            --in_deg[i];
            if (deg[i] <= 1 && in_deg[i] == 0 && !used[i]) {
                avail.push(i);
                used[i] = true;
            }
        }
        for (auto &i : adj[cur]) {
            if (--deg[i] <= 1 && in_deg[i] == 0 && !used[i]) {
                avail.push(i);
                used[i] = true;
            }
        }
    }
    if (rem.size() > 1) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << "\n";
        }
        return 0;
    }
    dfs(*rem.begin(), -1);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
