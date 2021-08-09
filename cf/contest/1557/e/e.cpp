/* Author: izhang05
 * Time: 08-09-2021 10:35:02
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

bool read() {
    string s;
    cin >> s;
    return s == "Done";
}

void solve() {
    int n = 8;
    while (true) {
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                for (int j = 1; j <= n; ++j) {
                    cout << i << " " << j << endl;
                    if (read()) {
                        return;
                    }
                }
            } else {
                for (int j = n; j >= 1; --j) {
                    cout << i << " " << j << endl;
                    if (read()) {
                        return;
                    }
                }
            }
        }
        for (int i = n; i >= 1; --i) {
            if (i % 2 == 1) {
                for (int j = 1; j <= n; ++j) {
                    cout << i << " " << j << endl;
                    if (read()) {
                        return;
                    }
                }
            } else {
                for (int j = n; j >= 1; --j) {
                    cout << i << " " << j << endl;
                    if (read()) {
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
