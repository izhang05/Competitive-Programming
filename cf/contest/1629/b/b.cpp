/* Author: izhang
 * Time: 02-23-2022 18:44:51
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
    int l, r, k;
    cin >> l >> r >> k;
    if (l == r) {
        if (l == 1) {
            cout << "NO"
                 << "\n";
        } else {
            cout << "YES"
                 << "\n";
        }
    } else {
        int odd = (r + 1) / 2 - l / 2;
        cout << (k >= odd ? "YES" : "NO") << "\n";
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
