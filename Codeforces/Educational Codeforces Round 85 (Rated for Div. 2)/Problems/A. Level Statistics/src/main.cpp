#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        bool possible = true;
        int n, current_p, current_c, p, c;
        cin >> n;
        cin >> current_p >> current_c;
        if (current_c > current_p) {
            possible = false;
        }
        --n;
        while (n--) {
            cin >> p >> c;
            if (p < current_p || c < current_c || (c - current_c) > (p - current_p)) {
                current_p = p;
                current_c = c;
                possible = false;
            }
        }

        if (possible) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }

    }
    return 0;
}