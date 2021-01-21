/*
ID: izhang01
TASK: clumsy
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("clumsy.in", "r", stdin);
    freopen("clumsy.out", "w", stdout);
    string p;
    cin >> p;
    int sol = 0, left = 0, right = 0;
    for (char i : p) {
        if (i == '(') {
            ++left;
        } else {
            if (right >= left) {
                ++sol;
                ++left;
            } else {
                ++right;
            }
        }
    }
    sol += (left - right) / 2;
    cout << sol << "\n";
    return 0;
}
