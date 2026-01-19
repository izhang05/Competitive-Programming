/* Author: izhang
 * Time: 10-19-2025 11:59:07
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[mxn];
int pre[mxn];
bool vis[mxn], cyc;

void dfs(int c, int p) {
    vis[c] = true;
    for (auto &i: adj[c]) {
        if (!vis[i]) {
            pre[i] = c;
            dfs(i, c);
        } else {
            if (i != p) {
                cyc = true;
            }
        }
    }
}

int test_case_number = 0;
int n, m;

bool has_cycles() {
    cyc = false;
    for (int i = 0; i < n; ++i) {
        vis[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }
    return cyc;
}

void test_case() {
    ++test_case_number;
    cin >> n;
    if (n == 0) {
        exit(0);
    }
    cin >> m;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (has_cycles()) {
        cout << "Graph " << test_case_number << " is not a caterpillar." << "\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                pre[k] = -1;
                vis[k] = false;
            }
            dfs(i, -1);
            set<int> good;
            int cur = j;
            while (pre[cur] != -1) {
                good.insert(cur);
                for (auto &k: adj[cur]) {
                    good.insert(k);
                }
                cur = pre[cur];
            }
            good.insert(cur);
            for (auto &k: adj[cur]) {
                good.insert(k);
            }
            if ((int) good.size() == n) {
                cout << "Graph " << test_case_number << " is a caterpillar." << "\n";
                return;
            }
        }
    }
    cout << "Graph " << test_case_number << " is not a caterpillar." << "\n";
}

int main() {
    setIO("1");

    while (true) {
        test_case();
    }
    return 0;
}
