#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        pair<int, int> a;
        for (int i = 0; i < n; ++i) {
            cin >> a.first;
        }
        a.second = a.first;
        int sol = 0;
        while (x < a.first) {
            ++sol;
            a.first -= x;
            x *= 2;
            a.first = min(a.first * 2, a.second);
        }
        cout << sol + n << "\n";
    }
    return 0;
}