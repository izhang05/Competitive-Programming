/* Author: izhang05
 * Time: 12-23-2021 20:40:02
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
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0 << "\n";
        return;
    }
    if (c == 1) {
        for (int i = 0; i < r; ++i) {
            cout << i + 2 << "\n";
        }
        return;
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = r + 1; j <= r + c; ++j) {
            cout << i * j << " ";
        }
        cout << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
