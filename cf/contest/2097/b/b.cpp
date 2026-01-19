/* Author: izhang
 * Time: 05-19-2025 22:48:01
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool used[mxn], vis[mxn];
set<int> adj[mxn];
int n, m, k;

int ind(pair<int, int> cur) {
    return cur.first * m + cur.second;
}

pair<int, int> get_edge(pair<int, int> a, pair<int, int> b) {
    if (a > b) {
        swap(a, b);
    }
    return {ind({a.first, b.second}), ind({b.first, a.second})};
}

bool bad;

void dfs1(int cur, int par) {
    vis[cur] = true;
    used[cur] = true;
    for (int i: adj[cur]) {
        if (used[i] && i != par) {
            bad = true;
        }
        if (!vis[i]) {
            dfs1(i, cur);
        }
    }
}

bool cycle;
int tot = 0, cyc_a, cyc_b, edges;

void dfs2(int cur, int par) {
    ++tot;
    vis[cur] = true;
    for (int i: adj[cur]) {
        if (vis[i] && i != par) {
            cyc_a = cur;
            cyc_b = i;
            cycle = true;
        }
        if (!vis[i]) {
            ++edges;
            dfs2(i, cur);
        }
    }
}

void dfs3(int cur, int par) {
//    cout << cur << " " << par << " " << bad << "\n";
    used[cur] = true;
    for (int i: adj[cur]) {
//        cout << i << " " << par << "\n";
        if (used[i] && i != par) {
            bad = true;
        }
        if (!used[i]) {
            dfs3(i, cur);
        }
    }
}

void test_case() {
    cin >> n >> m >> k;
    for (int i = 0; i < n * m; ++i) {
        used[i] = vis[i] = false;
        adj[i].clear();
    }
    pair<int, int> pre;
    cin >> pre.first >> pre.second;
    --pre.first, --pre.second;
    bad = false;
    for (int i = 0; i < k; ++i) {
        pair<int, int> cur;
        cin >> cur.first >> cur.second;
        --cur.first, --cur.second;
        if (abs(cur.first - pre.first) + abs(cur.second - pre.second) != 2) {
            bad = true;
            continue;
        }
        if (cur.first == pre.first) {
            used[ind({cur.first, (cur.second + pre.second) / 2})] = true;
        } else if (cur.second == pre.second) {
            used[ind({(cur.first + pre.first) / 2, cur.second})] = true;
        } else {
            pair<int, int> e = get_edge(cur, pre);
//            cout << e.first << " " << e.second << "\n";
            adj[e.first].insert(e.second);
            adj[e.second].insert(e.first);
        }
        swap(pre, cur);
    }
    if (bad) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 0; i < n * m; ++i) {
        if (!vis[i] && used[i]) {
            dfs1(i, -1);
        }
    }
    if (bad) {
        cout << 0 << "\n";
        return;
    }
    long long sol = 1;
    for (int i = 0; i < n * m; ++i) {
        if (vis[i]) {
            continue;
        }
        tot = 0;
        edges = 0;
        cycle = false;
        dfs2(i, -1);
        if (cycle) {
//            adj[cyc_a].erase(cyc_b);
//            adj[cyc_b].erase(cyc_a);
//            dfs3(cyc_a, -1);
            if (edges > tot) {
                cout << 0 << "\n";
                return;
            }
            sol *= 2;
            sol %= mod;
        } else {
            sol *= tot;
            sol %= mod;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
