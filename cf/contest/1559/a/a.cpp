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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            vector<int> new_a(n);
            for (int k = 0; k < n; ++k) {
                new_a[k] = a[k];
            }
            for (int k = i; k <= j; ++k) {
                new_a[k] = a[k] & a[j - (k - i)];
            }
            swap(a, new_a);
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, a[i]);
    }
    cout << sol << "\n";
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
