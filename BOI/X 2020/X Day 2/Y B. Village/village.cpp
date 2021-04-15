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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn], order;
int n, pos[maxn];
long long sol;

void solve_min(int c, int p) {
    for (auto i : adj[c]) {
        if (i != p) {
            solve_min(i, c);
        }
    }
    if (pos[c] == c) {
        sol += 2;
        if (c != 0) {
            swap(pos[c], pos[p]);
        } else {
            swap(pos[c], pos[adj[c][0]]);
        }
    }
}

int sub[maxn], dist[maxn];

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
    setIO("2");
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        pos[i] = i;
    }
    solve_min(0, -1);
    vector<int> minp(n);
    cout << sol << " ";
    for (int i = 0; i < n; ++i) {
        minp[i] = pos[i];
        pos[i] = i;
    }

    sol = 0;
    dfs(0, -1);
    solve(centroid(0, -1), -1, 0);
    cout << 2 * sol << "\n";
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[order[i]] = order[(i + (n + 1) / 2) % n] + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << minp[i] + 1 << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << "\n";
    return 0;
}
