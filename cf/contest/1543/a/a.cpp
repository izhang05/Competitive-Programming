/* Author: izhang05
 * Time: 07-07-2021 10:35:04
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
    long long a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << " " << 0 << "\n";
        return;
    }
    long long dist = abs(a - b);
    cout << dist << " " << min(a % dist, dist - (a % dist)) << "\n";
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
