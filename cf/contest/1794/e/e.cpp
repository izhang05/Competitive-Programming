/* Author: izhang
 * Time: 03-04-2023 12:35:03
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
std::ostream &
operator<<(std::ostream &dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
const int inf = 0x3f3f3f3f, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int a[maxn];
vector<int> adj[maxn];
__int128 pr = 5669, down[maxn], up[maxn], pr_pow[maxn], mod = 265252859812191058636308479999999; // 10888869450418352160768000001
set<__int128> powers;

void dfs1(int c, int p) {
    down[c] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            down[c] += down[i] * pr;
            down[c] %= mod;
        }
    }
}

void dfs2(int c, int p) {
    if (p != -1) {
        __int128 val = (down[p] + up[p]) % mod;
        val -= (down[c] * pr) % mod;
        val = (val + mod) % mod;
        up[c] = (val * pr) % mod;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }
}

void test_case() {
    __int128 cur = 1;
    for (int i = 0; i < maxn; ++i) {
        powers.insert(cur);
        pr_pow[i] = cur;
        cur *= pr;
        cur %= mod;
    }
    int n;
    cin >> n;
    __int128 hash = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
        hash += pr_pow[a[i]];
        hash %= mod;
    }

    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    up[0] = 0;
    dfs1(0, -1);
    dfs2(0, -1);
    vector<int> sol;
    for (int i = 0; i < n; ++i) {
        __int128 val = (down[i] + up[i]) % mod;
        val -= hash;
        val = (val + mod) % mod;
        dbg() << i << " " << down[i] << " " << up[i] << " " << val;
        if (powers.find(val) != powers.end()) {
            sol.push_back(i);
        }
    }
    cout << sol.size() << "\n";
    for (int i = 0; i < int(sol.size()); ++i) {
        cout << sol[i] + 1 << " \n"[i == int(sol.size()) - 1];
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
