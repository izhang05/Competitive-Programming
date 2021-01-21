#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        long long sol = 0;
        if (a - x >= n) {
            sol = (a - n) * y;
        } else {
            sol = x * (b - (n - (a - x)));
        }
        if (b - x >= n) {
            sol = max(sol, (b - n) * x);
        } else {
            sol = max(sol, a - (n - (b - x)));
        }
        cout << sol << "\n";
    }
    return 0;
}
