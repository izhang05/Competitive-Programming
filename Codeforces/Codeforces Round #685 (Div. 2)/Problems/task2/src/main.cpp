#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int l, r;
        for (int i = 0; i < q; ++i) {
            cin >> l >> r;
            --l, --r;
            bool sol = false;
            for (int j = 0; j < l; ++j) {
                if (s[j] == s[l]) {
                    sol = true;
                    break;
                }
            }
            for (int j = r + 1; j < n; ++j) {
                if (s[j] == s[r]) {
                    sol = true;
                    break;
                }
            }
            cout << (sol ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
