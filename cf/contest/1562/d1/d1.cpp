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
    int n, q;
    cin >> n >> q;
    string tmp;
    cin >> tmp;
    vector<int> a(n), pre(n);
    for (int i = 0; i < n; ++i) {
        a[i] = (tmp[i] == '+' ? 1 : -1);
        if (i % 2 == 1) {
            a[i] *= -1;
        }
        pre[i] = pre[max(0, i - 1)] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int sum = pre[r];
        if (l) {
            sum -= pre[l - 1];
        }
        sum = abs(sum);
        cout << sum - 2 * ((sum - 1) / 2) << "\n";
    }
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







