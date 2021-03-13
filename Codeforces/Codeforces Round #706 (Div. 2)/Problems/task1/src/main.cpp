#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool sol = true;
        if (k * 2 == n) {
            sol = false;
        }
        for (int i = 0; i < n && i < k; ++i) {
            if (s[i] != s[n - 1 - i]) {
                sol = false;
                break;
            }
        }
        cout << (sol ? "YES" : "NO") << "\n";
    }
    return 0;
}
