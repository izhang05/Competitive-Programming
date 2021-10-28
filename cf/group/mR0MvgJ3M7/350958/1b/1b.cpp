/* Author: izhang05
 * Time: 10-27-2021 09:33:10
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int l, q;
    cin >> l >> q;
    set<int> nums;
    nums.insert(0), nums.insert(l);
    while (q--) {
        int t, p;
        cin >> t >> p;
        if (t == 1) {
            nums.insert(p);
        } else if (t == 2) {
            auto it = nums.lower_bound(p);
            cout << *it - *prev(it) << "\n";
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
