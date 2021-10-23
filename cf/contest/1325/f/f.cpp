/* Author: izhang05
 * Time: 10-07-2021 13:35:11
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
bool visited[maxn];
int depth[maxn], k, par[maxn];
vector<vector<int>> nodes;

void dfs(int c, int p, int d) {
    par[c] = p;
    visited[c] = true;
    depth[c] = d;
    nodes[d % k].push_back(c);
    for (auto &i : adj[c]) {
        if (i != p) {
            if (!visited[i]) {
                dfs(i, c, d + 1);
            } else {
                int len = abs(depth[c] - depth[i]) + 1;
                if (len >= k + 1) {
                    cout << 2 << "\n";
                    cout << len << "\n";
                    if (depth[c] < depth[i]) {
                        swap(c, i);
                    }
                    int cur = c;
                    while (cur != i) {
                        cout << cur + 1 << " ";
                        cur = par[cur];
                    }
                    cout << i + 1 << "\n";
                    exit(0);
                }
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    k = ceil(sqrt(n)) - 1;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    nodes.resize(k);
    dfs(0, -1, 0);
    cout << 1 << "\n";
    for (auto &i : nodes) {
        if ((int) i.size() > k) {
            for (int j = 0; j < k + 1; ++j) {
                cout << i[j] + 1 << " \n"[j == k];
            }
            return;
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
