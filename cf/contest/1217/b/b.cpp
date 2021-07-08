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
        long long n, x;
        cin >> n >> x;
        vector<long long> a(n);
        long long mx = 0;
        for (int i = 0; i < n; ++i) {
            long long b, c;
            cin >> b >> c;
            mx = max(mx, b);
            a[i] = b - c;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        if (mx >= x) {
            cout << 1 << "\n";
        } else if (a[0] <= 0 && x > mx) {
            cout << -1 << "\n";
        } else {
            cout << max(0ll, (x - mx + a[0] - 1) / a[0]) + 1 << "\n";
        }
    }
    return 0;
}
