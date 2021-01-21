/*
ID: izhang01
TASK: highcard
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n;
    cin >> n;
    set<int> e;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        e.insert(a);
    }
    set<int> b;
    for (int i = 1; i < 2 * n + 1; ++i) {
        if (!e.count(i)) {
            b.insert(i);
        }
    }
    auto b_it = b.begin();
    auto e_it = e.begin();
    int count = 0;
    int sol = 0;
    while (count < n) {
        if (*b_it > *e_it) {
            ++sol;
            ++e_it;
        }
        ++count;
        ++b_it;
    }
    cout << sol << "\n";
    return 0;
}
