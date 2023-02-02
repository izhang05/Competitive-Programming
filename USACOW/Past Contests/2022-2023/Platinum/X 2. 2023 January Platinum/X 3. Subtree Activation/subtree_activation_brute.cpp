#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || DEBUG
#include <debug.h>
#endif

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
const int mxn = 2e5 + 5;
vector<int> adj[mxn];
int par[mxn];
const long long INFL = 4e18;
bool marked[mxn];

int dfs0(int c, int p, int r) {
    int res = marked[c];
    marked[c] = false;
    for (auto &i : adj[c]) {
        if (i != p && i != r) {
            res += dfs0(i, c, r);
        }
    }
    return res;
}

int dfs1(int c, int p) {
    int res = !marked[c];
    marked[c] = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            res += dfs1(i, c);
        }
    }
    return res;
}


int main() {
    setIO("1");
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        par[i] = p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    par[0] = -1;
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }
    pair<long long, vector<int>> sol = {INFL, vector<int>()};
    do {
        memset(marked, false, sizeof(marked));
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            if (order[i] != 0) {
                cur += dfs0(0, -1, order[i]);
            }
            cur += dfs1(order[i], par[order[i]]);
        }
        cur += dfs0(0, -1, 0);
        sol = min(sol, {cur, order});
    } while (next_permutation(order.begin(), order.end()));
    cout << sol.first << "\n";
    dbg() << sol.second;
    return 0;
}
