/* Author: izhang05
 * Time: 08-05-2021 18:01:45
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
        int n;
        cin >> n;
        string s, u;
        cin >> s >> u;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - '0';
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = u[i] - '0';
        }
        int sol = 0;
        for (int i = 0; i < n; ++i) {
            if (!b[i]) {
                continue;
            }
            if (a[i] == 0) {
                ++sol;
                continue;
            }
            if (i - 1 >= 0) {
                if (a[i - 1]) {
                    ++sol;
                    a[i - 1] = 0;
                    continue;
                }
            }
            if (i + 1 < n) {
                if (a[i + 1]) {
                    ++sol;
                    a[i + 1] = 0;
                    continue;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
