/*
ID: izhang01
TASK: lemonade
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    sort(w.begin(), w.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        if (w[i] < i) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}
