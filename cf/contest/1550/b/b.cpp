/* Author: izhang05
 * Time: 07-14-2021 14:04:05
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

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        if (b >= 0) {
            cout << n * a + n * b << "\n";
        } else {
            int zero = 0, one = 0;
            char pre = s[0];
            for (int i = 1; i < n; ++i) {
                if (s[i] != pre) {
                    if (pre == '0') {
                        ++zero;
                    } else {
                        ++one;
                    }
                }
                pre = s[i];
            }
            if (pre == '0') {
                ++zero;
            } else {
                ++one;
            }
            cout << n * a + b * (min(zero, one) + 1) << "\n";
        }
    }
    return 0;
}
