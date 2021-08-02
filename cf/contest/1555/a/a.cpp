/* Author: izhang05
 * Time: 07-30-2021 10:35:04
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
        long long n;
        cin >> n;
        long long sol = 0;
        if (n > 12) {
            sol = ((n + 5) / 6) * 15 - 30;
            n -= 6 * ((n + 5) / 6);
            n += 12;
        }
        if (n <= 6) {
            sol += 15;
        } else if (n <= 8) {
            sol += 20;
        } else if (n <= 10) {
            sol += 25;
        } else {
            sol += 30;
        }
        cout << sol << "\n";
    }
    return 0;
}
