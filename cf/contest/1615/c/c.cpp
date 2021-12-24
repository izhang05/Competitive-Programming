/* Author: izhang05
 * Time: 12-24-2021 09:35:01
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

void test_case() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b;
    cin >> b;
    if (a == b) {
        cout << 0 << "\n";
        return;
    }
    int diff = 0, same = 0;
    int same0=0, same1=0, diff0=0, diff1=0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++diff;
            if (a[i] == '1') {
                ++diff1;
            } else {
                ++diff0;
            }
        } else {
            if (a[i] == '1') {
                ++same1;
            } else {
                ++same0;
            }
            ++same;
        }
    }
    int sol = inf;
    if ((same1 - same0 == 1) && same % 2 == 1) {
        sol = same;
    }
    if ((diff0 == diff1) && diff % 2 == 0) {
        sol = min(sol, diff);
    }
    cout << (sol == inf ? -1 : sol) << "\n";
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
