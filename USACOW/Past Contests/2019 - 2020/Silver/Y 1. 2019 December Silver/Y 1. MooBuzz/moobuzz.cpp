/*
ID: izhang01
TASK: moobuzz
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    int n;
    cin >> n;
    long long sol = 0;
    sol += ((n - 1) / 8) * 15;
    map<int, int> values{{1, 1},
                         {2, 2},
                         {3, 4},
                         {4, 7},
                         {5, 8},
                         {6, 11},
                         {7, 13},
                         {0, 14}
    };
    sol += values[n % 8];
    cout << sol << "\n";
    return 0;
}
