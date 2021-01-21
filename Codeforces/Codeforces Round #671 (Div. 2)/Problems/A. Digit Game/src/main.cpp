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
        string a;
        cin >> a;
        if (n % 2 == 1) {
            bool sol = false;
            int i = 1;
            for (char j : a) {
                if (i++ % 2 == 1 && (j - '0') % 2 == 1) {
                    cout << 1 << "\n";
                    sol = true;
                    break;
                }
            }
            if (!sol) {
                cout << 2 << "\n";
            }
        } else {
            bool sol = false;
            int i = 1;
            for (char j : a) {
                if (i++ % 2 == 0 && (j - '0') % 2 == 0) {
                    cout << 2 << "\n";
                    sol = true;
                    break;
                }
            }
            if (!sol) {
                cout << 1 << "\n";
            }
        }
    }
    return 0;
}
