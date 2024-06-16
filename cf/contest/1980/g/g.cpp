/* Author: izhang
 * Time: 06-03-2024 10:35:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[mxn];
int d[mxn], depth[mxn];

void dfs(int c, int p) {
    for (auto &i : adj[c]) {
        if (i.first != p) {
            depth[i.first] = depth[c] + 1;
            d[i.first] = d[c] ^ i.second;
            dfs(i.first, c);
        }
    }
}

struct trie {
    vector<vector<int>> x;
    int t = 1;
    vector<vector<int>> child;

    void init(int n) {
        child.resize(n);
        x.resize(n);
        for (auto &i : x) {
            i = vector<int>{-1, -1};
        }
    }
    void build(int s) {
        int v = 0;
        for (int i = 29; i >= 0; --i) {
            int cur_b = bool((1 << i) & s);
            if (x[v][cur_b] == -1) {
                child[v].push_back(t);
                v = x[v][cur_b] = t++;
            } else {
                v = x[v][cur_b];
            }
        }
    }
    int query(int s) {
        int res = 0;
        int v = 0;
        for (int i = 29; i >= 0; --i) {
            int cur_b = !bool((1 << i) & s);
            if (x[v][cur_b] == -1) {
                v = x[v][!cur_b];
            } else {
                    res += (1 << i);
//                if (cur_b) {
//                }
                v = x[v][cur_b];
            }
        }
        return res^s;
    }
};

void test_case() {
    int n, m;
    cin >> n >> m;
    trie even, odd;
    even.init(32 * n), odd.init(32 * n);
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    d[0] = depth[0] = 0;
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        if (depth[i] % 2 == 0) {
            even.build(d[i]);
        } else {
            odd.build(d[i]);
        }
    }
    int tot_w = 0;
    while (m--) {
        char c;
        cin >> c;
        if (c == '^') {
            int w;
            cin >> w;
            tot_w ^= w;
        } else {
            int v, w;
            cin >> v >> w;
            --v;
            int val = d[v];
            if (depth[v] % 2 == 1) {
                val ^= tot_w;
            }
            int res = even.query(val ^ w) ^ val ^ w;
            dbg() << imie(val ^ w) << " " << even.query(val ^ w);
            dbg() << res;
            int cur_odd = odd.query(val ^ w ^ tot_w) ^ val ^ w ^ tot_w;
            dbg() << cur_odd;
            cout << max(res, cur_odd) << " ";
            //            int cur = tot_w ^ w;
            //            cout << (query(d[v] ^ tot_w ^ w) ^) << " ";
        }
    }
    cout << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
        dbg();
    }
    return 0;
}
