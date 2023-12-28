#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || DEBUG
#include <debug.h>
#endif

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
const int mxn = 2e5 + 5;
vector<int> adj[mxn];
const long long INFL = 4e18;
int children[mxn];
long long par[mxn], sz[mxn], dp[mxn], dp2[mxn]; // dp[i] - turn on all subtrees with lights remaining on, dp2[i] - turn on all subtrees with lights remaining off

void dfs0(int c, int p) {
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs0(i, c);
            sz[c] += sz[i];
            ++children[c];
        }
    }
}

void dfs1(int c, int p) {
    dp[c] = 1;
    long long mx = 0;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            dp[c] += dp2[i] + sz[i];
            assert(dp2[i] + sz[i] - dp[i] >= 0);
            mx = max(mx, dp2[i] + sz[i] - dp[i]);
        }
    }
    dp[c] -= mx;

    dp2[c] = 2;
    pair<long long, long long> mx2{0, 0};
    vector<array<long long, 3>> nums;
    for (auto &i : adj[c]) {
        if (i != p) {
            dp2[c] += dp2[i] + 2 * sz[i];
            nums.push_back({dp[i], dp2[i], sz[i]});
            int const cur = dp2[i] + 2 * sz[i] - (dp[i] + sz[i]);
            assert(cur >= 0);
            if (cur > mx2.first) {
                swap(mx2.first, mx2.second);
                mx2.first = cur;
            } else if (cur > mx2.second) {
                mx2.second = cur;
            }
        }
    }
    long long orig = dp2[c];
    int m = int(nums.size());
    //    dbg() << c << " " << imie(m) << " " << dp2[c];
    if (m == 0) {
        return;
    } else if (m == 1) {
        dp2[c] = 2 + nums[0][1];
    } else {
        dp2[c] -= mx2.first + mx2.second;
        //        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (i == j) {
//                    continue;
//                }
//                long long cur = orig;
//                cur -= nums[i][1] + 2 * nums[i][2];
//                cur -= nums[j][1] + 2 * nums[j][2];
//                //                dbg() << i << " " << j << " " << imie(cur);
//
//                cur += nums[i][0] + nums[i][2];
//                //                cur += nums[j][0] + nums[j][2];
//                cur += nums[j][1];
//                dp2[c] = min(dp2[c], cur);
//            }
//        }
    }
    //    dbg() << c << " " << dp[c] << " " << dp2[c] << " " << mx2.first << " " << mx2.second;
}

int main() {
    setIO("1");
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        par[i] = p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    par[0] = -1;
    for (int i = 0; i < n; ++i) {
        sz[i] = 1;
    }
    dfs0(0, -1);
    dfs1(0, -1);
//    for (int i = 0; i < n; ++i) {
//        dbg() << i << " " << dp[i] << " " << dp2[i] << " " << sz[i];
//    }
    cout << dp2[0] << "\n";
    return 0;
}
