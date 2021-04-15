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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn], order;
int sub[maxn], n, dist[maxn];
long long sol = 0;

void dfs(int c, int p) {
    sub[c] = 1;
    for (auto i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            sub[c] += sub[i];
        }
    }
}

int centroid(int c, int p) {
    for (auto i : adj[c]) {
        if (i != p && sub[i] > n / 2) {
            return centroid(i, c);
        }
    }
    return c;
}

void solve(int c, int p, int d) {
    sol += d;
    order.push_back(c);
    for (auto i : adj[c]) {
        if (i != p) {
            solve(i, c, d + 1);
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
    solve(centroid(0, -1), -1, 0);
    cout << 2 * sol << "\n";
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[order[i]] = order[(i + (n + 1) / 2) % n] + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << pos[i] << " ";
    }
    cout << "\n";
    return 0;
}
