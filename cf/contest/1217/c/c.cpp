/* Author: izhang05
 * Time: 07-08-2021 14:15:02
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
        string s;
        cin >> s;
        int n = int(s.size());
        long long sol = 0, len = 0, cur = 0, pre_len = 0;
        int last = 0;
        bool zero = true;
        for (int i = 0; i < n; ++i) {
            if (zero) {
                last = i;
                if (s[i] == '1') {
                    zero = false;
                    cur = 1;
                    ++sol;
                    pre_len = len;
                    len = 1;
                } else {
                    ++len;
                }
            } else {
                cur <<= 1;
                if (s[i] == '1') {
                    ++cur;
                }
                ++len;
                if (len + pre_len >= cur) {
                    ++sol;
                } else {
                    zero = true;
                    len = 0;
                    i = last;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
