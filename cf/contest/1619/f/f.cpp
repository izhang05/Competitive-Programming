/* Author: izhang
 * Time: 02-25-2022 23:31:49
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    int greater = n - m * (n / m);
    for (int i = 0; i < k; ++i) {
        int j = 0;
        for (int cnt = 0; cnt < greater; j += n / m + 1, ++cnt) {
            cout << n / m + 1;
            for (int l = j; l < j + n / m + 1; ++l) {
                cout << " " << nums[l];
            }
            cout << "\n";
        }
        for (; j < n; j += n / m) {
            cout << n / m;
            for (int l = j; l < j + n / m; ++l) {
                cout << " " << nums[l];
            }
            cout << "\n";
        }
        rotate(nums.begin(), nums.begin() + (n / m) * (m - greater), nums.end());
    }
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
