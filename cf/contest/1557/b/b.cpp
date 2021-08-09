/* Author: izhang05
 * Time: 08-09-2021 10:35:02
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> sorted(a.begin(), a.end());
    sort(a.begin(), a.end());
    map<int, int> next;
    for (int i = 0; i < n - 1; ++i) {
        next[sorted[i]] = sorted[i + 1];
    }
    next[sorted[n - 1]] = inf;
    int cost = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (next[a[i]] != a[i + 1]) {
            ++cost;
        }
    }
    cout << (cost <= k ? "Yes" : "No") << "\n";
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
