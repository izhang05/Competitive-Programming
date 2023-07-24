/* Author: izhang
 * Time: 01-29-2022 16:02:02
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 16;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long grid[maxn][maxn];
int n;
long long sol;

void solve(const vector<int>& rem, long long cur) {
    if (rem.empty()) {
        sol = max(sol, cur);
        return;
    }
    for (int i = 1; i < int(rem.size()); ++i) {
        vector<int> nxt;
        for (int j = 1; j < int(rem.size()); ++j) {
            if (j == i) continue;
            nxt.push_back(rem[j]);
        }
        solve(nxt, cur ^ grid[rem[0]][rem[i]]);
    }
}

void test_case() {
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = i + 1; j < 2 * n; ++j) {
            cin >> grid[i][j];
            grid[j][i] = grid[i][j];
        }
    }
    vector<int> nums(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        nums[i] = i;
    }
    solve(nums, 0);
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
