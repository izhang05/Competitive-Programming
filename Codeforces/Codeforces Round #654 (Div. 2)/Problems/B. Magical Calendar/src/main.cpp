#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long n, r;
        cin >> n >> r;
//        cout << min(n - 1, r) << "\n";
        long long maxim = min(n - 1, r);
        long long sol = (maxim * (maxim + 1)) / 2;
        if (n <= r) {
            ++sol;
        }
        cout << sol << "\n";
    }
    return 0;
}
