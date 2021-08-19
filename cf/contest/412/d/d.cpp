/* Author: izhang05
 * Time: 08-18-2021 23:45:11
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e4;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
set<int> adj[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> sol;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].insert(b);
    }
    for (int i = 0; i < n; ++i) {
        sol.push_back(i);
        for (int j = i - 1; j >= 0; --j) {
            if (adj[sol[j]].find(sol[j + 1]) != adj[sol[j]].end()) {
                swap(sol[j], sol[j + 1]);
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
