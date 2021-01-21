#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y, n;
        cin >> x >> y >> n;
        if ((n / x) * x + y <= n) {
            cout << (n / x) * x + y << "\n";
        } else {
            cout << (n / x) * x + y - x << "\n";
        }
    }
    return 0;
}
