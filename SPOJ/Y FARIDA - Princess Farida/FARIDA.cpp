// https://www.spoj.com/problems/FARIDA/
// Date:	2013-05-13
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("solution.out", "w", stdout);
//    freopen("1.in", "r", stdin);
    int t, n;
    cin >> t;
    vector<int> monsters;
    vector<long long> maximum;
    long long solution;
    for (int _ = 1; _ < t + 1; ++_) {
        cin >> n;
        monsters.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> monsters[i];
        }
        if (n == 0) {
            solution = 0;
        } else if (n == 1) {
            solution = monsters[0];
        } else {
            maximum.resize(n);
            fill(maximum.begin(), maximum.end(), numeric_limits<long long>::max());
            maximum[0] = monsters[0];
            maximum[1] = max(monsters[0], monsters[1]);
            for (int i = 2; i < n; ++i) {
                maximum[i] = max(maximum[i - 1], maximum[i - 2] + monsters[i]);
            }
            solution = maximum[n - 1];
        }
        cout << "Case " << _ << ": " << solution << "\n";
    }
    return 0;
}
