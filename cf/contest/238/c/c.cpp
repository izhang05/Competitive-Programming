/* Author: izhang05
 * Time: 07-09-2021 15:49:04
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e3 + 5;
vector<pair<int, int>> adj[maxn];
int sub[maxn], cur, longest;

void dfs(int c, int p, int best) {
    best = max(0, best);
    longest = max(longest, best);
    for (auto &i : adj[c]) {
        if (i.first != p) {
            cur += i.second;
            int next_best = best + i.second;
            if (i.second == 0) {
                --next_best;
            }
            dfs(i.first, c, next_best);
        }
    }
}

int main() {
    setIO("3");
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, 0);
        adj[b].emplace_back(a, 1);
    }
    int sol = n - 1;
    for (int i = 0; i < n; ++i) {
        cur = 0, longest = 0;
        dfs(i, -1, 0);
        sol = min(sol, cur - longest);
#ifdef DEBUG
        cout << i << " " << cur << " " << longest << " " << sol << "\n";
#endif
    }
    cout << sol << "\n";
    return 0;
}
