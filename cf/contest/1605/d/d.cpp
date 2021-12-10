/* Author: izhang05
 * Time: 12-02-2021 16:54:20
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
int cnt[2], sol[maxn];
vector<int> avail[2];

void dfs(int c, int p, int d) {
    ++cnt[d % 2];
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

void dfs1(int c, int p, int d) {
    sol[c] = avail[d % 2].back();
    avail[d % 2].pop_back();
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c, d + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(cnt, 0, sizeof(cnt));
    dfs(0, -1, 0);
    int mn = cnt[0] <= cnt[1] ? 0 : 1;
    for (int i = 0; i < 20; ++i) {
        if ((1 << i) & cnt[mn]) {
            for (int j = (1 << i); j < (1 << (i + 1)) && j <= n; ++j) {
                avail[mn].push_back(j);
            }
        } else {
            for (int j = (1 << i); j < (1 << (i + 1)) && j <= n; ++j) {
                avail[mn ^ 1].push_back(j);
            }
        }
    }
    dfs1(0, -1, 0);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " \n"[i == n - 1];
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
