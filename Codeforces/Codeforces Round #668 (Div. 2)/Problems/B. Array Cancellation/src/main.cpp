#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long sol = max(0ll, a[0]);
        for (int i = 1; i < n; ++i) {
            sol = max(0ll, sol + a[i]);
        }
        cout << sol << "\n";
    }
    return 0;
}
