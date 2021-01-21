/*
ID: izhang01
TASK: poker
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
}


int main() {
    setIO();
    int n, pre, a;
    cin >> n >> pre;
    long long sol = pre;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a;
        sol += max(0, a - pre);
        pre = a;
    }
    cout << sol << "\n";
    return 0;
}
