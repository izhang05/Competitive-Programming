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

const int maxn = 1e5 + 5;

// adj_t is the transpose of adj
vector<int> adj[maxn], adj_t[maxn], S;
bool vis[maxn];
int id[maxn];

void dfs(int c, int pass, int num = 0) {
    vis[c] = true;
    vector<int> &ad = (pass == 1) ? adj[c] : adj_t[c];
    for (const int &e : ad) {
        if (!vis[e]) {
            dfs(e, pass, num);
        }
    }

    S.push_back(c);
    if (pass == 2) {
        id[c] = num;
    }
}

int main() {
    setIO("25");

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_t[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 1);
        }
    }

    memset(vis, false, sizeof vis);
    int components = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!vis[S[i]]) {
            components++;
            dfs(S[i], 2, components);
        }
    }
    cout << components << "\n";
    for (int i = 1; i <= n; i++) {
        cout << id[i] << " ";
    }
    return 0;
}
