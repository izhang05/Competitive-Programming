/*
ID: izhang01
TASK: baseball
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("baseball.in", "r", stdin);
    freopen("baseball.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int xy = cows[j] - cows[i], yz = cows[k] - cows[j];
                if ((yz >= xy) && (yz <= xy * 2)) {
                    ++sol;
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
