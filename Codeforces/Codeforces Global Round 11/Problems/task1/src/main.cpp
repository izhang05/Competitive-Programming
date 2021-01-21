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
        int sum = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == 0) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            if (sum < 0) {
                sort(a.begin(), a.end());
            } else {
                sort(a.begin(), a.end(), greater<>());
            }
            for (int i = 0; i < n - 1; ++i) {
                cout << a[i] << " ";
            }
            cout << a[n - 1] << "\n";
        }
    }
    return 0;
}
