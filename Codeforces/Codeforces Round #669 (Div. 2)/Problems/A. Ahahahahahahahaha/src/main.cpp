#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, zero = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            if (a == 0) {
                ++zero;
            }
        }

        if (zero >= n / 2) {
            cout << n / 2 << "\n";
            cout << 0;
            for (int i = 0; i < n / 2 - 1; ++i) {
                cout << " " << 0;
            }
        } else {
            if (n % 4 == 0) {
                cout << n / 2 << "\n";
                cout << 1;
                for (int i = 0; i < n / 2 - 1; ++i) {
                    cout << " " << 1;
                }
            } else {
                cout << n / 2 + 1 << "\n";
                cout << 1;
                for (int i = 0; i < n / 2; ++i) {
                    cout << " " << 1;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
