/* Author: izhang05
 * Time: 09-15-2021 13:57:07
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        a = 0, b = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == 'a') {
                ++a;
            } else {
                ++b;
            }
            if (a == b) {
                cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    }
    cout << -1 << " " << -1 << "\n";
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
