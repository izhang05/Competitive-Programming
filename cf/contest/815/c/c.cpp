/* Author: izhang05
 * Time: 08-07-2021 00:40:16
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
const int mod = 1e9 + 7, maxn = 5e3 + 5;
const long long inf = 2e18;
int cost[maxn], disc[maxn];
vector<long long> dp[maxn][2];
vector<int> child[maxn];

vector<long long> merge(vector<long long> a, vector<long long> b) {
    vector<long long> res(a.size() + b.size() - 1, inf);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            res[i + j] = min(res[i + j], a[i] + b[j]);
        }
    }
    return res;
}

void dfs(int c) {
    dp[c][0] = {0, cost[c]};
    dp[c][1] = {inf, disc[c]};

    for (auto &i : child[c]) {
        dfs(i);
        dp[c][0] = merge(dp[c][0], dp[i][0]);
        dp[c][1] = merge(dp[c][1], dp[i][1]);
    }
    for (int i = 0; i < dp[c][1].size(); ++i) {
        dp[c][1][i] = min(dp[c][1][i], dp[c][0][i]);
    }
}

int main() {
    setIO("1");
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        cin >> cost[i] >> disc[i];
        disc[i] = cost[i] - disc[i];
        if (i != 0) {
            int p;
            cin >> p;
            --p;
            child[p].push_back(i);
        }
    }
    dfs(0);
    for (int i = n; i >= 0; --i) {
        if (dp[0][1][i] <= b) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
