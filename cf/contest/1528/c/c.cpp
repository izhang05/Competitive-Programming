/* Author: izhang05
 * Time: 10-06-2021 17:56:43
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj_a[maxn], adj_b[maxn];
int st[maxn], en[maxn], t, sol;

void dfs0(int c, int p) {
    st[c] = t++;
    for (auto &i : adj_b[c]) {
        if (i != p) {
            dfs0(i, c);
        }
    }
    en[c] = t++;
}

set<pair<int, int>> nodes;
void dfs1(int c, int p) {
    auto it = nodes.upper_bound({st[c], inf});
    pair<int, int> removed{-1, -1}, added{-1, -1};
    if (it == nodes.end() || st[it->second] > en[c]) {
        // no current nodes in subtree of c
        if (it != nodes.begin() && en[prev(it)->second] > en[c]) {
            // there is an ancestor of c
            removed = *prev(it);
            nodes.erase(prev(it));
        }
        nodes.insert({st[c], c});
        added = {st[c], c};
    }
    sol = max(sol, (int) nodes.size());
    for (auto &i : adj_a[c]) {
        if (i != p) {
            dfs1(i, c);
        }
    }
    if (removed.first != -1) {
        nodes.insert(removed);
    }
    if (added.first != -1) {
        nodes.erase(added);
    }
}

void solve() {
    int n;
    cin >> n;
    t = 0, sol = 0;
    for (int i = 0; i < n; ++i) {
        adj_a[i].clear();
        adj_b[i].clear();
        st[i] = 0, en[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        adj_a[a].push_back(i);
        adj_a[i].push_back(a);
    }
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        adj_b[a].push_back(i);
        adj_b[i].push_back(a);
    }
    dfs0(0, -1);
    dfs1(0, -1);
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
