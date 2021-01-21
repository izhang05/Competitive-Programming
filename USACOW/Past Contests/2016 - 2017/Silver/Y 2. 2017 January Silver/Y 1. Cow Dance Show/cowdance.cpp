/*
ID: izhang01
TASK: cowdance
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> d;
int n, t;

bool possible(int k) {
    multiset<int> cows;
    for (int i = 0; i < k; ++i) {
        cows.insert(d[i]);
    }
    for (int i = k; i < n; ++i) {
        auto it = cows.begin();
        int first = *it;
//        cout << first << "\n";
        cows.erase(it);
        cows.insert(d[i] + first);
    }
    auto it = cows.end();
    --it;
    return *it <= t;
}


int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> t;
    d.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    int low = 1, high = n, mid, sol;
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
