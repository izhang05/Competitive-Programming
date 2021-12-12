/* Author: izhang05
 * Time: 12-11-2021 16:44:44
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
const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 150005, k = 320, maxs = 18;

const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[maxn];
int deg[maxn], sz[maxn], st[maxn], en[maxn], ti, n, t2, tin[maxn];
vector<pair<int, int>> tour[maxn];
long long sol[maxn];
int inv;
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

void upd(int ind, long long v) {
    if (v < 0) {
        v += mod;
    }
    for (; ind < n; ind = ind | (ind + 1)) {
        sol[ind] += v;
        if (sol[ind] > mod) {
            sol[ind] -= mod;
        }
    }
}

long long query(int ind) {
    long long res = 0;
    for (; ind >= 0; ind = (ind & (ind + 1)) - 1) {
        res += sol[ind];
        if (res > mod) {
            res -= mod;
        }
    }
    return res;
}

void dfs(int c, int p) {
    st[c] = ti++;
    sz[c] = 1;
    tour[c].emplace_back(t2++, -1);
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            tour[c].back().second = i;
            tour[c].emplace_back(t2++, -1);
            sz[c] += sz[i];
        }
    }
    en[c] = ti;
}
vector<int> heavy;
long long heavy_cnt[maxn];

void test_case() {
    int q;
    cin >> n >> q;
    inv = binpow(n, mod - 2, mod);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++deg[a], ++deg[b];
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        if (deg[i] >= k) {
            heavy.push_back(i);
        }
    }
    while (q--) {
        int t, c;
        cin >> t >> c;
        --c;
        if (t == 1) {
            long long d;
            cin >> d;
            if (deg[c] < k) {
                upd(st[c], d), upd(st[c] + 1, -d);
                for (auto &i : adj[c]) {
                    if (sz[i] < sz[c]) {
                        long long add = d * (n - sz[i]) % mod * inv % mod;
                        upd(st[i], add), upd(en[i], -add);
                    } else {
                        long long add = d * sz[c] % mod * inv % mod;
                        upd(0, add);
                        upd(st[c], -add), upd(en[c], add);
                    }
                }
            } else {
                heavy_cnt[c] += d;
                if (heavy_cnt[c] > mod) {
                    heavy_cnt[c] -= mod;
                }
            }
        } else {
            long long cur = query(st[c]);
            for (auto &i : heavy) {
                if (i == c) {
                    cur += heavy_cnt[i];
                    if (cur > mod) {
                        cur -= mod;
                    }
                    continue;
                }
                auto it = lower_bound(tour[i].begin(), tour[i].end(), tour[c][0]);
                int cur_sz;
                if (it == tour[i].begin() || it == tour[i].end()) {
                    // c not in subtree of i
                    cur_sz = sz[i];
                } else {
                    cur_sz = n - sz[prev(it)->second];
                }
                cur += heavy_cnt[i] * cur_sz % mod * inv % mod;
                if (cur > mod) {
                    cur -= mod;
                }
            }
            cout << cur << "\n";
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
