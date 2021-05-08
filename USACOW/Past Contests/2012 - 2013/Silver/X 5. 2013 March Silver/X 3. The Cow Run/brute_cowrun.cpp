/*
ID: izhang01
TASK: brute_cowrun
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("cowrun.in", "r", stdin);
//    freopen("cowrun.out", "w", stdout);
//    freopen("cowrun.out", "w", stderr);
}
//#define DEBUG

int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n), order(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        order[i] = i;
    }
    long long sol = 1e18;
    do {
        long long time = 0, cost = 0;
        int last = 0;
        for (auto i : order) {
            time += abs(a[i] - last);
            last = a[i];
            cost += time;
        }
        sol = min(sol, cost);
    } while (next_permutation(order.begin(), order.end()));
    cout << sol << "\n";

    return 0;
}
