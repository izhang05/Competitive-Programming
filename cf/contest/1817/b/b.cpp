/* Author: izhang
 * Time: 05-02-2023 13:51:13
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];
int deg[mxn];
bool vis[mxn], nxt[mxn], found = false;
vector<int> sol;

void dfs(int c, int p) {
    sol.push_back(c);
    vis[c] = true;
    for (auto &i : adj[c]) {
        if (found) {
            break;
        }
        if (i != p) {
            if (nxt[i]) {
                dbg() << sol;
                cout << "YES"
                     << "\n";
                sol.push_back(i);
                sol.push_back(sol[0]);
                cout << sol.size() + 1 << "\n";
                for (int j = 0; j < int(sol.size()) - 1; ++j) {
                    cout << sol[j] + 1 << " " << sol[j + 1] + 1 << "\n";
                }
                int cnt = 0;
                for (auto &j : adj[sol[0]]) {
                    if (j != sol[1] && j != i) {
                        cout << sol[0] + 1 << " " << j + 1 << "\n";
                        ++cnt;
                        if (cnt >= 2) {
                            break;
                        }
                    }
                }
                found = true;
            }
            if (!vis[i]) {
                dfs(i, c);
            }
        }
    }
    sol.pop_back();
}

void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        deg[i] = 0;
        vis[i] = false;
    }
    found = false;
    for (int i = 0; i < m; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
        ++deg[node1], ++deg[node2];
    }
    for (int i = 0; i < n; ++i) {
        if (deg[i] < 4) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            nxt[j] = false;
        }
        for (auto &j : adj[i]) {
            nxt[j] = true;
        }
        for (auto &j : adj[i]) {
            memset(vis, false, sizeof(vis));
            vis[i] = true;
            sol = vector<int>{i};
            nxt[j] = false;
            dfs(j, i);
            if (found) {
                return;
            }
            nxt[j] = true;
        }
    }
    cout << "NO"
         << "\n";
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
