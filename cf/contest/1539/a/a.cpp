/* Author: izhang05
 * Time: 06-22-2021 21:25:02
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
    long long n, x, y;
    cin >> n >> x >> y;
    if (y < x) {
        cout << 0 << "\n";
        return;
    }
    long long first = min(n - 1, y / x);
    long long mx = (n - 1) * x - y;
    long long full = max(0ll, mx / x) + 1;
    long long sol = first * full;
    long long left = n - full;
    sol += (left * (left - 1)) / 2;
    cout << sol << "\n";
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
