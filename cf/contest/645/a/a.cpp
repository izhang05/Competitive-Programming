#include <bits/stdc++.h>

using namespace std;

int main() {
    string start, b1, b2, goal, e1, e2;
    // read in the input
    cin >> b1 >> b2 >> e1 >> e2;

    // turn the 2d matrix into a 1d string
    // AB
    // CD
    // turns into
    // ABDC
    start = b1 + b2[1] + b2[0];
    goal = e1 + e2[1] + e2[0];

    // try each possible swap of 'X'
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 4; ++j) {
            // look for 'X' in start
            if (start[j] == 'X') {
                // swap the 'X' with the next element
                swap(start[j], start[(j + 1) % 4]);
                break;
            }
        }
        // the configurations are the same
        if (start == goal) {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}
