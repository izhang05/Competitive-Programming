/* Author: izhang05
 * Time: 12-24-2021 09:35:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
int depth[maxn], par[maxn];
bool vis[maxn];

void dfs(int c, int p, int d) {
    par[c] = p;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

void test_case() {
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 0);
    vector<pair<int, int>> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = {depth[i], i};
    }
    sort(nodes.begin(), nodes.end());
    reverse(nodes.begin(), nodes.end());
    vector<int> v(n);
    for (auto &i : nodes) {
        int cur = i.second;
        int val = 0;
        while (cur != -1 && !vis[cur]) {
            vis[cur] = true;
            ++val;
            cur = par[cur];
        }
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    long long sol = -n * (n / 2);

    long long block = 0;
    for (int r = 1; r <= k; ++r) {
        block += v.back();
        v.pop_back();
        long long b = min(n / 2, n - block);
        long long cur = r * (n - r) - b * (n - b);
        sol = max(sol, cur);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
