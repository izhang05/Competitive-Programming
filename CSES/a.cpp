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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn];
int sub[maxn], n, val[maxn];
bool visited[maxn];
long long sol = 0;
pair<long long, long long> odd, even;

int find_centroid(int c, int p, int s) {
    for (auto i : adj[c]) {
        if (!visited[i] && sub[i] > s / 2 && i != p) {
            return find_centroid(i, c, s);
        }
    }
    return c;
}

int find_size(int v, int p = -1) {
    sub[v] = 1;

    for (int i : adj[v]) {
        if (i != p && !visited[i]) {
            sub[v] += find_size(i, v);
        }
    }

    return sub[v];
}

void dfs(int c, int p, int d, int v, bool adding) {
    v *= -1;
    v += val[c];
    v %= mod;
    if (adding) {
        if (d % 2 == 0) {
            sol += even.first + even.second * v;
        } else {
            sol += odd.first + odd.second * v;
        }
#ifdef DEBUG
        cout << c << " " << sol << "\n";
#endif
        sol %= mod;
    } else {
        if (d % 2 == 0) {
            even.first += v;
            even.first %= mod;
            ++even.second;
        } else {
            odd.first += v;
            odd.first %= mod;
            ++odd.second;
        }
    }

    for (auto i : adj[c]) {
        if (i != p && !visited[i]) {
            dfs(i, c, d + 1, v, adding);
        }
    }
}
void solve(int v = 0) {
    find_size(v);
    int c = find_centroid(v, -1, sub[v]);
#ifdef DEBUG
    cout << "centroid: " << c << "\n";
#endif
    visited[c] = true;
    odd = {0, 0};
    even = {val[c], 1};
    for (auto i : adj[c]) {
        if (!visited[i]) {
            dfs(i, c, 1, 0, true);
            dfs(i, c, 1, val[c], false);
        }
    }

    for (int x : adj[c]) {
        if (!visited[x]) {
            solve(x);
        }
    }
}

signed main() {
    setIO("1");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve();
    sol *= 2;
    sol %= mod;
    for (int i = 0; i < n; ++i) {
        sol += val[i];
    }
    sol %= mod;
    while (sol < 0) {
        sol += mod;
    }
    cout << sol << "\n";
    //    cout << (val[0] - val[3] + val[6] + val[0] - val[3] + val[6] - val[5] + val[4] + val[0] - val[3] + val[6] - val[5] + val[4] - val[7] + val[1]) << "\n";
    return 0;
}
