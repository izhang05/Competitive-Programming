#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL
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


const int maxn = 2e5 + 5;
unordered_set<int> adj[maxn];

int main() {
    setIO("1");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (auto &j : adj[i]) {
            if (adj[i].size() < adj[j].size()) {
                for (auto &k : adj[i]) {
                    if (j != k && adj[j].find(k) == adj[j].end()) {
                        adj[j].insert(k);
                        ++sol;
                    }
                }
            } else {
                for (auto &k : adj[j]) {
                    if (j != k && adj[i].find(k) == adj[i].end()) {
                        adj[j].insert(k);
                        ++sol;
                    }
                }
            }
        }
        for (auto &j : adj[i]) {
            adj[j].erase(i);
        }
    }
    cout << sol / 2 << "\n";
    return 0;
}
