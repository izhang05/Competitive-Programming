/* Author: izhang05
 * Time: 06-25-2021 11:35:03
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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (n <= 2) {
            cout << 0 << "\n";
        } else {
            long long sol = 0, cur = 0;
            for (int i = 1; i < n; ++i) {
                cur += (i - 1) * (a[i] - a[i - 1]);
                sol += cur;
                cur += a[i] - a[i - 1];
            }
            cout << -sol << "\n";
        }
    }
    return 0;
}
