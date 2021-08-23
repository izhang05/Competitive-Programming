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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<pair<int, int>> adj[maxn];
pair<int, int> edge[maxn];

int up[maxn][maxs], depth[maxn], n, tin[maxn], tout[maxn], t;
long long dist[maxn], dp[maxn], val[maxn][maxs];
bool shop[maxn];

long long jmp(int x, int d) {
    long long res = INFL;
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            res = min(res, val[x][i]);
            x = up[x][i];
        }
    }
    return res;
}

void dfs(int c = 0, int p = -1, int de = 0, long long di = 0) {
    up[c][0] = p;
    depth[c] = de;
    dist[c] = di;
    tin[c] = t++;
    if (shop[c]) {
        dp[c] = -di;
    }
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c, de + 1, di + i.second);
            if (dp[i.first] != INFL) {
                dp[c] = min(dp[c], dp[i.first] + 2 * i.second);
            }
        }
    }
    tout[c] = t;
    val[c][0] = dp[c];
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                val[j][i] = min(val[j][i - 1], val[up[j][i - 1]][i - 1]);
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}


int main() {
    setIO("2");
    memset(dp, 0x3f, sizeof(dp));
    memset(dist, 0x3f, sizeof(dist));
    int s, q, e;
    cin >> n >> s >> q >> e;
    --e;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        edge[i] = {a, b};
    }
    for (int i = 0; i < s; ++i) {
        int c;
        cin >> c;
        --c;
        shop[c] = true;
    }
    memset(val, 0x3f, sizeof(val));
    dfs(e);
    build();
    while (q--) {
        int road, u;
        cin >> road >> u;
        --road, --u;
        int l = (depth[edge[road].first] > depth[edge[road].second] ? edge[road].first : edge[road].second);
        if (!(tin[u] >= tin[l] && tout[u] <= tout[l])) { // u is not in subtree of l
            cout << "escaped" << "\n";
            continue;
        }
        long long sol = jmp(u, depth[u] - depth[l] + 1);
        if (sol == INFL) {
            cout << "oo" << "\n";
        } else {
            cout << sol + dist[u] << "\n";
        }
    }
    return 0;
}
