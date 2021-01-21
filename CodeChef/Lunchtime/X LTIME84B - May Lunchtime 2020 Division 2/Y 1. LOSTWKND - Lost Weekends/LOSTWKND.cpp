#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        long long a, total = 0;
        for (int i = 0; i < 5; ++i) {
            cin >> a;
            total += a;
        }
        int p;
        cin >> p;
        if (total * p <= 120) {
            cout << "No" << "\n";
        } else {
            cout << "Yes" << "\n";
        }
    }
    return 0;
}
