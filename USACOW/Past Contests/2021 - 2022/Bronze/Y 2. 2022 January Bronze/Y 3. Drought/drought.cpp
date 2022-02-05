#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    if (a[n - 1] > a[n - 2]) {
        cout << -1 << "\n";
        return;
    }
    int mn = 1e9 + 5;
    for (int i = 0; i < n; ++i) {
        mn = min(mn, a[i]);
    }
    long long sol = 0;
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] != mn) {
                changed = true;
            }
            sol += a[i] - mn;
            a[i + 1] -= a[i] - mn;
            a[i] = mn;
            mn = min(mn, a[i + 1]);
        }
        if (a[n - 1] > a[n - 2] || mn < 0) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << sol * 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
