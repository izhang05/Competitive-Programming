/* Author: izhang05
 * Time: 08-18-2021 10:39:53
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
    int n, k;
    cin >> n >> k;
    for (long long i = n;; ++i) {
        set<int> nums;
        long long cur = i;
        while (cur) {
            nums.insert(cur % 10);
            cur /= 10;
        }
        if (int(nums.size()) <= k) {
            cout << i << "\n";
            break;
        }
    }
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
