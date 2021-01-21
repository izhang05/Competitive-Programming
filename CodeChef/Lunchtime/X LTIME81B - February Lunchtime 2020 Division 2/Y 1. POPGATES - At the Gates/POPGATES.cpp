#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int t, n, k, flips, solution;
    cin >> t;
    while (t--) {
        flips = 0;
        cin >> n >> k;
        vector<int> coins(n);
        char coin;
        for (int i = 0; i < n; ++i) {
            cin >> coin;
            coins[i] = coin == 'H';
        }
        for (int i = n - 1; i > n - k - 1; --i) {
            if ((coins[i] + flips) % 2 == 1) {
                ++flips;
            }
        }
        solution = 0;
        for (int i = 0; i < n - k; ++i) {
            if ((coins[i] + flips) % 2 == 1) {
                ++solution;
            }
        }
        cout << solution << "\n";
    }
    return 0;
}
