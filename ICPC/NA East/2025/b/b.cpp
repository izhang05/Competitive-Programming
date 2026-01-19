#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> child[mxn];
char leaf[mxn];
int dp[mxn][2]; // [false, true]

void dfs(int c, bool a) {
//    cout << c << " " << child[c].size() << "\n";
    for (auto &i: child[c]) {
        dfs(i, !a);
    }
    if (leaf[c] == 'T') {
        dp[c][0] = 1;
    } else if (leaf[c] == 'F') {
        dp[c][1] = 1;
    } else {
        if (a) {
            int mn_diff = 1e9;
            for (auto &i: child[c]) {
                dp[c][1] += dp[i][1];
                dp[c][0] += min(dp[i][0], dp[i][1]);
                mn_diff = min(mn_diff, dp[i][0] - dp[i][1]);
            }
            dp[c][0] += max(0, mn_diff);
        } else {
            int mn_diff = 1e9;
            for (auto &i: child[c]) {
                dp[c][0] += dp[i][0];
                dp[c][1] += min(dp[i][0], dp[i][1]);
                mn_diff = min(mn_diff, dp[i][1] - dp[i][0]);
            }
            dp[c][1] += max(0, mn_diff);
        }
    }
    assert(min(dp[c][0], dp[c][1]) == 0);
//    cout << c << " " << dp[c][0] << " " << dp[c][1] << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);

    int n;
    char t;
    cin >> n >> t;
    int pre;
    cin >> pre;
    int cur_node = 1;
    vector<int> par;
    for (int i = 0; i < pre; ++i) {
        par.push_back(0);
    }
    for (int i = 1; i < n; ++i) {
        int nxt = 0;
        vector<int> nxt_par;
        for (int j = 0; j < pre; ++j) {
            string x;
            cin >> x;
            int cur_par = par.back();
            par.pop_back();
            child[cur_par].push_back(cur_node);
            if (x == "T" || x == "F") {
                leaf[cur_node] = x[0];
            } else {
                int num_c;
                if (x == "10") {
                    num_c = 10;
                } else {
                    num_c = x[0] - '0';
                }
                for (int k = 0; k < num_c; ++k) {
                    nxt_par.push_back(cur_node);
                }
                nxt += num_c;
            }
            ++cur_node;
        }
        par = nxt_par;
        reverse(par.begin(), par.end());
        pre = nxt;
    }
    dfs(0, t == 'A');
    cout << max(dp[0][0], dp[0][1]) << "\n";
//    assert(min(dp[0][0], dp[0][1]) == 0);
}
