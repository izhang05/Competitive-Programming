/* Author: izhang05
 * Time: 07-19-2021 14:25:14
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

void solve() {
    long long x;
    cin >> x;
    if (x == 1) {
        cout << "NO"
             << "\n";
        return;
    }
    long long s = round(sqrt(x));
    if (s * s != x) {
        cout << "NO"
             << "\n";
        return;
    }
    for (int i = 2; i * i <= s; ++i) {
        if (s % i == 0) {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
