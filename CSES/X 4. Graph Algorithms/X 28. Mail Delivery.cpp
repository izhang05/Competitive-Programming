#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxm = 2e5 + 5;

int n, m;
bool used[maxn];
vector<pair<int, int>> adj[maxn];
vector<pair<int, int>>::iterator its[maxn];
vector<pair<int, int>> solve(int src = 0) {
    for (int i = 0; i < n; ++i) {
        its[i] = adj[i].begin();
    }
    vector<pair<pair<int, int>, int>> ret, s = {{{src, -1}, -1}};
    // {{vert, prev vert}, edge label}
    while (!s.empty()) {
        int x = s.back().first.first;
        auto &it = its[x], en = adj[x].end();
        while (it != en && used[it->second]) {
            ++it;
        }
        if (it == en) { // no more edges out of vertex
            if (!ret.empty() && ret.back().first.second != x) {
                return {};
            }
            ret.push_back(s.back());
            s.pop_back();
        } else {
            s.push_back({{it->first, x}, it->second});
            used[it->second] = true;
        }
    }
    if (int(ret.size()) != m + 1) {
        return {};
    }
    vector<pair<int, int>> ans;
    for (auto &i : ret) {
        ans.emplace_back(i.first.first, i.second);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    setIO("28");
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    vector<pair<int, int>> sol = solve();
    if (sol.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (auto &i : sol) {
            cout << i.first + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
