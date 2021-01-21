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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        reverse(a.begin(), a.end());
        cout << a[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << a[i];
        }
        cout << "\n";
    }
    return 0;
}
