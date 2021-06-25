/* Author: izhang05
 * Time: 06-25-2021 11:35:03
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
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;

long long binpow(long long x, long long n, long long m) {
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

long long mult(long long a, long long b) {
    return (a * b) % mod;
}
long long di(long long a, long long b) {
    return mult(a, binpow(b, mod - 2, mod));
}

long long add(long long a, long long b) {
    return (a + b) % mod;
}
long long sub(long long a, long long b) {
    return ((a - b) % mod + mod) % mod;
}
const int maxn = 205, maxs = 10;
vector<int> adj[maxn];
long long fact[maxn];

long long nCr(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
    return di(fact[a], mult(fact[b], fact[a - b]));
}

int cnt(int c, int p, int val) {
    int res = 0;
    if (c < val) {
        ++res;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            res += cnt(i, c, val);
        }
    }
    return res;
}
int up[maxn][maxs], depth[maxn], n;

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    x = jmp(x, depth[x] - depth[y]);
    if (x == y) {
        return x;
    }
    for (int i = maxs - 1; i >= 0; --i) {
        int new_x = up[x][i], new_y = up[y][i];
        if (new_x != new_y) {
            x = new_x, y = new_y;
        }
    }
    return up[x][0];
}

int dist(int x, int y) {
    int l = lca(x, y);
    return depth[x] - depth[l] + depth[y] - depth[l];
}

void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}
long long mem[maxn][maxn];

long long prob(long long a, long long b) {
    if (mem[a][b] != -1) {
        return mem[a][b];
    }
    long long p = binpow(di(1, 2), a + b - 1, mod);
    long long s = 0;
    for (long long i = a; i <= a + b - 1; ++i) {
        s = add(s, nCr(a + b - 1, i));
    }
    return mem[a][b] = mult(p, s);
}

int main() {
    setIO("1");
    memset(mem, -1, sizeof(mem));
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fact[i] = mult(fact[i - 1], i);
    }
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        dfs(i, -1);
        build();
        long long cur = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int l = lca(j, k);
                int dist_j = dist(j, l), dist_k = dist(k, l);
#ifdef DEBUG
                cout << dist_k << " " << dist_j << " " << prob(dist_k, dist_j) << "\n";
#endif
                cur = add(cur, prob(dist_k, dist_j));
            }
        }
        sol = add(sol, di(cur, n));
#ifdef DEBUG
        cout << "sol: " << i << " " << cur << " " << sol << "\n";
#endif
    }
    cout << sol << "\n";
    return 0;
}
