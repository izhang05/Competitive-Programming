#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        pair<int, int> mn{inf, 0}, mx{0, 0};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mn = min(mn, {a[i], i});
            mx = max(mx, {a[i], i});
        }
        vector<int> ind{mn.second, mx.second};
        sort(ind.begin(), ind.end());
        cout << min({ind[1] + 1, ind[0] + 1 + n - ind[1], n - ind[0]}) << "\n";
    }
    return 0;
}
