/* Author: izhang05
 * Time: 12-27-2021 15:56:21
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
    set<int> nums;
    for (int i = 1; i < n + 1; ++i) {
        nums.insert(i);
    }
    int sol = n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        if (b <= n && nums.find(b) != nums.end()) {
            --sol;
            nums.erase(b);
        } else {
            a.push_back(b);
        }
    }
    sort(a.begin(), a.end());
    for (auto &i : a) {
        auto it = nums.upper_bound((i - 1) / 2);
        if (it == nums.begin()) {
            cout << -1 << "\n";
            return;
        }
        nums.erase(prev(it));
    }
    cout << sol << "\n";
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
