#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if ((n % 2 == 1) && (k % 2 == 0)) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";

        }
    }
    return 0;
}
