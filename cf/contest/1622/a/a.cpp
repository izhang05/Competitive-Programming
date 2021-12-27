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
    vector<int> a(3);
    map<int, int> nums;
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
        ++nums[a[i]];
    }
    sort(a.begin(), a.end());
    if (a[2] == a[0] + a[1]) {
        cout << "YES"
             << "\n";
    } else if (nums.size() == 2) {
        int one;
        if (nums.begin()->second == 2) {
            one = nums.rbegin()->first;
        } else {
            one = nums.begin()->first;
        }
        if (one % 2 == 0) {
            cout << "YES"
                 << "\n";
        } else {
            cout << "NO"
                 << "\n";
        }
    } else if (nums.size() == 1 && nums.begin()->first % 2 == 0) {
        cout << "YES"
             << "\n";
    } else {
        cout << "NO"
             << "\n";
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
