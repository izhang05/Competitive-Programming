#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (n == 1 || n == 2) {
            cout << 1 << "\n";
        } else {
            cout << (n - 2 + x - 1) / x + 1 << "\n";
        }
    }
    return 0;
}
