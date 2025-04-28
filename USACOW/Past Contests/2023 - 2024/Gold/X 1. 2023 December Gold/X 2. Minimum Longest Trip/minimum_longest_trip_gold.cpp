#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
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
vector<pair<int, int>> adj[mxn];
int indeg[mxn];


int main() {
    setIO("1");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        --a, --b;
        adj[a].emplace_back(b, l);
        ++indeg[b];
    }
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!indeg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for (auto &i : adj[cur]) {
            if (--indeg[i.first] == 0) {
                q.push(i.first);
            }
        }
    }
    vector<pair<int, int>> sol(n);
    reverse(topo.begin(), topo.end());
    for (auto &i : topo) {
        int mx_len = 0, sum = 0, l = 1e9;
        for (auto &j : adj[i]) {
            if (sol[j.first].first + 1 >= mx_len && j.second < l) {
                mx_len = sol[j.first].first + 1;
                sum = sol[j.first].second + j.second;
                l = j.second;
            }
        }
        sol[i] = {mx_len, sum};
    }

    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}
