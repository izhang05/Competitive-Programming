/* Author: izhang05
 * Time: 07-08-2021 20:47:12
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, maxn = 1e5 + 5;
vector<pair<int, int>> adj[maxn];

long long m, sol, inv;
int sub[maxn];
bool visited[maxn];

long long modInverse(long long a, long long mod) {
    long long m0 = mod;
    long long y = 0, x = 1;

    if (mod == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        long long q = a / mod;
        long long t = mod;

        // mod is remainder now, process same as
        // Euclid's algo
        mod = a % mod, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

long long binpow(long long x, long long n) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

int find_size(int v, int p) {
    sub[v] = 1;
    for (auto &i : adj[v]) {
        if (i.first != p && !visited[i.first]) {
            sub[v] += find_size(i.first, v);
        }
    }
    return sub[v];
}

int centroid(int v, int p, int s) {
    for (auto &i : adj[v]) {
        if (i.first != p && !visited[i.first] && sub[i.first] > s / 2) {
            return centroid(i.first, v, s);
        }
    }
    return v;
}

map<long long, int> occ;

void dfs1(int c, int p, long long val, int d, bool add) {
    if (add) {
#ifdef DEBUG
        cout << c << " " << val << "\n";
#endif
        ++occ[val];
        if (val == 0) {
            ++sol;
        }
    } else {
        --occ[val];
        if (val == 0) {
            --sol;
        }
    }
    for (auto &i : adj[c]) {
        if (i.first != p && !visited[i.first]) {
            dfs1(i.first, c, (val + binpow(10, d) * i.second) % m, d + 1, add);
        }
    }
}

void dfs2(int c, int p, long long val, int d) {
    long long goal = ((-val * binpow(inv, d)) % m + m) % m;
#ifdef DEBUG
    cout << c << " " << val << " " << goal << " " << occ[goal] << "\n";
#endif
    sol += occ[goal];
    for (auto &i : adj[c]) {
        if (i.first != p && !visited[i.first]) {
            dfs2(i.first, c, (10 * val + i.second) % m, d + 1);
        }
    }
}

void solve(int v) {
    find_size(v, -1);
    int c = centroid(v, -1, sub[v]);
#ifdef DEBUG
    cout << "c: " << c << "\n";
    cout << "v: " << v << "\n";
#endif
    visited[c] = true;

    occ.clear();
    occ[0] = 1;
    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            dfs1(i.first, c, i.second % m, 1, true);
        }
    }
    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            dfs1(i.first, c, i.second % m, 1, false);
            dfs2(i.first, c, i.second % m, 1);
            dfs1(i.first, c, i.second % m, 1, true);
        }
    }
    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            solve(i.first);
        }
    }
}

int main() {
    setIO("1");

    int n;
    cin >> n >> m;
    inv = modInverse(10, m);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    solve(0);
    cout << sol << "\n";
    return 0;
}
