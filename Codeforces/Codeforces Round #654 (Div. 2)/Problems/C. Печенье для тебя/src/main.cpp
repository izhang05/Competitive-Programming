#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        if (a + b < n + m) {
            cout << "No" << "\n";
        } else {
            if (min(a, b) < m) {
                cout << "No" << "\n";
            } else {
                if (a <= b) {
                    a -= m;
                } else {
                    b -= m;
                }
                if (a + b < n) {
                    cout << "No" << "\n";
                } else {
                    cout << "Yes" << "\n";
                }
            }
        }
    }
    return 0;
}
