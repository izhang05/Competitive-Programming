/* Author: izhang05
 * Time: 10-30-2021 10:35:02
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
    long long x, y;
    cin >> x >> y;
    if (x == y) {
        cout << x << "\n";
    } else if (x > y) {
        cout << x + y << "\n";
    } else {
        long long new_y = y % x + x;
        long long n = (new_y + x) / 2;
        n += x * ((y / x) - 1);
        cout << n << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
