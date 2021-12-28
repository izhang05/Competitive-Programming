/* Author: izhang05
 * Time: 12-28-2021 16:40:25
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

void test_case() {
    long long t1, t2, t3, t4, t5, t6;
    cin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6;
    __int128 k = t1, l = t2, r = t3, t = t4, x = t5, y = t6;
    // change range to [0, r]
    k -= l, r -= l;
    if (k - t * x >= 0) {
        cout << "Yes"
             << "\n";
        return;
    }
    if (y <= x) {
        // always take when r - k >= y
        __int128 mn = r - y, turns = max(__int128(0), (k - mn + x - 1) / x);
        t -= turns;
        k -= turns * x;
        if (k - t * (x - y) >= 0) {
            cout << "Yes"
                 << "\n";
        } else {
            cout << "No"
                 << "\n";
        }
        return;
    }
    if (y > r) {
        cout << "No"
             << "\n";
        return;
    }
    gp_hash_table<long long, null_type> seen;
    seen.insert(k);
    while (t > 0) {
        __int128 mn = r - y, turns = min(t, max(__int128(0), (k - mn + x - 1) / x));
        t -= turns;
        k -= turns * x;
        if (k < 0) {
            cout << "No"
                 << "\n";
            return;
        }
        turns = (mn - k) / (y - x);
        t -= turns;
        k += turns * (y - x) + y;
        if (seen.find((long long) k) != seen.end()) {
            break;
        }
        seen.insert((long long) k);
    }
    cout << "Yes"
         << "\n";
}

int main() {
    setIO("3");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
