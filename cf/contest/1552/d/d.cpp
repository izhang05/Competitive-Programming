/* Author: izhang05
 * Time: 07-25-2021 10:36:09
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> sums;
    for (int i = 0; i < (1 << n); ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cur += a[j];
            }
        }
        if (sums.find(cur) != sums.end()) {
            cout << "YES"
                 << "\n";
            return;
        }
        sums.insert(cur);
    }
    cout << "NO" << "\n";
}

int main() {
    setIO("2");

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
