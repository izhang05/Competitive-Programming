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
        int sol = 0;
        bool pos = true;
        while (true) {
            if (n % 6 == 0) {
                ++sol;
                n /= 6;
            } else if (n % 3 == 0) {
                sol += 2;
                n /= 3;
            } else if (n == 1) {
                break;
            } else {
                pos = false;
                break;
            }
        }
        if (pos) {
            cout << sol << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
