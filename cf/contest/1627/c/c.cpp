/* Author: izhang
 * Time: 01-15-2022 09:35:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn];
int deg[maxn];

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        deg[i] = 0;
    }
    int mx = 0;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
        ++deg[a], ++deg[b];
        mx = max({mx, deg[a], deg[b]});
    }
    if (mx >= 3) {
        cout << -1 << "\n";
        return;
    }
    vector<int> sol(n - 1);
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            sol[adj[i][0].second] = 2;
            int cur = adj[i][0].first;
            int last = 2, p = i;
            while (deg[cur] > 1) {
                for (auto &j : adj[cur]) {
                    if (j.first != p) {
                        p = cur;
                        sol[j.second] = 5 - last;
                        cur = j.first;
                        break;
                    }
                }
                last = 5 - last;
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << sol[i] << " \n"[i == n - 2];
    }
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
