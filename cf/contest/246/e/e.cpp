/* Author: izhang05
 * Time: 07-07-2021 15:33:49
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> child[maxn];
int name[maxn], sol[maxn], sz[maxn];
vector<pair<int, int>> q[maxn];
unordered_map<int, set<int>> nodes[maxn];
bool visited[maxn];

void dfs(int c, int d) {
    visited[c] = true;
    nodes[c][d].insert(name[c]);
    sz[c] = 1;
    for (auto &i : child[c]) {
        dfs(i, d + 1);
        if (sz[i] > sz[c]) {
            swap(sz[i], sz[c]);
            swap(nodes[i], nodes[c]);
        }
        for (auto &j : nodes[i]) {
            for (auto &k : j.second) {
                if (nodes[c][j.first].find(k) == nodes[c][j.first].end()) {
                    ++sz[c];
                    nodes[c][j.first].insert(k);
                }
            }
        }
        nodes[i].clear();
    }
    for (auto &i : q[c]) {
#ifdef DEBUG
        cout << c << " " << i.first << ":";
        for (auto &j : nodes[c][i.first]) {
            cout << " " << j;
        }
        cout << "\n";
#endif
        if (nodes[c].find(d + i.first) != nodes[c].end()) {
            sol[i.second] = (int) nodes[c][d + i.first].size();
        }
    }
}

int main() {
    setIO("2");

    int n;
    cin >> n;
    unordered_map<string, int> names;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        int p;
        cin >> s >> p;
        --p;
        if (names.find(s) == names.end()) {
            names[s] = ind++;
        }
        name[i] = names[s];
        if (p >= 0) {
            child[p].push_back(i);
        }
#ifdef DEBUG
        cout << name[i] << "\n";
#endif
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int v, k;
        cin >> v >> k;
        --v;
        q[v].emplace_back(k, i);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
