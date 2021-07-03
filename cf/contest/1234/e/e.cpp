/* Author: izhang05
 * Time: 07-02-2021 21:35:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
#define int long long

signed main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<vector<int>> adj(n);
    vector<int> loc(n), p(n);
    for (int i = 0; i < n; ++i) {
        loc[i] = i;
        p[i] = i;
    }
    int sol = 0;
    for (int i = 0; i < m - 1; ++i) {
        sol += abs(a[i + 1] - a[i]);
        adj[a[i]].push_back(a[i + 1]);
        adj[a[i + 1]].push_back(a[i]);
    }
    cout << sol;
    for (int i = 1; i < n; ++i) {
        loc[p[0]] = i;
        loc[p[i]] = 0;
        swap(p[0], p[i]);
        for (auto &j : adj[p[0]]) {
            if (loc[j] != i && loc[j] != 0) {
                int pre = abs(i - loc[j]);
                sol -= pre;
                sol += abs(0 - loc[j]);
            }
        }
        for (auto &j : adj[p[i]]) {
            if (loc[j] != 0 && loc[j] != i) {
                int pre = abs(0 - loc[j]);
                sol -= pre;
                sol += abs(i - loc[j]);
            }
        }
        cout << " " << sol;
    }
    cout << "\n";
    return 0;
}
