/* Author: izhang05
 * Time: 08-26-2021 10:35:03
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
    for (int i = n / 2; i < n; ++i) {
        if (s[i] == '0') {
            cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
            return;
        }
    }
    for (int i = n - (n / 2) - 1; i >= 0; --i) {
        if (s[i] == '0') {
            cout << i + 2 << " " << n << " " << i + 1 << " " << n << "\n";
            return;
        }
    }
    cout << 1 << " " << n / 2 << " " << 2 << " " << n / 2 + 1 << "\n";
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
