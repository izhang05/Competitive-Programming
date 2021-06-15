#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        long long sol = 0;
        while (l != 0 || r != 0) {
            sol += r - l;
            l /= 10, r /= 10;
        }
        cout << sol << "\n";
    }
    return 0;
}
