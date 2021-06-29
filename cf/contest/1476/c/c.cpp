/* Author: izhang05
 * Time: 06-29-2021 15:38:29
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
        vector<long long> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<long long> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        long long sol = 0, cur = 0;
        for (int i = n - 1; i >= 1; --i) {
            cur = max(cur, c[i] - 1);
            if (a[i] == b[i]) {
                sol = max(sol, cur + 2);
                cur = 0;
            } else {
                sol = max(sol, cur + 2 + abs(b[i] - a[i]));
                cur += c[i - 1] - 1 - (abs(b[i] - a[i])) + 2;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
