#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    bool flag;
    cin >> t;
    int parity, height;
    while (t--) {
        flag = true;
        cin >> n;
        cin >> parity;
        parity %= 2;
        for (int i = 1; i < n; ++i) {
            cin >> height;
            if (height % 2 != parity) {
                if (flag) {
                    cout << "NO" << "\n";
                }
                flag = false;
            }
        }
        if (flag) {
            cout << "YES" << "\n";
        }
    }
    return 0;
}
