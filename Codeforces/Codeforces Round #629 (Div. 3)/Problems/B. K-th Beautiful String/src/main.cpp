#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k, --k;
        int p1, p2;
        for (int i = n - 2; i >= 0; --i) {
            if (k < n - 1 - i) {
                p1 = i;
                p2 = n - 1 - k;
                break;
            }
            k -= n - 1 - i;
        }
        for (int i = 0; i < n; ++i) {
            if (i == p1 || i == p2) {
                cout << 'b';
            } else {
                cout << 'a';
            }
        }
        cout << "\n";

    }
    return 0;
}
