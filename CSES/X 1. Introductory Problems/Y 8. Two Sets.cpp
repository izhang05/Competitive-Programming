#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n;
    cin >> n;
    if (n % 4 == 2 || n % 4 == 1) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        if (n % 4 == 0) {
            cout << n / 2 << "\n";
            for (int i = 1; i < n + 1; ++i) {
                if (i % 4 == 0 || i % 4 == 1) {
                    cout << i << " ";
                }
            }
            cout << "\n" << n / 2 << "\n";
            for (int i = 1; i < n + 1; ++i) {
                if (i % 4 == 2 || i % 4 == 3) {
                    cout << i << " ";
                }
            }
        } else {
            cout << n / 2 + 1 << "\n";
            cout << 1 << " " << 2;
            for (int i = 4; i < n + 1; ++i) {
                if (i % 4 == 0 || i % 4 == 3) {
                    cout << " " << i;
                }
            }
            cout << "\n" << n / 2 << "\n";
            cout << 3;
            for (int i = 4; i < n + 1; ++i) {
                if (i % 4 == 1 || i % 4 == 2) {
                    cout << " " << i;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
