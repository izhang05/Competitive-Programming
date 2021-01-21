#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int mx = *max_element(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            a[i] = mx - a[i];
        }
        if (k % 2 == 1) {
            for (int i = 0; i < n - 1; ++i) {
                cout << a[i] << " ";
            }
            cout << a[n - 1];
        } else {
            mx = *max_element(a.begin(), a.end());
            for (int i = 0; i < n; ++i) {
                a[i] = mx - a[i];
            }
            for (int i = 0; i < n - 1; ++i) {
                cout << a[i] << " ";
            }
            cout << a[n - 1];
        }
        cout << "\n";
    }
    return 0;
}
