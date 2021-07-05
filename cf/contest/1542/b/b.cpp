/* Author: izhang05
 * Time: 07-03-2021 09:05:10
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
    long long a, b, n;
    cin >> n >> a >> b;
    long long cur = 1;
    if (a > 1) {
        while (cur * a <= n) {
            if ((n - cur) % b == 0) {
                cout << "Yes"
                     << "\n";
                return;
            }
            cur *= a;
        }
    }
    if ((n - cur) % b == 0) {
        cout << "Yes"
             << "\n";
    } else {
        cout << "No"
             << "\n";
    }
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
