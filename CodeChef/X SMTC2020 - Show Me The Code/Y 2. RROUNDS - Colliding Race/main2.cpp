#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t, r, x, a, b, solution;
    cin >> t;
    while (t--) {
        solution = 0;
        cin >> x >> r >> a >> b;
        int maxa_b = max(a, b);
        int mina_b = min(a, b);
        a = maxa_b;
        b = mina_b;

        int previous_lap = 0;

        for (int i = 1; i < x; ++i) {
            float current_lap = float(i + 1) * (float(b) / float(a));
//            cout << i << "\n";
//            cout << previous_lap << "\n";
//            cout << current_lap << "\n";
//            cout << "\n";
            if (current_lap - previous_lap < 1 ) {
//                cout << i << "\n";
//                cout << previous_lap << "\n";
//                cout << current_lap << "\n";
//                cout << "\n";
                ++solution;
            }
            previous_lap = floor(current_lap);
        }
        cout << solution << "\n";
    }
    return 0;
}