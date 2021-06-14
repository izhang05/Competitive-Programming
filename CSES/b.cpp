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
pair<int, int> down[maxn];
int up[maxn];
bool affected[maxn];

void dfs(int c, int p) {
    if (affected[c]) {
        down[c].first = 0;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            int cur = down[i].first;
            if (cur != -1) {
                ++cur;
                if (cur > down[c].first) {
                    swap(down[c].first, down[c].second);
                    down[c].first = cur;
                } else if (cur > down[c].second) {
                    down[c].second = cur;
                }
            }
        }
    }
}
void dfs2(int c, int p) {
    if (p != -1) {
        if (up[p] != -1) {
            up[c] = max(up[c], up[p] + 1);
        }
        int cur;
        if (down[c].first == -1 || down[c].first + 1 != down[p].first) {
            cur = down[p].first;
        } else {
            cur = down[p].second;
        }
        if (cur != -1) {
            up[c] = max(up[c], cur + 1);
        }
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }
}
int main() {
    setIO("b");
    memset(up, -1, sizeof(up));
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < n; ++i) {
        down[i] = {-1, -1};
    }
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        affected[a - 1] = true;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        if (max(down[i].first, up[i]) <= d) {
            ++sol;
#ifdef DEBUG
            cout << i << "\n";
#endif
        }
    }
    cout << sol << "\n";
    return 0;
}
