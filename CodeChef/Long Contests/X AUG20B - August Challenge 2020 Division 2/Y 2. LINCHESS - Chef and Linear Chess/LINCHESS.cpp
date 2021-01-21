#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("1.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int p;
        pair<int, int> sol = {1e9, -1};
        for (int i = 0; i < n; ++i) {
            cin >> p;
            if (abs(p - k) % p == 0) {
                if (abs(p - k) / p < sol.first) {
                    sol.first = abs(p - k) / p;
                    sol.second = p;
                }
            }
        }
        cout << sol.second << "\n";
    }
    return 0;
}
