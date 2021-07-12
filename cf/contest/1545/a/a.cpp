/* Author: izhang05
 * Time: 07-11-2021 10:05:01
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    map<int, multiset<int>> loc;
    for (int i = 0; i < n; ++i) {
        loc[b[i]].insert(i % 2);
    }
    for (int i = 0; i < n; ++i) {
        if (loc[a[i]].find(i % 2) == loc[a[i]].end()) {
            cout << "NO"
                 << "\n";
            return;
        }
        loc[a[i]].erase(loc[a[i]].find(i % 2));
    }
    cout << "YES" << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
