#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    //#ifdef LOCAL
    //    freopen((name + ".in").c_str(), "r", stdin);
    //    freopen((name + ".out").c_str(), "w", stdout);
    //    freopen((name + ".out").c_str(), "w", stderr);
    //#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
array<pair<int, int>, 2> dp[maxn];
vector<int> adj[maxn];
int a[maxn], n, cycle_ind[maxn], visited[maxn];
long long k;

void dfs1(int c, int p) {
    dp[c][0] = dp[c][1] = {-inf, -inf};
    for (auto i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            vector<pair<int, int>> pos;
            pos.emplace_back(dp[i][0].first - 1, dp[i][0].second);
            pos.emplace_back(a[i] - 1, -i);
            pos.emplace_back(dp[i][1].first - 1, dp[i][1].second);
            pos.push_back(dp[c][0]), pos.push_back(dp[c][1]);
            sort(pos.begin(), pos.end());
            reverse(pos.begin(), pos.end());
            int used = 0, num = -1;
            for (auto j : pos) {
                if (j.second != num) {
                    dp[c][used++] = j;
                    num = j.second;
                    if (used == 2) {
                        break;
                    }
                }
            }
        }
    }
}

void dfs2(int c, int p) {
    if (p != 0) {
        vector<pair<int, int>> pos;
        pos.emplace_back(dp[p][0].first - 1, dp[p][0].second);
        pos.emplace_back(a[p] - 1, -p);
        pos.emplace_back(dp[p][1].first - 1, dp[p][1].second);
        pos.push_back(dp[c][0]), pos.push_back(dp[c][1]);
        sort(pos.begin(), pos.end());
        reverse(pos.begin(), pos.end());
        int used = 0, num = 1;
        for (auto i : pos) {
            if (i.second != num) {
                dp[c][used++] = i;
                num = i.second;
                if (used == 2) {
                    break;
                }
            }
        }
    }
    for (auto i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }
}

signed main() {
    setIO("1");
    cin >> n >> k;
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i < n; ++i) {
        adj[i].clear();
    }
#ifdef DEBUG
    for (int i = 1; i < n + 1; ++i) {
        cout << dp[i][0].first << " " << dp[i][0].second << " " << dp[i][1].first << " " << dp[i][1].second << "\n";
    }
    cout << "\n";
#endif
    for (int i = 1; i < n + 1; ++i) {
        visited[i] = -1;
    }
    int cur = 1, cnt = 0;
    visited[1] = 0;
    bool flag = false;
    while (k) {
        int nex = -dp[cur][0].second;
        if (nex == cur) {
            nex = -dp[cur][1].second;
        }
        cur = nex;
        ++cnt;
        --k;
        if (!flag && visited[cur] != -1) {
            int cycLen = cnt - visited[cur];
            k %= cycLen;
            flag = true;
        }
        visited[cur] = cnt;
    }
    cout << cur << "\n";
    return 0;
}
