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
        long long n, k;
        cin >> n >> k;
        long long sol = 0;
        while (n) {
            if (n % k == 0) {
                n /= k;
                ++sol;
            } else {
                sol += n % k;
                n -= n % k;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
