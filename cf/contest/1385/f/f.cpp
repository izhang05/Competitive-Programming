/* Author: izhang05
 * Time: 12-23-2021 14:02:41
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
int n, k, deg[maxn], leaf_adj[maxn];

void test_case() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        deg[i] = leaf_adj[i] = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++deg[a], ++deg[b];
    }
    if (k == 1) {
        cout << n - 1 << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (auto &j : adj[i]) {
            if (deg[j] == 1) {
                ++leaf_adj[i];
            }
        }
    }
    set<pair<int, int>, greater<>> s;
    for (int i = 0; i < n; ++i) {
        s.insert({leaf_adj[i], i});
    }
    int sol = 0;
    while (!s.empty() && s.begin()->first >= k) {
        pair<int, int> cur = *s.begin();
        s.erase(s.begin());
        ++sol;
        int node = cur.second;
        deg[node] -= k;
        leaf_adj[node] -= k;
        if (deg[node] == 1) {
            for (auto &i : adj[node]) {
                if (deg[i] != 1) {
                    s.erase({leaf_adj[i], i});
                    ++leaf_adj[i];
                    s.insert({leaf_adj[i], i});
                    break;
                }
            }
        }
        s.insert({leaf_adj[node], node});
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
