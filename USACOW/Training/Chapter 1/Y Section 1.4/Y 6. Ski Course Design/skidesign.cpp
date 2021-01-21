/*
ID: izhang01
TASK: skidesign
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> elevations(n);
    for (int i = 0; i < n; ++i) {
        cin >> elevations[i];
    }
    sort(elevations.begin(), elevations.end());
    int solution = 1E7;
    for (int i = elevations[0]; i < elevations[n - 1] - 16; ++i) {
        int current_price = 0;
        for (int j : elevations) {
            if (j < i) {
                current_price += pow(i - j, 2);
            } else if (j > i + 17) {
                current_price += pow(j - (i + 17), 2);
            }
        }
        solution = min(solution, current_price);
    }
    cout << solution << "\n";
    return 0;
}
