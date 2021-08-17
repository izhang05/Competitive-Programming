/* Author: izhang05
 * Time: 08-15-2021 10:35:03
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
    int n;
    cin >> n;
    vector<int> a(n);
    bool one = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            one = false;
        }
    }
    if (one) {
        cout << n + 1 << " ";
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    a.push_back(1);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && a[i + 1] == 1) {
            for (int j = 1; j <= i + 1; ++j) {
                cout << j << " ";
            }
            cout << n + 1 << " ";
            for (int j = i + 2; j <= n; ++j) {
                cout << j << " ";
            }
            cout << "\n";
            return;
        }
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
