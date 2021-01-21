
/*
ID: izhang01
TASK: ariprog
LANG: C++
*/


#include <bits/stdc++.h>

using namespace std;

bool is_bisquare[2 * 250 * 250];

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    const int max = 2 * m * m;
    for (int i = 0; i < m + 1; ++i) {
        for (int j = i; j < m + 1; ++j) {
            is_bisquare[i * i + j * j] = true;
        }
    }
    bool found = false, sol;
    for (int b = 1; b * (n - 1) <= max; ++b) {
        for (int a = 0; a + b * (n - 1) <= max; ++a) {
            sol = true;
            for (int i = 0; i < n; ++i) {
                if (!is_bisquare[a + b * i]) {
                    sol = false;
                    break;
                }
            }
            if (sol) {
                cout << a << " " << b << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "NONE" << "\n";
    }
    return 0;
}