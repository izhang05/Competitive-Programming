#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        if (n == 1) {
            cout << -1 << "\n";
            continue;
        }
        if ((2 * (n - 1)) % 3 != 0) {
            for (int i = 0; i < n - 1; ++i) {
                s.append("2");
            }
            s.append("3");
            cout << s << "\n";
            continue;
        } else {
            for (int i = 0; i < n - 2; ++i) {
                s.append("2");
            }
            s.append("4");
            s.append("3");
            cout << s << "\n";
            continue;
        }
    }
    return 0;
}
