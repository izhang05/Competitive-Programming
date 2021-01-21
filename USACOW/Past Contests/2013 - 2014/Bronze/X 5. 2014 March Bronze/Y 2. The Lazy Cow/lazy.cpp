/*
ID: izhang01
TASK: lazy
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6;
int grass[MAXN];

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int g, x;
    for (int i = 0; i < n; ++i) {
        cin >> g >> x;
        grass[x] = g;
    }
    if (2 * k + 1 > MAXN) {
        int sol = 0;
        for (int i : grass) {
            sol += i;
        }
        cout << sol << "\n";
    } else {
        int current = 0;
        for (int i = 0; i < 2 * k + 1; ++i) {
            current += grass[i];
        }
        int maximum = current;
        for (int i = 1; i + 2 * k + 1 < MAXN; ++i) {
            current -= grass[i - 1];
            current += grass[i + 2 * k];
            maximum = max(maximum, current);
        }
        cout << maximum << "\n";
    }
    return 0;
}
