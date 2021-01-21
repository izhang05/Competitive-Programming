#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int low = 0;
        int high = min(a / 2, b), mid, sol = 0;
        cout << high << "\n";
        while (low <= high) {
            mid = (low + high) / 2;
            int l = low + min(a - 2 * low, (b - low) / 2);
            int h = high + min(a - 2 * high, (b - high) / 2);
            if (l < h) {
                ++low;
            } else {
                --high;
            }
            sol = max(l, h);
//            cout << low << " " << high << "\n";
        }
        cout << sol << "\n";
    }
    return 0;
}
