/*
ID: izhang01
TASK: angry
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> x;


bool possible(int r) {
    int used = 1;
    int max = x[0] + 2 * r;
    for (int i : x) {
        if (i > max) {
            ++used;
            if (used > k) {
                return false;
            }
            max = i + 2 * r;
        }
    }
    return true;
}


int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n >> k;
    x.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int low = 1;
    int high = 1e9, mid, sol;
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
