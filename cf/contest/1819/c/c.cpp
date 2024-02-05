/* Author: izhang
 * Time: 02-04-2024 21:53:19
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
vector<int> adj[mxn];
int deg[mxn], par[mxn], dist[mxn];
pair<int, int> mx_dist;
bool on_d[mxn];

void dfs(int c, int p, int d) {
    dist[c] = d;
    par[c] = p;
    mx_dist = max(mx_dist, {d, c});
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
        ++deg[node1], ++deg[node2];
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (auto &j : adj[i]) {
            cnt += (deg[j] >= 2);
        }
        if (cnt > 2) {
            cout << "No"
                 << "\n";
            return;
        }
    }
    cout << "Yes"
         << "\n";
    mx_dist = {-1, 0};
    dfs(0, -1, 0);
    int a = mx_dist.second;
    mx_dist = {-1, 0};
    dfs(a, -1, 0);
    pair<int, int> diam = {a, mx_dist.second};
    on_d[diam.second] = true;
    int cur = par[diam.second];
    while (cur != -1) {
        on_d[cur] = true;
        cur = par[cur];
    }
    vector<int> sol;
    map<int, vector<int>> nodes;
    for (int i = 0; i < n; ++i) {
        nodes[dist[i]].push_back(i);
    }
    for (int i = 0; i <= dist[diam.second]; i += 2) {
        int res;
        for (auto &j : nodes[i]) {
            if (!on_d[j]) {
                sol.push_back(j);
            } else {
                res = j;
            }
        }
        sol.push_back(res);
    }
    int r = dist[diam.second] - 1;
    if (dist[diam.second] % 2 == 1) {
        --r;
        for (auto &i : nodes[dist[diam.second]]) {
            sol.push_back(i);
        }
    }
    for (; r >= 1; r -= 2) {
        for (auto &i : nodes[r]) {
            if (on_d[i]) {
                sol.push_back(i);
            }
        }
        for (auto &i : nodes[r]) {
            if (!on_d[i]) {
                sol.push_back(i);
            }
        }
    }
    for (auto &i : sol) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
