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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

vector<int> adj[maxn];
pair<int, int> mx, diam;

void dfs1(int c, int p, int d) {
    mx = max(mx, {d, c});
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c, d + 1);
        }
    }
}

bool sol = false;

void dfs2(int c, int p) {
    if (c == diam.second) {
        sol = true;
        return;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            if (adj[i].size() == 1 && i == diam.second) {
                dfs2(i, c);
            } else if (adj[i].size() >= 3) {
                dfs2(i, c);
            }
        }
    }

}

int main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0, -1, 0);
    diam.first = mx.second;
    mx = {0, 0};
    dfs1(diam.first, -1, 0);
    diam.second = mx.second;
#ifdef DEBUG
    cout << diam.first << " " << diam.second << "\n";
#endif
    dfs2(diam.first, -1);
    cout << (sol ? "YES" : "NO") << "\n";
    return 0;
}
