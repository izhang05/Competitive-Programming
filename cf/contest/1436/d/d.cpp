/* Author: izhang05
 * Time: 08-06-2021 22:12:19
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
vector<int> adj[maxn];
__int128 dp[maxn];
long long a[maxn], x;
bool good;

void dfs(int c, int p) {
    bool leaf = true;
    __int128 cur = a[c];
    for (auto &i : adj[c]) {
        if (i != p) {
            leaf = false;
            dfs(i, c);
            if (!good) {
                return;
            }
            cur -= dp[i];
        }
    }
    if (leaf) {
        if (a[c] > x) {
            good = false;
        }
        dp[c] = x - a[c];
    } else {
        if (cur > 0) {
            good = false;
        } else {
            dp[c] = -cur;
        }
    }
}

bool check() {
    memset(dp, 0, sizeof(dp));
    good = true;
    dfs(0, -1);
    return good;
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long lo = 0, hi = 1e15, mid, sol = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        x = mid;
        if (check()) {
            sol = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}
