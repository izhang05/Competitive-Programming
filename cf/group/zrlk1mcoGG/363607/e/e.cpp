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
    unordered_set<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    map<int, int> cnt;
    for (auto &i : nums) {
        for (int j = i + i; j <= 1e5; j += i) {
            if (nums.find(j) != nums.end()) {
                ++cnt[j], ++cnt[i];
            }
        }
    }
    for (auto &i : cnt) {
        if (i.second % 2) {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
