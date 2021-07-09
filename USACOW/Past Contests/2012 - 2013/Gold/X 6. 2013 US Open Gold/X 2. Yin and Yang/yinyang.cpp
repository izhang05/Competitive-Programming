/*
ID: izhang01
TASK: yinyang
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("yinyang.in", "r", stdin);
    freopen("yinyang.out", "w", stdout);
    freopen("yinyang.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e5 + 5;
vector<pair<int, int>> adj[maxn];
bool visited[maxn];
long long sol = 0;
int sub[maxn];

int find_size(int c, int p) {
    sub[c] = 1;
    for (auto &i : adj[c]) {
        if (i.first != p && !visited[i.first]) {
            sub[c] += find_size(i.first, c);
        }
    }
    return sub[c];
}

int centroid(int c, int p, int s) {
    for (auto &i : adj[c]) {
        if (i.first != p && !visited[i.first] && sub[i.first] > s / 2) {
            return centroid(i.first, c, s);
        }
    }
    return c;
}

map<int, pair<int, int>> occ; // first = with intermediate node, second = no intermediate node
multiset<int> cur;

void dfs(int c, int p, bool add, int w) {
    if (add) {
        if (occ.find(-w) != occ.end()) {
            if (cur.find(w) != cur.end()) {
#ifdef DEBUG
                cout << c << " " << w << " " << occ[-w].first << " " << occ[-w].second << "\n";
#endif
                sol += occ[-w].first + occ[-w].second;
            } else {
#ifdef DEBUG
                cout << c << " " << w << " " << occ[-w].first << "\n";
#endif
                sol += occ[-w].first;
            }
        }
    } else {
        if (cur.find(w) != cur.end()) {
#ifdef DEBUG
            cout << c << " " << w << " "
                 << "intermediate"
                 << "\n";
#endif
            ++occ[w].first;
        } else {
#ifdef DEBUG
            cout << c << " " << w << " "
                 << "not intermediate"
                 << "\n";
#endif
            ++occ[w].second;
        }
    }
    cur.insert(w);
    for (auto &i : adj[c]) {
        if (i.first != p && !visited[i.first]) {
            dfs(i.first, c, add, w + i.second);
        }
    }
    cur.erase(cur.find(w));
}

void solve(int v) {
    find_size(v, -1);
    int c = centroid(v, -1, sub[v]);
#ifdef DEBUG
    cout << "v: " << v << "\n";
    cout << "c: " << c << "\n";
#endif
    visited[c] = true;
    occ.clear();
    occ[0].second = 1;
    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            cur.clear();
            dfs(i.first, c, true, i.second);
            cur.clear();
            cur.insert(0);
            dfs(i.first, c, false, i.second);
        }
    }
    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            solve(i.first);
        }
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        if (c == 0) {
            c = -1;
        }
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    solve(0);
    cout << sol << "\n";
    return 0;
}
