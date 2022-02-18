/* Author: izhang
 * Time: 02-17-2022 20:44:35
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
    int a, b;
    cin >> a >> b;
    int sol = b - a;
    for (int i = 0; i < b - a; ++i) {
        if (((a + i) & b) == (a + i)) {
            sol = min(sol, i + 1);
        }
    }
    for (int i = 0; i < b - a; ++i) {
        if ((a & (b + i)) == a) {
            sol = min(sol, i + 1);
        }
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
