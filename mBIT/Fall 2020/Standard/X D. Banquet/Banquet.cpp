#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("3.in", "r", stdin);
#endif
}


int main() {
    setIO();
    int n;
    cin >> n;
    int sol = 0, a, cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ++cur;
        cur -= a;
        sol += abs(cur);
    }
    cout << sol << "\n";
    return 0;
}

