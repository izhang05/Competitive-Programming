/* Author: izhang
 * Time: 03-02-2022 00:53:20
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
    int n;
    cin >> n;
    map<int, int> occ;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++occ[a];
    }
    vector<pair<int, int>> nums;
    for (auto &i : occ) {
        nums.emplace_back(i.second, i.first);
    }
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    pair<int, int> mx;
    int r = int(nums.size()) - 1;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = r; j >= 0; --j) {
            ++cur;
            if (nums[j].first == i) {
                r = j - 1;
            }
        }
        long long lo = 0, hi = n, mid, res;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (i * mid <= cur) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (i <= res && (i * res > mx.first * mx.second)) {
            mx = {i, res};
        }
    }
    int cnt = mx.first * mx.second;
    cout << cnt << "\n";
    cout << mx.first << " " << mx.second << "\n";
    vector<int> numbers;
    for (int i = 0; cnt > 0; ++i) {
        for (int j = 0; j < min(mx.first, nums[i].first) && cnt > 0; ++j) {
            --cnt;
            numbers.push_back(nums[i].second);
        }
    }
    vector<vector<int>> sol(mx.first, vector<int>(mx.second));
    int i = 0, j = 0;
    cnt = 0;
    for (auto &k : numbers) {
        sol[i][j] = k;
        ++i, ++j, ++cnt;
        i %= mx.first, j %= mx.second;
        if (cnt % mx.first == 0) {
            i = 0;
            j = cnt / mx.first;
        }
    }
    for (int k = 0; k < mx.first; ++k) {
        for (int l = 0; l < mx.second; ++l) {
            cout << sol[k][l] << " \n"[l == mx.second - 1];
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
