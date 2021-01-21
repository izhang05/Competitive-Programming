/*
ID: izhang01
TASK: breedflip
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int solution = 0;
    bool different = a[0] != b[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] == b[i]) {
            if (different) {
                ++solution;
            }
            different = false;
        } else {
            different = true;
        }
    }
    if (different) {
        ++solution;
    }
    cout << solution << "\n";
    return 0;
}
