#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        int sol = 0;
        long long used = 0;
        for (long long i = 2; i < (long long) 1e18; i*= 2) {
            used += ((i - 1) * i) / 2;
            if (used <= x) {
                ++sol;
            } else {
                break;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
