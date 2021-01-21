#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long sol = -1e18;
        for (int i = 0; i < 5; ++i) {
            long long cur = 1;
            for (int j = 0; j < i; ++j) {
                cur *= a[j];
            }
            for (int j = n - 1; j > n - 1 - (5 - i); --j) {
                cur *= a[j];
            }
            sol = max(cur, sol);
        }
        cout << sol << "\n";
    }
    return 0;
}
