/* Author: izhang05
 * Time: 12-27-2021 09:35:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    pair<long long, vector<int>> sol;
    sol.first = -1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cur -= x[i];
            } else {
                cur += x[i];
            }
        }
        vector<pair<long long, int>> nums(m);
        for (int i = 0; i < m; ++i) {
            int cur_cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (s[j][i] == '1') {
                    if (mask & (1 << j)) {
                        ++cur_cnt;
                    } else {
                        --cur_cnt;
                    }
                }
            }
            nums[i] = {cur_cnt, i};
        }
        sort(nums.begin(), nums.end());
        vector<int> perm(m);
        for (int i = 0; i < m; ++i) {
            perm[nums[i].second] = i + 1;
            cur += (i + 1) * nums[i].first;
        }
        if (cur > sol.first) {
            sol = {cur, perm};
        }
    }
    for (auto &i : sol.second) {
        cout << i << " ";
    }
    cout << "\n";
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
