/* Author: izhang05
 * Time: 10-03-2021 10:35:04
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n), sorted_a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        sorted_a[i] = a[i];
    }
    sort(sorted_a.begin(), sorted_a.end());
    for (int i = 0; i < n; ++i) {
        if (a[i] != sorted_a[i] && i - x < 0 && i + x >= n) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
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
