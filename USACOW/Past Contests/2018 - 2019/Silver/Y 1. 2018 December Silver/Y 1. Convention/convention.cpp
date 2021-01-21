/*
ID: izhang01
TASK: convention
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> t;
int n, m, c;


bool possible(int wait) {
    int start = t[0], buses = 1, max = start + wait, cows_in_bus = 0;
    for (int i : t) {
        ++cows_in_bus;
        if (i > max || cows_in_bus > c) {
            start = i;
            max = start + wait;
            ++buses;
            if (buses > m) {
                return false;
            }
            cows_in_bus = 1;
        }
    }
    return true;
}


int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    int low = 0, high = 1e9, mid, sol;
    while (low <= high) {
        mid = (low + high) / 2;
        if (possible(mid)) {
            sol = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}
