#include <bits/stdc++.h>

using namespace std;

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
struct edge {
    int node, load;
    long long toll;
};
const int maxn = 5e4 + 5;
edge p[maxn];
vector<edge> adj[maxn];

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void dfs(int c, edge par) {
    p[c] = par;
    for (auto i : adj[c]) {
        if (i.node != par.node) {
            dfs(i.node, {c, i.load, i.toll});
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        long long d;
        cin >> a >> b >> c >> d;
        --a, --b;
        adj[a].push_back({b, c, d});
        adj[b].push_back({a, c, d});
    }
    dfs(0, {-1, -1, -1});
    for (int i = 0; i < q; ++i) {
        int a, cur;
        cin >> a >> cur;
        --a;
        long long sol = -1;
        while (a != 0) {
            if (cur >= p[a].load) {
                if (sol == -1) {
                    sol = p[a].toll;
                } else {
                    sol = gcd(sol, p[a].toll);
                }
            }
            a = p[a].node;
        }
        cout << (sol == -1 ? 0 : sol) << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
