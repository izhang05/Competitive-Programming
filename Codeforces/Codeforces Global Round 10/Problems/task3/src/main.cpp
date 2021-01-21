#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long sol = 0, mn = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] > mn) {
                sol += a[i] - mn;
                mn = a[i];
            } else {
                mn = min(mn, a[i]);
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
