/* Author: izhang05
 * Time: 07-22-2021 10:16:55
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

int main() {
    setIO("1");

    long long n, k;
    cin >> n >> k;
    if (k >= 43) {
        cout << "No"
             << "\n";
    } else {
        set<long long> nums;
        for (int i = 1; i <= k; ++i) {
            long long cur = n % i;
            if (nums.find(cur) != nums.end()) {
                cout << "No" << "\n";
                return 0;
            }
            nums.insert(cur);
        }
        cout << "Yes" << "\n";
    }
    return 0;
}
