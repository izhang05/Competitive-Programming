/* Author: izhang05
 * Time: 06-26-2021 22:34:06
**/
#include <bits/stdc++.h>

using namespace std;

#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
//    #ifdef DEBUG
//        freopen("in2.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
//        freopen("out.txt", "w", stderr);
//    #endif
}
const long long inf = 1e18;

#define int long long
signed main() {
    setIO("");
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        long long mx = -inf;
        vector<long long> a(n), pre(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            pre[i] = pre[max(0ll, i - 1)] + a[i];
            mx = max(mx, pre[i]);
        }
        vector<pair<long long, long long>> sorted_pre;
        long long last = -1;
        for (int i = 0; i < n; ++i) {
            if (pre[i] > last) {
                last = pre[i];
                sorted_pre.emplace_back(pre[i], i);
            }
        }
        for (int i = 0; i < m; ++i) {
            long long x;
            cin >> x;
            long long sol;
            if (sum <= 0) {
                auto it = lower_bound(sorted_pre.begin(), sorted_pre.end(), make_pair(x, 0ll));
                if (it != sorted_pre.end()) {
                    sol = it->second;
                } else {
                    sol = -1;
                }
            } else {
                long long full = max(0ll, (x - mx + sum - 1) / sum);
                sol = full * n;
                //                cout << x << " " << mx << " " << x - full * sum << " " << sum << "\n";
                auto it = lower_bound(sorted_pre.begin(), sorted_pre.end(), make_pair(x - full * sum, 0ll));
                //                if (it != sorted_pre.end()) {
                sol += it->second;
                //                }
            }
            cout << sol << " ";
        }
        cout << "\n";
    }

    return 0;
}
