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
        string state;
        cin >> state;
        int last = 0;
        int sol = 0;
        if (!(state[0] - '0')) {
            ++sol;
        }
        for (int i = 1; i < n; ++i) {
            if (!(state[i] - '0')) {
                if (last == -1 || i - last > k) {
                    ++sol;
                    last = i;
                }
            } else {
                if (i - last <= k) {
                    --sol;
                }
                last = i;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
