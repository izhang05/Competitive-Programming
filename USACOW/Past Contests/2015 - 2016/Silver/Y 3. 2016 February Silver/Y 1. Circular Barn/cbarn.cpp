/*
ID: izhang01
TASK: cbarn
LANG: C++11
*/
#include <bits/stdc++.h>


using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n;
    int c[n], cow;
    for (int i = 0; i < n; ++i) {
        cin >> cow;
        c[i] = cow;
    }
    int num_cows = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        num_cows += c[i] - 1;
        if (num_cows < 0) {
            num_cows = 0;
            start = i + 1;
        }
    }
    multiset<int> waiting;
    long long sol = 0;
    for (int i = 0; i < c[start] - 1; ++i) {
        waiting.insert(0);
    }
    for (int i = 1; i < n; ++i) {
//        cout << i << " " << c[(i + start) % n] << " " << sol << "\n";
        for (int j = 0; j < c[(i + start) % n]; ++j) {
            waiting.insert(i);
        }
        auto it = waiting.begin();
        sol += pow(i - *it, 2);
//        cout << i << "\n";
//        for (int j : waiting) {
//            cout << j << " ";
//        }
//        cout << "\n";
        waiting.erase(it);
    }
    if (!waiting.empty()) {
        sol += pow(n - *waiting.begin(), 2);
    }
    cout << sol << "\n";
    return 0;
}
