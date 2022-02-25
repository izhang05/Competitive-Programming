/* Author: izhang
 * Time: 02-24-2022 08:42:37
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
    if (n % 2 == 0) {
        cout << n / 2 << " " << n / 2 - 1 << " " << 1 << "\n";
    } else {
        if ((n / 2) % 2 == 0) {
            cout << n / 2 - 1 << " " << n / 2 + 1 << " " << 1 << "\n";
        } else {
            cout << n / 2 - 2 << " " << n / 2 + 2 << " " << 1 << "\n";
        }
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
