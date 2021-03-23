#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

#define int long long
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn];
int n, st[maxn], en[maxn], timer = 1, bit[2][maxn], depth[maxn];

void dfs(int c, int p) {
    st[c] = timer++;
    for (auto i : adj[c]) {
        if (i != p) {
            depth[i] = depth[c] + 1;
            dfs(i, c);
        }
    }
    en[c] = timer - 1;
}

void update(int p, int v, int t) {
    for (; p <= n; p += p & (-p)) {
        bit[t][p] += v;
    }
}

long long query(int p, int t) {
    long long res = 0;
    for (; p > 0; p -= p & (-p)) {
        res += bit[t][p];
    }
    return res;
}

signed main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> n >> q;
        for (int i = 1; i < n + 1; ++i) {
            adj[i].clear();
        }
        memset(st, 0, sizeof(st));
        memset(en, 0, sizeof(en));
        timer = 1;
        memset(bit, 0, sizeof(bit));
        memset(depth, 0, sizeof(depth));
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        vector<vector<int>> values(2, vector<int>(n));
        while (q--) {
            int a, b, c;
            cin >> a >> b >> c;
            if (c != 0) {
                update(st[a], c, 0);
                update(st[b], c, 1);

            } else {
                if (depth[a] < depth[b]) {
                    swap(a, b);
                }
                // depth[a] > depth[b]
                cout << abs((query(en[a], 0) - query(st[a] - 1, 0)) - (query(en[a], 1) - query(st[a] - 1, 1))) << "\n";
            }
        }
    }
    return 0;
}
