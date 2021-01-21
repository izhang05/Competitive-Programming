/*
ID: (izhang01
TASK: socdist1
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int n;
    cin >> n;
    string stalls;
    cin >> stalls;
    char previous_stall = stalls[0];
    int largest = 0, second_largest = 0, current_distance = 1, beginning_distance = 1;
    bool cow = previous_stall == '1';
    for (int i = 1; i < n; ++i) {
        if (cow) {
            if (stalls[i] == '0') {
                ++current_distance;
            } else {
                if (current_distance > largest) {
                    second_largest = largest;
                    largest = current_distance;
                } else if (current_distance > second_largest) {
                    second_largest = current_distance;
                }
                current_distance = 1;
            }
        } else {
            if (stalls[i] == '1') {
                cow = true;
                if (current_distance > largest) {
                    second_largest = largest;
                    largest = current_distance;
                } else if (current_distance > second_largest) {
                    second_largest = current_distance;
                }
                current_distance = 1;
            } else {
                ++current_distance;
                ++beginning_distance;
            }
        }
    }
    if (current_distance - 1 > largest) {
        second_largest = largest;
        largest = current_distance - 1;
    } else if (current_distance - 1 > second_largest) {
        second_largest = current_distance - 1;
    }
//    cout << largest << "\n";
//    cout << second_largest << "\n";
    if (!cow) {
        cout << n - 1 << "\n";
    } else {
        cout << max({1, largest / 3, second_largest / 2, min(current_distance - 1, largest / 2),
                     min(beginning_distance, largest / 2)}) << "\n";
    }
    return 0;
}
