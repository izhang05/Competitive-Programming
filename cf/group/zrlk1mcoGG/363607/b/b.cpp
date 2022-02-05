/* Author: izhang
 * Time: 01-18-2022 22:55:17
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
    vector<int> a(n);
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums[i] = i + 1;
    }
    do {
        vector<int> cur(2 * n);
        int ind = 0;
        bool good = true;
        for (auto &i : nums) {
            while (ind < 2 * n && cur[ind] != 0) {
                ++ind;
            }
            cur[ind] = i;
            int nxt = ind + a[i - 1];
            if (nxt >= 2 * n || cur[nxt] != 0) {
                good = false;
                break;
            }
            cur[nxt] = i;
        }
        for (auto &i : cur) {
            if (i == 0) {
                good = false;
            }
        }

        if (good) {
            cout << "YES"
                 << "\n";
            for (auto &i : cur) {
                cout << i << " ";
            }
            cout << "\n";
            return;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    cout << "NO"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
