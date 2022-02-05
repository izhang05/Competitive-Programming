/* Author: izhang
 * Time: 01-18-2022 22:55:17
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
int sol = 0;

int dfs(int c, int p) {
    int res = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            res += dfs(i, c);
        }
    }
    return res;
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        int mx = 0;
        for (auto &j : adj[i]) {
            mx = max(mx, dfs(j, i));
        }
        sol = max(sol, n - mx);
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
