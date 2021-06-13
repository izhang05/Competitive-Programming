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
long long sub[maxn], down[maxn], up[maxn];
int n;
void dfs(int c, int p) {
    sub[c] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            sub[c] += sub[i];
            down[c] += down[i];
        }
    }
    down[c] += sub[c];
}

void dfs2(int c, int p) {
    if (p != -1) {
        up[c] = up[p] + down[p] - down[c] - sub[c] + n - sub[c];
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }
}

int main() {
    setIO("1");

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, down[i] + up[i]);
#ifdef DEBUG
        cout << i << " " << down[i] << " " << up[i] << "\n";
#endif
    }
    cout << sol << "\n";
    return 0;
}
