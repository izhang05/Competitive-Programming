/* Author: izhang05
 * Time: 07-18-2021 21:10:02
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
#define int long long
int n;
vector<int> a, b, pre_a, pre_b;

bool check(int x) {
    int total = x - x / 4, take_orig = total - (x - n);
    if (take_orig <= 0) {
        return true;
    }
#ifdef DEBUG
    cout << x << " " << 100 * (x - n) + pre_a[take_orig - 1] << " " << pre_b[take_orig - 1] << "\n";
#endif
    return 100 * (x - n) + pre_a[take_orig - 1] >= pre_b[min(total, n) - 1];
}

signed main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n), b.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        pre_a.resize(n), pre_b.resize(n);
        pre_a[0] = 0, pre_b[0] = 0;
        for (int i = 0; i < n; ++i) {
            pre_a[i] = pre_a[max(0ll, i - 1)] + a[i];
            pre_b[i] = pre_b[max(0ll, i - 1)] + b[i];
        }
        int lo = 0, hi = 1e9, m, sol;
        while (lo <= hi) {
            m = (lo + hi) / 2;
            if (check(m + n)) {
                sol = m;
                hi = m - 1;
            } else {
                lo = m + 1;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
