/* Author: izhang
 * Time: 02-06-2022 09:35:02
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
    int n, k;
    cin >> n >> k;
    int m = n * k;
    int odd = (m + 1) / 2, even = m / 2;
    if (odd % k != 0 || even % k != 0) {
        cout << "NO"
             << "\n";
        return;
    }
    cout << "YES"
         << "\n";
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << cur << " \n"[j == k - 1];
            cur += 2;
            if (cur > m) {
                cur = 2;
            }
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
