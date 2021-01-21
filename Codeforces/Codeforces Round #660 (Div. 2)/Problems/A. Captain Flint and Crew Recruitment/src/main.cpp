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
        if (n == 36) {
            cout << "YES" << "\n";
            cout << "5 6 10 15" << "\n";
        } else if (n == 44) {
            cout << "YES" << "\n";
            cout << "6 7 10 21" << "\n";
        } else if (n == 40) {
            cout << "YES" << "\n";
            cout << "6 10 15 9" << "\n";
        } else if (n < 31) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            cout << 6 << " " << 10 << " " << 14 << " ";
            cout << n - 30 << "\n";
        }
    }
    return 0;
}
