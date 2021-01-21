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
        string s;
        cin >> s;
        bool pos = true;
        for (int i = k; i < n; ++i) {
            if (s[i] != '?') {
                if (s[i % k] == '?') {
                    s[i % k] = s[i];
                } else if (s[i] != s[i % k]) {
                    pos = false;
                    break;
                }
            }
        }
        int z = 0, o = 0;
        for (int i = 0; i < k; ++i) {
            if (s[i] == '1') {
                ++o;
            } else if (s[i] == '0'){
                ++z;
            }
        }
        if (z > k / 2 || o > k / 2) {
            pos = false;
        }
        if (pos) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
