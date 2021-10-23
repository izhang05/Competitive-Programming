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
        cout << pre[i] << " ";
    }
    cout << "\n";
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int sum = pre[r];
        if (l) {
            sum -= pre[l - 1];
        }
        if (sum == 0) {
            cout << 0 << "\n";
            continue;
        }
        vector<int> sol;
        if ((r - l + 1) % 2 == 0) {
            sol.push_back(++l);
        }
        int res = -1, mid, lo = l, hi = r;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int lv = (mid ? pre[mid - 1] : 0);
            if (l) {
                lv -= pre[l - 1];
            }
            int rv = pre[r] - pre[mid];
            if (lv == rv) {
                res = mid;
                break;
            } else if (lv > rv) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        sol.push_back(res + 1);
        cout << sol.size() << "\n";
        for (auto &i : sol) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    setIO("2");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
