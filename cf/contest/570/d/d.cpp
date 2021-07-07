/* Author: izhang05
 * Time: 07-07-2021 16:08:07
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5;
vector<int> child[maxn];
string s;
vector<pair<int, int>> q[maxn];
int sol[maxn], sz[maxn];
unordered_map<int, int> odd_cnt[maxn];
unordered_map<int, map<char, int>> occ[maxn];

void dfs(int c, int d) {
    ++odd_cnt[c][d];
    ++occ[c][d][s[c]];
    ++sz[c];
    for (auto &i : child[c]) {
        dfs(i, d + 1);
        if (sz[i] > sz[c]) {
            swap(sz[i], sz[c]);
            swap(odd_cnt[i], odd_cnt[c]);
            swap(occ[i], occ[c]);
        }
        for (auto &j : occ[i]) {
            for (auto &k : j.second) {
                if (occ[c][j.first].find(k.first) == occ[c][j.first].end()) {
                    ++sz[c];
                }
                occ[c][j.first][k.first] += k.second;
                if (k.second % 2 != 0) {
                    if (occ[c][j.first][k.first] % 2 == 0) {
                        --odd_cnt[c][j.first];
                    } else {
                        ++odd_cnt[c][j.first];
                    }
                }
            }
        }
        odd_cnt[i].clear();
        occ[i].clear();
    }
    for (auto &i : q[c]) {
        sol[i.second] = odd_cnt[c][i.first] <= 1;
    }
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        child[p].push_back(i);
    }
    cin >> s;
    for (int i = 0; i < m; ++i) {
        int v, h;
        cin >> v >> h;
        --v;
        q[v].emplace_back(h, i);
    }
    dfs(0, 1);
    for (int i = 0; i < m; ++i) {
        cout << (sol[i] ? "Yes" : "No") << "\n";
    }
    return 0;
}
