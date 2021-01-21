#include <iostream>
#include <vector>

using namespace std;

int main() {
//    freopen("solution.out", "w", stdout);
//    freopen("1.in", "r", stdin);
    int t, n, previous_house, max_inf, min_inf, current;
    cin >> t;
    while (t--) {
        cin >> n;
        max_inf = 1, min_inf = n;
        cin >> previous_house;
        int j;
        current = 1;
        for (int i = 1; i < n; ++i) {
            cin >> j;
            if (j - previous_house <= 2) {
                ++current;
                previous_house = j;
            } else {
//                cout << i - previous_house << "\n";
                max_inf = max(max_inf, current);
                min_inf = min(min_inf, current);
                current = 1;
                previous_house = j;
            }
        }
        max_inf = max(max_inf, current);
        min_inf = min(min_inf, current);
        cout << min_inf << " " << max_inf << "\n";
    }
    return 0;
}