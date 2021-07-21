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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn];
int a[maxn];

bool dfs(int c, int p, set<int> seen) {
    if (seen.find(a[c]) != seen.end()) {
        return false;
    }
    seen.insert(a[c]);
    for (auto &i : adj[c]) {
        if (i != p) {
            if (!dfs(i, c, seen)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    setIO("1");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        if (dfs(i, -1, set<int>{})) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
